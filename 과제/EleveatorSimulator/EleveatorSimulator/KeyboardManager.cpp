#include "KeyboardManager.h"
#include <windows.h>


void KeyboardManager::Initialize() {
	m_key[KC_UP].key   = VK_UP;
	m_key[KC_DOWN].key = VK_DOWN;
	m_key[KC_Z].key = 0x5A;
	m_key[KC_X].key = 0x58;
}

void KeyboardManager::Update() {
	m_anyKey = false; // 초기화하고 시작하여 버튼이 하나라도 눌려있으면 true처리.

	for (int i = 0; i < KC_LAST; ++i) {
		if (m_key[i].key == 0)
			continue; 
		if (GetAsyncKeyState(m_key[i].key) & 0x8000) {  // 지금 확인하는 버튼이 눌린 상태일 경우
			if (m_key[i].press == false) { // 눌려 있는 상태가 아닐 경우
				m_key[i].down = true;
			} else // 눌려 있던 경우
				m_key[i].down = false; 
			m_key[i].press = true;
			m_anyKey = true;
		} else { // 지금 확인하는 버튼이 눌리지 않은 상태가 아닐 경우
			if (m_key[i].press == true) {
				m_key[i].up = true;
			} else 
				m_key[i].up = false;

			m_key[i].down = false;
			m_key[i].press = false;
		}
	}
}

void KeyboardManager::Release() {
	DESTROY_SINGLE(KeyboardManager);
}

KeyboardManager::KeyboardManager() { }


KeyboardManager::~KeyboardManager() { }
