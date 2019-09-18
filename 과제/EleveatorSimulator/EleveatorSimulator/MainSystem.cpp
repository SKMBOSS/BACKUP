#include <time.h>
#include <stdlib.h>

#include "LogManager.h"
#include "Macro.h"
#include "MainSystem.h"
#include "KeyboardManager.h"

void MainSystem::Initialize() {
	srand((unsigned)time(NULL));
	//std::locale::global(std::locale("kor"));
	int floorCnt = 20;
	int elevatorCnt = 6;

	InitConsoleMap((int)((floorCnt * 2) + elevatorCnt), floorCnt + 3);
	InitObject(floorCnt, elevatorCnt, m_pConsoleMap);

	GET_SINGLE(LogManager)->SetMaximum(elevatorCnt);
	GET_SINGLE(LogManager)->SetTitle("<Z> Put Human / <X> Exit / <¢Õ> Move");

	GET_SINGLE(KeyboardManager)->Initialize();
}

void MainSystem::Update() {
	m_pBuilding->Update();
	m_pConsoleMap->Update();
	GET_SINGLE(KeyboardManager)->Update();
	InputKey();
}

void MainSystem::Render() {
	m_pBuilding->Render();
	m_pConsoleMap->Render();
	GET_SINGLE(LogManager)->Render();
	system("cls");
}

void MainSystem::Release() {
	SAFE_RELEASE(m_pBuilding);
	SAFE_RELEASE(m_pConsoleMap);
	GET_SINGLE(LogManager)->Release();
	GET_SINGLE(KeyboardManager)->Release();
}

void MainSystem::InputKey() {
	if (GET_SINGLE(KeyboardManager)->GetKeyDown(KEY_CODE::KC_X))
		m_isActive = false;
}

void MainSystem::InitConsoleMap(int width, int height) {
	m_pConsoleMap = new ConsoleMap();
	m_pConsoleMap->Initialize(Size(width, height));
}

void MainSystem::InitObject(int floorCnt, int elevatorCnt, ConsoleMap* buffers) {
	m_pBuilding = new Building();
	m_pBuilding->Initialize(floorCnt, elevatorCnt, m_pConsoleMap);
}

MainSystem::MainSystem() : m_isActive(true) { }

MainSystem::~MainSystem() { }
