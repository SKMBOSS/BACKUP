#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "cPlayer.h"

class cMap
{
public:
	enum TILE
	{
		TILE_EMPTY,
		TILE_WALL,
		TILE_DOOR,
		TILE_PLAYER,
		TILE_ENEMY
	};

private:
	int WIDTH=0;
	int HEIGHT=0;
	
	int enemyX;
	int enemyY;
	TILE **map;
	cPlayer *pPlayer;
	
public:
	void LoadMap(std::string mapFile, cPlayer* _pPlayer);
	void DrowMap(cPlayer* _pPlayer);

	inline bool IsEmpty(int x, int y)
	{
		if (map[y][x] == TILE_EMPTY)
			return true;
		else
			return false;
	}

	inline bool IsWall(int x, int y)
	{
		if (map[y][x] == TILE_WALL)
			return true;
		else
			return false;
	}

	inline bool IsDoor(int x, int y)
	{
		if (map[y][x] == TILE_DOOR)
			return true;
		else
			return false;
	}

	inline bool IsPlayer(int x, int y)
	{
		if (map[y][x] == TILE_PLAYER)
			return true;
		else
			return false;
	}

	inline bool IsEnemy(int x, int y)
	{
		if (map[y][x] == TILE_ENEMY)
			return true;
		else
			return false;
	}

	inline void SetEmpty(int x, int y)
	{
		map[y][x] = TILE_EMPTY;
	}

	inline void SetWall(int x, int y)
	{
		map[y][x] = TILE_WALL;
	}

	inline void SetDoor(int x, int y)
	{
		map[y][x] = TILE_DOOR;
	}

	inline void SetPlayer(int x, int y)
	{
		map[y][x] = TILE_PLAYER;
	}

	inline void SetEnemy(int x, int y)
	{
		map[y][x] = TILE_ENEMY;
	}

	cMap();
	~cMap();
};

