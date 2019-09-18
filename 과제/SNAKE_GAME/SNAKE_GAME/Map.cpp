#include "Map.h"
#include <iostream>
using namespace std;

Map::Map()
{
}


Map::~Map()
{
}

void Map::Init()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			map[i][j] = TILE_EMPTY;
	}

	for (int i = 0; i < HEIGHT; i++)
	{
		map[i][0] = TILE_WALL;
		map[i][WIDTH - 1] = TILE_WALL;
	}

	for (int j = 0; j < WIDTH; j++)
	{
		map[0][j] = TILE_WALL;
		map[HEIGHT - 1][j] = TILE_WALL;
	}
}

void Map::DrawMap()
{
	system("cls");
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			switch (map[i][j])
			{
			case TILE_EMPTY:
				cout << "  ";
				break;
			case TILE_WALL:
				cout << "бс";
				break;
			case TILE_FOOD:
				cout << "б┘";
				break;
			case TILE_TAIL:
				cout << "бс";
				break;
			case TILE_PLAYER:
				cout << "б█";
				break;
			}
		}
		cout << endl;
	}
}
