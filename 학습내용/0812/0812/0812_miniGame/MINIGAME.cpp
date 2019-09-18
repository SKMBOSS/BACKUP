#include <iostream>
#include <conio.h>
#include "MINIGAME.h"

using namespace std;

MINIGAME::MINIGAME()
{
}


MINIGAME::~MINIGAME()
{
}

void MINIGAME::Init()
{
	player.initPlayer();

	for (int iy = 0; iy < MAP_SIZE; iy++)
	{
		for (int jx = 0; jx < MAP_SIZE; jx++)
		{
			if ((iy == 0) || (iy == MAP_SIZE - 1) || (jx == 0) || (jx == MAP_SIZE - 1))
				board[iy][jx] = WALL;

			else
				board[iy][jx] = BLANK;
		}
	}
}

void MINIGAME::DrawMap()
{
	system("cls");

	for (int iy = 0; iy < MAP_SIZE; iy++)
	{
		for (int jx = 0; jx < MAP_SIZE; jx++)
		{
			if (iy == player.PosY && jx == player.PosX)
				cout << "бр";

			else if (board[iy][jx] == WALL)
			{
				cout << "бс";
			}
			else
				cout << "  ";
		}
		cout << endl;
	}
}

void MINIGAME::OperateInput()
{
	char input = _getch();
	
	if (input == UP)
	{
		if (board[player.PosY - 1][player.PosX] != WALL)
			player.PosY--;
	}

	else if (input == DOWN)
	{
		if (board[player.PosY + 1][player.PosX] != WALL)
			player.PosY++;
	}
	else if (input == LEFT)
	{

		if (board[player.PosY][player.PosX - 1] != WALL)
			player.PosX--;
	}

	else if (input == RIGHT)
	{
		if (board[player.PosY][player.PosX + 1] != WALL)
			player.PosX++;
	}

	else if (input == SPACE)
	{
		board[player.PosY][player.PosX] = WALL;
	}
}