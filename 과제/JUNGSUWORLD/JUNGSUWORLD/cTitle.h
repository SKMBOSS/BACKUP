#pragma once
#include "cScene.h"

enum TITLE_STATE
{
	START,
	LOAD,
};

class cTitle : public cScene
{
private:
	TITLE_STATE titleState;
public:
	cTitle();
	~cTitle();

	void Init();
	void OperateInput();
	void Update();
	void Render();
	void Release();

	void PrintTitle() const;
	void PrintStart() const;
	void PrintLoad() const;
};

