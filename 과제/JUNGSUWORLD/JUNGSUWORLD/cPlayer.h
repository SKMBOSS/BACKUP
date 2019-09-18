#pragma once
#include <string>

class cPlayer
{
private:
	int playerX=0;
	int playerY=0;

	std::string playerName = "ÀÌÁ¤¼ö";
	int hp=100;
	int mp=100;
	int atk=10;
	int def=10;
	int exp=0;

public:
	cPlayer();
	~cPlayer();

	void SaveStatus();
	void LoadStatus();

	inline int GetPlayerX()
	{
		return playerX;
	}

	inline int GetPlayerY()
	{
		return playerY;
	}

	inline void SetPlayerPos(int x, int y)
	{
		playerX = x;
		playerY = y;
	}

	inline void MoveUp()
	{
		playerY--;
	}

	inline void MoveDown()
	{
		playerY++;
	}

	inline void MoveLeft()
	{
		playerX--;
	}

	inline void MoveRight()
	{
		playerX++;
	}
};

