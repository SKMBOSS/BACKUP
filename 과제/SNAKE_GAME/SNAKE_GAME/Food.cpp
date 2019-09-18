#include "Food.h"

Food::Food()
{
}

Food::~Food()
{
}

void Food::Init(Map* _pMap)
{
	srand(time(nullptr));
	ThrowFood(_pMap);
}

void Food::ThrowFood(Map* _pMap)
{
	while (true)
	{
		FoodPosX = rand() % (WIDTH - 2) + 1;
		FoodPosY = rand() % (HEIGHT - 2) + 1;

		if (_pMap->isTail(FoodPosX, FoodPosY) || _pMap->isPlayer(FoodPosX, FoodPosY))
		{
			continue;
		}
		break;
	}
	_pMap->SetFood(FoodPosX, FoodPosY);
}