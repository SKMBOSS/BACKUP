#include "Elevator.h"
#include "Building.h"
#include "ConsoleMap.h"
#include "LogManager.h"

const int Elevator::LIMITED_WEIGHT = 1000;

void Elevator::Initialize(std::vector<Floor*>& floors, int moveDelay, 
						  Point pos, ConsoleMap* buffer) {
	m_pConsoleMap = buffer;
	m_mode = MOVE_MODE::EL_MOVE_STOP;
	m_position = pos;
	m_Humans.reserve(20);

	m_pBuildingFloors = &floors;
	m_pointingFloor = m_pBuildingFloors->rbegin();

	m_maximumMoveDelay = moveDelay;
	m_currentMoveDealy = m_maximumMoveDelay;
}

void Elevator::Update() {
	Move();
	PutHuman();
}

void Elevator::Render() {
	*(m_pConsoleMap->GetBuffer(m_position.x, m_position.y)) = "╒г";
}

void Elevator::Release() {

}

void Elevator::Move() {
	if (m_currentMoveDealy <= 0) {
		switch (m_mode) {
			case MOVE_MODE::EL_MOVE_STOP:
				QuitHuman();
				FindCurrentHumanInFloors();	
				break;
			case MOVE_MODE::EL_MOVE_UP:
				if (m_pointingFloor == m_pBuildingFloors->rend() - 1) {
					m_mode = MOVE_MODE::EL_MOVE_STOP;
					return;
				}
				QuitHuman();

				m_pointingFloor++;
				m_position.y--;
				break;
			case MOVE_MODE::EL_MOVE_DOWN:
				if (m_pointingFloor == m_pBuildingFloors->rbegin()) {
					m_mode = MOVE_MODE::EL_MOVE_STOP;
					return;
				}
				QuitHuman();

				m_pointingFloor--;
				m_position.y++;
				break;
			default:
				break;
		}

		m_currentMoveDealy = m_maximumMoveDelay;
	}
	m_currentMoveDealy--;
	
}

void Elevator::PutHuman() {
	if (LIMITED_WEIGHT - 99 < m_totalWeight) // юс╫ц
		return;

	bool isUp = false;
	if (m_mode == MOVE_MODE::EL_MOVE_UP)
		isUp = true;
	else if (m_mode == MOVE_MODE::EL_MOVE_DOWN)
		isUp = false;

	auto human = (*m_pointingFloor)->PopHuman((*m_pointingFloor)->GetFloorCount(), isUp);
	if (human != nullptr) {
		human->SetPosition(Point(0, 0));
		m_pHumansInElevator.push_back(human);
		
		m_totalWeight += human->GetWeight();	
	}
}

void Elevator::FindCurrentHumanInFloors() {
	if (m_pHumansInElevator.size() <= 0) {
		bool checkUp = rand() % 2;
		if (checkUp) {
			for (auto iter = m_pointingFloor.base() - 1; iter != m_pBuildingFloors->end(); ++iter) {
				if ((*iter)->GetElevatorButtonState()) {
					m_mode = MOVE_MODE::EL_MOVE_DOWN;
					break;
				}
			}
		} else {
			for (auto iter = m_pointingFloor; 
				 iter != m_pBuildingFloors->rend(); ++iter) {
				if ((*iter)->GetElevatorButtonState()) {
					m_mode = MOVE_MODE::EL_MOVE_UP;
					break;
				}
			}
		}
	} else {
		int targetFloor = m_pHumansInElevator.front()->GetTargetFloorCount();
		int currentFloor = (*m_pointingFloor)->GetFloorCount();
		m_mode = targetFloor >= currentFloor ? MOVE_MODE::EL_MOVE_DOWN : MOVE_MODE::EL_MOVE_UP;
	}
}

void Elevator::QuitHuman() {
	if (m_pHumansInElevator.size() <= 0)
		m_mode = MOVE_MODE::EL_MOVE_STOP;

	for (auto iter = m_pHumansInElevator.begin();
		 iter != m_pHumansInElevator.end();) {
		if ((*iter)->GetTargetFloorCount() == (*m_pointingFloor)->GetFloorCount()) {
			auto target = *iter;
			m_totalWeight -= target->GetWeight();
			target->Release();
			iter = m_pHumansInElevator.erase(iter);
			SAFE_DELETE(target);

			if (m_pHumansInElevator.size() <= 0)
				m_mode = MOVE_MODE::EL_MOVE_STOP;

		} else {
			++iter;
		}
	}
}

Elevator::Elevator() : m_totalWeight(0) { }

Elevator::~Elevator() { }
