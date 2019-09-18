#include "HumanSpawner.h"
#include "Macro.h"
#include "Utility.h"
#include "Floor.h"
#include "KeyboardManager.h"
#include "ConsoleMap.h"

void HumanSpawner::Initialize(int spawnDelay, int maxWaitingCnt,
							  std::vector<Floor*>* spawnFloors, ConsoleMap* buffer) {
	m_maximumHumanSpawnDelay = spawnDelay;
	m_currentHumanSpawnDelay = m_maximumHumanSpawnDelay;
	m_maxSpawnCount = maxWaitingCnt;
	m_pSpawnFloors = spawnFloors;
	m_pConsoleMap = buffer;

	InitSpawnCursor(m_pSpawnFloors->size());
}

void HumanSpawner::Update() {
	InputKey();
	SpawnWithRandomDealy();
}

void HumanSpawner::Render() {
	RenderCursor();
}

void HumanSpawner::Release() {
	SAFE_DELETE_ARRAY(m_pCursorBuffers);
}

void HumanSpawner::InitSpawnCursor(size_t cnt) {
	m_pCursorBuffers = new std::string[cnt];
}

void HumanSpawner::InputKey() {
	if (GET_SINGLE(KeyboardManager)->GetKeyPress(KEY_CODE::KC_UP)) {
		if (m_cursorIndex > 1)
			m_cursorIndex--;
	} else if (GET_SINGLE(KeyboardManager)->GetKeyPress(KEY_CODE::KC_DOWN)) {
		if (m_cursorIndex < m_pSpawnFloors->size())
			m_cursorIndex++;
	} else if (GET_SINGLE(KeyboardManager)->GetKeyDown(KEY_CODE::KC_Z)) {
		SpawnHumanImmediate();
	}
}

void HumanSpawner::SpawnWithRandomDealy() {
	if (m_currentHumanSpawnDelay <= 0) {
		
		std::vector<Floor*>::iterator iter = m_pSpawnFloors->begin();
		iter += Utility::RandomRange(0, (int)m_pSpawnFloors->size() - 1);;
		if ((*iter)->GetWaitingCount() < m_maxSpawnCount * 3)
			(*iter)->PushHuman(Utility::RandomRange(0, (int)m_pSpawnFloors->size() - 1));
		m_currentHumanSpawnDelay = m_maximumHumanSpawnDelay;
	}
	m_currentHumanSpawnDelay--;
}

void HumanSpawner::SpawnHumanImmediate() {
	std::vector<Floor*>::iterator iter = m_pSpawnFloors->begin();
	iter += m_cursorIndex - 1;
	if ((*iter)->GetWaitingCount() < m_maxSpawnCount * 3)
		(*iter)->PushHuman(Utility::RandomRange(0, (int)m_pSpawnFloors->size() - 1));
}

void HumanSpawner::RenderCursor() {
	int skipBufferSize = 3;
	for (int y = 1; y < m_pSpawnFloors->size() + 1; ++y) {
		*(m_pConsoleMap->GetBuffer(m_maxSpawnCount * 3 + skipBufferSize, y)) = "  ";

		if (y == m_cursorIndex)
			*(m_pConsoleMap->GetBuffer(m_maxSpawnCount * 3 + skipBufferSize, y)) = "¢·";
	}
}

HumanSpawner::HumanSpawner() : m_maximumHumanSpawnDelay(0), m_currentHumanSpawnDelay(0), m_cursorIndex(1) { }

HumanSpawner::~HumanSpawner() { }
