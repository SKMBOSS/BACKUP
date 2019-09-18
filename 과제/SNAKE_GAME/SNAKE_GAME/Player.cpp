#include <conio.h>
#include <iostream>
#include "Player.h"
#include "Map.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init(Map* _pMap, Food*_pFood)
{
	pMap = _pMap;
	pFood = _pFood;
	pMap->SetPlayer(playerX[0], playerY[0]);
}

void Player::OperateInput()
{
	if (_kbhit())
	{
		char ch = _getch();

		switch (ch)
		{
		case 'w':
			if (dirrection != DIRRECTION_DOWN)
				dirrection = DIRRECTION_UP;
			break;
		case 's':
			if (dirrection != DIRRECTION_UP)
				dirrection = DIRRECTION_DOWN;
			break;
		case 'a':
			if (dirrection != DIRRECTION_RIGHT)
				dirrection = DIRRECTION_LEFT;
			break;
		case 'd':
			if (dirrection != DIRRECTION_LEFT)
				dirrection = DIRRECTION_RIGHT;
			break;
		}
	}
}
void Player::Update()
{
	for (int i = 0; i < length; i++)
		pMap->SetEmpty(playerX[i], playerY[i]);

	if (isEatFood)
	{
		length++;
		isEatFood = false;
	}

	for (int i = length - 1; i >= 0; i--)
	{
		playerX[i + 1] = playerX[i];
		playerY[i + 1] = playerY[i];
	}

	switch (dirrection)
	{
	case DIRRECTION_UP:
		playerY[0]--;
		break;
	case DIRRECTION_DOWN:
		playerY[0]++;
		break;
	case DIRRECTION_LEFT:
		playerX[0]--;
		break;
	case DIRRECTION_RIGHT:
		playerX[0]++;
		break;
	}

	if (pMap->isFood(playerX[0], playerY[0]))
	{
		isEatFood = true;
	}

	if (pMap->isTileWall(playerX[0], playerY[0]))
	{
		isPlaying = false;
	}

	pMap->SetPlayer(playerX[0], playerY[0]);

	for (int i = 1; i < length; i++)
		pMap->SetTail(playerX[i], playerY[i]);


	if (pMap->isTail(playerX[0], playerY[0]))
	{
		isPlaying = false;
	}

	if (isEatFood)
	{
		pFood->ThrowFood(pMap);
	}

	if (length == MAX_TAIL)
	{
		isPlaying = false;
	}
}