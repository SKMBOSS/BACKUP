#ifndef  _HUMANSPAWNER_H_
#define _HUMANSPANWER_H_

#include <vector>

class Floor;
class ConsoleMap;
class HumanSpawner {
private:
	ConsoleMap* m_pConsoleMap;

	int m_maximumHumanSpawnDelay;
	int m_currentHumanSpawnDelay;
	int m_maxSpawnCount;
	std::vector<Floor*>* m_pSpawnFloors;

	std::string* m_pCursorBuffers;
	int m_cursorIndex;

public:
	void Initialize(int spawnDelay, int maxWaitingCnt, 
					std::vector<Floor*>* spawnFloors, ConsoleMap* buffer);
	void Update();
	void Render();
	void Release();

private:
	void InitSpawnCursor(size_t cnt);

	void InputKey();
	void SpawnWithRandomDealy();
	void SpawnHumanImmediate();
	void RenderCursor();

public:
	HumanSpawner();
	virtual ~HumanSpawner();
};

#endif


