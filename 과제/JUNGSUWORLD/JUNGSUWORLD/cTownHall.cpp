#include "cTownHall.h"
#include <conio.h> 
#include <iostream>

cTownHall::cTownHall()
{
}

cTownHall::~cTownHall()
{
}

void cTownHall::Init()
{
	if (bCallMenu)
	{
		player.LoadStatus();
		bCallMenu = false;
	}
	else
	{
		player.SetPlayerPos(1, 15);
	}
	map.LoadMap("townMap.txt", &player);
}

void cTownHall::Render()
{
	system("cls");
	map.DrowMap(&player);
}

void cTownHall::Update()
{
	map.SetPlayer(player.GetPlayerX(), player.GetPlayerY());
}

void cTownHall::Release()
{}

void cTownHall::OperateInput()
{
	if (_kbhit())
	{
		char key = _getch();

		switch (key)
		{
			
		case UP:
			if (!map.IsWall(player.GetPlayerX(), player.GetPlayerY() - 1))
			{
				map.SetEmpty(player.GetPlayerX(), player.GetPlayerY());
				player.MoveUp();
			}
			break;
		case DOWN:
			if (!map.IsWall(player.GetPlayerX(), player.GetPlayerY() + 1))
			{
				map.SetEmpty(player.GetPlayerX(), player.GetPlayerY());
				player.MoveDown();
			}
			break;
		case LEFT:
			if (!map.IsWall(player.GetPlayerX()-1, player.GetPlayerY()))
			{
				map.SetEmpty(player.GetPlayerX(), player.GetPlayerY());
				player.MoveLeft();
			}
			break;
		case RIGHT:
			if (!map.IsWall(player.GetPlayerX() + 1, player.GetPlayerY()))
			{
				map.SetEmpty(player.GetPlayerX(), player.GetPlayerY());
					player.MoveRight();
			}
			break;
		case ESC:
			bSceneEnd = true;
			bCallMenu = true;
			player.SaveStatus();
			break;
		default:
			break;
		}
	}
}