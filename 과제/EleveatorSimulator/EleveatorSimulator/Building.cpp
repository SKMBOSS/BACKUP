#include <string>
#include <functional>

#include "Building.h"
#include "Macro.h"
#include "ConsoleMap.h"
#include "LogManager.h"
#include "KeyboardManager.h"

void Building::Initialize(int floorCnt, int elevatorCnt,  ConsoleMap* buffer) {
	m_pConsoleMap = buffer;
	
	InitFloor(floorCnt);
	InitElevator(elevatorCnt);
	InitSpawner();
}

void Building::Update() {
	this->UpdateMember();
	m_pHumanSpanwer->Update();
}

void Building::Render() {
	this->RenderMember();
	this->RenderBuilding();
	this->RenderElevatorInfo();
	m_pHumanSpanwer->Render();
}

void Building::Release() {
	for (auto iter = m_elevators.begin(); iter != m_elevators.end(); ++iter) {
		(*iter)->Release();
		SAFE_DELETE(*iter);
	}
	for (auto iter = m_floors.begin(); iter != m_floors.end(); ++iter) {
		(*iter)->Release();
		SAFE_DELETE(*iter);
	}
	SAFE_RELEASE(m_pHumanSpanwer);
}

void Building::InitFloor(int cnt) {
	m_floorCount = cnt;
	m_floors.reserve(m_floorCount * 2);
	for (int i = 0; i < m_floorCount; ++i) {
		Floor* floor = new Floor();
		floor->Initialize(i, m_pConsoleMap);

		m_floors.push_back(floor);
	}
}

void Building::InitElevator(int cnt) {
	int skipBufferSize = 4;
	m_elevatorCount = cnt;
	m_elevators.reserve(m_elevatorCount * 2);
	for (int i = 0; i < m_elevatorCount; ++i) {
		Elevator* elevator = new Elevator();
		elevator->Initialize(
			m_floors, 3,	
			Point(m_elevatorCount * 3 + skipBufferSize + i, m_floorCount), m_pConsoleMap);

		m_elevators.push_back(elevator);
	}
}

void Building::InitSpawner() {
	m_pHumanSpanwer = new HumanSpawner();
	m_pHumanSpanwer->Initialize(1, m_elevatorCount, &m_floors, m_pConsoleMap);
}

void Building::RenderBuilding() {
	int index = 0;
	for (int y = 0; y < m_pConsoleMap->GetSize()->height; ++y) {
		for (int x = 0; x < m_pConsoleMap->GetSize()->width; ++x) {
			if (y == m_floorCount + 1  && x < m_elevatorCount * 3 + 2)
				*(m_pConsoleMap->GetBuffer(x, y)) = "бс";
			else if (y == 0 && x < m_elevatorCount * 3 + 2)
				*(m_pConsoleMap->GetBuffer(x, y)) = "бс";
			else if (x == 0 && y < m_floorCount + 1)
				*(m_pConsoleMap->GetBuffer(x, y)) = "бс";
			else if (x == m_elevatorCount * 3 + 2 - 1 && y < m_floorCount + 1 )
				*(m_pConsoleMap->GetBuffer(x, y)) = "бс";
			else if (x == m_elevatorCount * 3 + 2 && y < m_floorCount + 1 && y > 0) {
				std::string floor = std::to_string(index++);
				if (floor.length() < 2)
					floor = "0" + floor;
				*(m_pConsoleMap->GetBuffer(x, y)) = floor;
			}
		}
	} 
}

void Building::RenderMember() {
	for (auto iter = m_elevators.begin(); iter != m_elevators.end(); ++iter)
		(*iter)->Render();
	for (auto iter = m_floors.begin(); iter != m_floors.end(); ++iter)
		(*iter)->Render();
}

void Building::RenderElevatorInfo() {
	int index = 0;
	for (auto out_iter = m_elevators.begin(); out_iter != m_elevators.end(); ++out_iter) {
		std::string log;
		log = std::to_string(index) + "╚г▒т (" + std::to_string((*out_iter)->GetWeight()) + "/" + std::to_string(Elevator::LIMITED_WEIGHT) + ") : " ;
		for (auto in_iter = (*out_iter)->GetHumans()->begin(); in_iter != (*out_iter)->GetHumans()->end(); ++in_iter) {
			log += (std::to_string((*in_iter)->GetTargetFloorCount()) + ",");
		}
		GET_SINGLE(LogManager)->PushLine(log);
		index++;
	}
}

void Building::UpdateMember() {
	for (auto iter = m_elevators.begin(); iter != m_elevators.end(); ++iter)
		(*iter)->Update();
	for (auto iter = m_floors.begin(); iter != m_floors.end(); ++iter)
		(*iter)->Update();
}

Building::Building() : m_floors(0), m_elevators(0) {
}

Building::~Building() {
}
