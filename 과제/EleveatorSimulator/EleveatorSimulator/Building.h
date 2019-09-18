#ifndef _BUILDING_H_
#define _BUILDING_H_

#include <vector>

#include "Floor.h"
#include "Elevator.h"
#include "Human.h"
#include "HumanSpawner.h"

class ConsoleMap;
class Building {
	ConsoleMap* m_pConsoleMap;
	HumanSpawner* m_pHumanSpanwer;

	int m_floorCount;
	std::vector<Floor*> m_floors;
	int m_elevatorCount;
	std::vector<Elevator*> m_elevators;

public:
	void Initialize(int floorCnt, int elevatorCnt, ConsoleMap* buffer);
	void Update();
	void Render();
	void Release();

private:
	void InitFloor(int cnt);
	void InitElevator(int cnt);
	void InitSpawner();
	void UpdateMember();
	void RenderMember();
	void RenderBuilding();
	void RenderElevatorInfo();

public:
	Building();
	virtual ~Building();
};

#endif