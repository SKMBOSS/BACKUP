#pragma once
#include "cScene.h"

class cTownHall : public cScene
{
public:
	void Init();
	void OperateInput();
	void Update();
	void Render();
	void Release();

	cTownHall();
	~cTownHall();
};

