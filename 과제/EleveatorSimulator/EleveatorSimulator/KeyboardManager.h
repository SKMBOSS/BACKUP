#ifndef _KEYBOARDMANAGER_H_
#define _KEYBOARDMANAGER_H_

#include "Macro.h"

enum KEY_CODE {
	KC_NULL = -1,
	KC_UP,		KC_DOWN,
	KC_Z,		KC_X,
	KC_LAST, 
};

typedef struct tagKeyState {
public:
	short key;  // 활성화할 키
	bool down;  // 누르는 순간 
	bool press; // 눌려있는 순간
	bool up;    // 떼는 순간

public:
	struct tagKeyState() : key(0), down(false),
		press(false), up(false) {}
} KeyState;

class KeyboardManager {
	DECLARE_SINGLETON(KeyboardManager)
	COPY_PROTECTION(KeyboardManager)
private: 
	KeyState m_key[KEY_CODE::KC_LAST];
	bool m_anyKey;

public: 
	void Initialize();
	void Update();       
	void Release();

	const inline bool IsInputAnyKey()		         { return m_anyKey; }
	const inline bool GetKeyDown(KEY_CODE KeyType)   { return m_key[KeyType].down; }
	const inline bool GetKeyPress(KEY_CODE KeyType)  { return m_key[KeyType].press; }
	const inline bool GetKeyUp(KEY_CODE KeyType)	 { return m_key[KeyType].up;	}

private:
	KeyboardManager();
public:
	~KeyboardManager();
};

#endif



