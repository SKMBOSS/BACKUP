#pragma once
#include <time.h>
#include <stdlib.h>
#include "Map.h"

class Food
{
private:
	int FoodPosX;
	int FoodPosY;
	Map* pMap;
	Food* pFood;
public:
	void Init(Map* _pMap);
	void ThrowFood(Map* _pMap);

	Food();
	~Food();
};

