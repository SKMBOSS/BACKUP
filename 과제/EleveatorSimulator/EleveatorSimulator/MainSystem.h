#ifndef _MAINSYSTEM_H_
#define _MAINSYSTEM_H_

#include "Building.h"
#include "ConsoleMap.h"

class MainSystem {
private:
	Building* m_pBuilding;
	ConsoleMap* m_pConsoleMap;
	bool m_isActive;

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

	const inline bool IsActive() { return m_isActive; }

private:
	void InputKey();
	void InitConsoleMap(int width, int height);
	void InitObject(int floorCnt, int elevatorCnt, ConsoleMap* buffers);

public:
	MainSystem();
	~MainSystem();
};

#endif