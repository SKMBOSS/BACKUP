#include "Human.h"
#include "Utility.h"
#include "ConsoleMap.h"

void Human::Initialize(int targetFloor, Point pos, ConsoleMap* buffer) {
	m_pConsoleMap = buffer;
	m_targetFloor = targetFloor;
	m_position = pos;
	m_weight = Utility::RandomRange(65, 100); // floatÀ¸·Î ¹Ù²Ü ¿¹Á¤
}

void Human::Update() {

}

void Human::Render() {
	*(m_pConsoleMap->GetBuffer(m_position.x, m_position.y)) = "¿ô";
}

void Human::Release() {

}

Human::Human() {
}


Human::~Human() {
}
