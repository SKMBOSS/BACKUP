#pragma once
#include "Map.h"
#include "Food.h"

const int MAX_TAIL = (WIDTH-2) * (HEIGHT-2);

class Player
{
public:
	enum DIRRECTION
	{
		DIRRECTION_LEFT,
		DIRRECTION_RIGHT,
		DIRRECTION_UP,
		DIRRECTION_DOWN
	};
private:
	int playerX[MAX_TAIL] = { WIDTH / 2, };
	int playerY[MAX_TAIL] = { HEIGHT / 2, };
	int dirrection = DIRRECTION_UP;
	int length = 1;
	bool isEatFood = false;
	bool isPlaying = true;
	Map* pMap;
	Food* pFood;
public:
	void Init(Map* _pMap, Food*_pFood);
	void OperateInput();
	void Update();

	inline bool GameOver()
	{
		return isPlaying;
	}

	inline bool EatFood()
	{
		return isEatFood;
	}

	Player();
	~Player();
};

