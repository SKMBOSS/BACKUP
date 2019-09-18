#include "KeyboardManager.h"
#include <windows.h>


void KeyboardManager::Initialize() {
	m_key[KC_UP].key   = VK_UP;
	m_key[KC_DOWN].key = VK_DOWN;
	m_key[KC_Z].key = 0x5A;
	m_key[KC_X].key = 0x58;
}

void KeyboardManager::Update() {
	m_anyKey = false; // �ʱ�ȭ�ϰ� �����Ͽ� ��ư�� �ϳ��� ���������� trueó��.

	for (int i = 0; i < KC_LAST; ++i) {
		if (m_key[i].key == 0)
			continue; 
		if (GetAsyncKeyState(m_key[i].key) & 0x8000) {  // ���� Ȯ���ϴ� ��ư�� ���� ������ ���
			if (m_key[i].press == false) { // ���� �ִ� ���°� �ƴ� ���
				m_key[i].down = true;
			} else // ���� �ִ� ���
				m_key[i].down = false; 
			m_key[i].press = true;
			m_anyKey = true;
		} else { // ���� Ȯ���ϴ� ��ư�� ������ ���� ���°� �ƴ� ���
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
