#include "Floor.h"
#include "Utility.h"
#include "Macro.h"
#include "ConsoleMap.h"

void Floor::Initialize(int floorCnt, ConsoleMap* buffer) {
	m_floorCount = floorCnt;
	m_pConsoleMap = buffer;
}

void Floor::Update() {
	UpdateHumans();
	ControlElevatorButton();
	SortWatingHumans();
}

void Floor::Render() {
	for (auto iter = m_waitingHumans.begin(); iter != m_waitingHumans.end(); ++iter)
		(*iter)->Render();
}

void Floor::Release() {
	for (auto iter = m_waitingHumans.begin(); iter != m_waitingHumans.end(); ++iter)
		SAFE_RELEASE((*iter));
}

void Floor::PushHuman(int targetFloorCount) {
	if (targetFloorCount == m_floorCount)
		return;

	Human* human = new Human();
	human->Initialize(targetFloorCount, Point((int)m_waitingHumans.size() + 1, m_floorCount + 1), m_pConsoleMap);
	m_waitingHumans.push_front(human);
}

// 상호참조나 콜백, 혹은 벡터 자체를 넘기는 방법으로 변경?
Human* Floor::PopHuman(int elevatorFloor, bool isUp) {
	if (m_waitingHumans.size() <= 0)
		return nullptr;

	for (auto iter = m_waitingHumans.begin(); iter != m_waitingHumans.end(); ) {
		if (isUp) {
			if ((*iter)->GetTargetFloorCount() < elevatorFloor) {
				auto ret = *iter;
				iter = m_waitingHumans.erase(iter);
				return ret;
			} else
				++iter;
		} else {
			if ((*iter)->GetTargetFloorCount() > elevatorFloor) {
				auto ret = *iter;
				iter = m_waitingHumans.erase(iter);
				return ret;
			} else
				++iter;
		}
	}

	return nullptr;
}

void Floor::UpdateHumans() {
	for (auto iter = m_waitingHumans.begin(); iter != m_waitingHumans.end(); ++iter)
		(*iter)->Update();
}

void Floor::SortWatingHumans() {
	for (int i = 0; i < m_waitingHumans.size(); ++i)
		m_waitingHumans[i]->SetPosition(Point(i + 1, m_floorCount + 1));
}

void Floor::ControlElevatorButton() {
	m_isPressElevatorButton = m_waitingHumans.size() > 0 ? true : false;
}

Floor::Floor() : m_isPressElevatorButton(false) {
}

Floor::~Floor() {
}
