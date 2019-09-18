#pragma once

const int WIDTH = 17;
const int HEIGHT = 17;

class Map
{
public:
	enum TILE
	{
		TILE_EMPTY,
		TILE_WALL,
		TILE_FOOD,
		TILE_TAIL,
		TILE_PLAYER
	};
private:
	TILE map[HEIGHT][WIDTH];
public:
	Map();
	~Map();

	void Init();
	void DrawMap();

	inline bool isTileWall(int x, int y)
	{
		if (map[y][x] == TILE_WALL)
			return true;
		else
			return false;
	}

	inline bool isFood(int x, int y)
	{
		if (map[y][x] == TILE_FOOD)
			return true;
		else
			return false;
	}

	inline bool isTail(int x, int y)
	{
		if (map[y][x] == TILE_TAIL)
			return true;
		else
			return false;
	}

	inline bool isPlayer(int x, int y)
	{
		if (map[y][x] == TILE_PLAYER)
			return true;
		else
			return false;
	}


	inline void SetPlayer(int x, int y)
	{
		map[y][x] = TILE_PLAYER;
	}

	inline void SetTail(int x, int y)
	{
		map[y][x] = TILE_TAIL;
	}

	inline void SetFood(int x, int y)
	{
		map[y][x] = TILE_FOOD;
	}

	inline void SetEmpty(int x, int y)
	{
		map[y][x] = TILE_EMPTY;
	}


};

