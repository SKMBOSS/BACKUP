#include <iostream>
#include <Windows.h>
#include "Map.h"
#include "Food.h"
#include "Player.h"

using namespace std;

const int FPS = 20;

int main()
{
	Map map;
	Player player;
	Food food;

	map.Init();
	food.Init(&map);
	player.Init(&map, &food);

	while (player.GameOver())
	{
		player.OperateInput();
		player.Update();
		Sleep(1000 / FPS);
		map.DrawMap();
	}

	return 0;
}