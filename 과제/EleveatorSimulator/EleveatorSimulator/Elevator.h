#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_

#include <vector>

#include "Human.h"
#include "Floor.h"
#include "Content.h"

class ConsoleMap;
class Elevator {
private:
	enum MOVE_MODE { EL_MOVE_NULL = -1, EL_MOVE_STOP, EL_MOVE_UP, EL_MOVE_DOWN };

public:
	const static int LIMITED_WEIGHT;

private:
	MOVE_MODE m_mode;
	ConsoleMap* m_pConsoleMap;
	Point m_position;

	std::vector<Human*> m_Humans;
	int m_totalWeight;

	std::vector<Floor*>* m_pBuildingFloors;
	std::vector<Floor*>::reverse_iterator m_pointingFloor;
	std::vector<Human*> m_pHumansInElevator;

	int m_maximumMoveDelay;
	int m_currentMoveDealy;

public:
	void Initialize(std::vector<Floor*>& floors, int moveDelay, 
					Point pos, ConsoleMap* buffer);
	void Update();
	void Render();
	void Release();

	const inline Point* GetPoint() const { return &m_position; }
	const inline std::vector<Human*>* GetHumans() { return &m_pHumansInElevator; }
	const inline int GetWeight() { return m_totalWeight; }

private:
	void Move();
	void PutHuman();
	void FindCurrentHumanInFloors();
	void QuitHuman();

public:
	Elevator();
	virtual ~Elevator();
};

#endif