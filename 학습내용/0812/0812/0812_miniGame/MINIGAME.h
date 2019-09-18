#pragma once
#include "PLAYER.h"

#define MAP_SIZE 19

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32

#define WALL -1
#define BLANK 1

class MINIGAME
{
private:
	PLAYER player;
	int board[MAP_SIZE][MAP_SIZE];

public:
	MINIGAME();
	~MINIGAME();

	void Init();
	void DrawMap();
	void OperateInput();
};

