#pragma once
#include "cMap.h"
#include "cPlayer.h"

const int Arrowkey = 224;
const int UP = 72;
const int DOWN = 80;
const int RIGHT = 77;
const int LEFT = 75;
const int ENTER = 13;
const int ESC = 27;

class cScene
{
protected:
	cMap map;
	cPlayer player;
public:
	bool bSceneEnd = false;
	bool bSceneLoad = false;
	bool bCallMenu = false;

	cScene();
	virtual ~cScene(); //°¡»ó¼Ò¸êÀÚ

	virtual void Init() = 0;
	virtual void OperateInput() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

};