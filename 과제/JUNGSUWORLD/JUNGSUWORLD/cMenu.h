#pragma once
#include "cScene.h"
class cMenu : public cScene
{
private:
public:
	cMenu();
	~cMenu();

	void Init();
	void OperateInput();
	void Update();
	void Render();
	void Release();

	void PrintStatus1();
	void PrintStatus2();

};

