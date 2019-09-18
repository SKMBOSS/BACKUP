#include "cMap.h"

cMap::cMap()
{
}

cMap::~cMap()
{
}

void cMap::LoadMap(std::string mapFile, cPlayer* _pPlayer)
{
	pPlayer = _pPlayer;

	std::ifstream inFile(mapFile);
	std::string sBuffer;

	inFile >> WIDTH >> HEIGHT;

	map = new TILE*[HEIGHT];

	for (int i = 0; i < HEIGHT; i++)
		map[i] = new TILE[WIDTH];

	for (int y = 0; y < HEIGHT; y++)
	{
		inFile >> sBuffer;
		for (int x = 0; x < WIDTH; x++)
		{
			switch (sBuffer[x])
			{
			case '0':
				SetEmpty(x, y);
				break;
			case '1':
				SetWall(x, y);
				break;
			case '2':
				SetDoor(x, y);
				break;
			default:
				break;
			}
		}
	}
	
	inFile >> enemyX >> enemyY;
	SetEnemy(enemyX, enemyY);

}

void cMap::DrowMap(cPlayer*_pPlayer)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			switch (map[y][x])
			{
			case TILE_EMPTY:
				std::cout << "  ";
				break;
			case TILE_WALL:
				std::cout << "¡á";
				break;
			case TILE_DOOR:
				std::cout << "¡Þ";
				break;
			case TILE_PLAYER:
				std::cout << "¡Ù";
				break;
			case TILE_ENEMY:
				std::cout << "¢±";
				break;

			default:
				break;
			}
		}
		std::cout << std::endl;
	}
}