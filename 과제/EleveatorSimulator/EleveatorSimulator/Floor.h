#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <deque>
#include "Human.h"

class ConsoleMap;
class Floor {
private:
	ConsoleMap* m_pConsoleMap;
	std::deque<Human*> m_waitingHumans;
	int m_floorCount;
	bool m_isPressElevatorButton;

public:
	void Initialize(int floorCnt, ConsoleMap* buffer);
	void Update();
	void Render();
	void Release();

	void PushHuman(int targetFloorCount);
	Human* PopHuman(int elevatorFloor, bool isUp);

	const inline size_t GetWaitingCount() { return m_waitingHumans.size(); }
	const inline int  GetFloorCount()     { return m_floorCount; }
	const inline bool GetElevatorButtonState() { return m_isPressElevatorButton; }

private:
	void UpdateHumans();
	void SortWatingHumans();
	void ControlElevatorButton();

public:
	Floor();
	virtual ~Floor();
};

#endif

