#include "cMenu.h"
#include <iostream>
#include <conio.h>

cMenu::cMenu()
{
}

cMenu::~cMenu()
{
}

void cMenu::Init()
{
	system("cls");

	player.LoadStatus();
}

void cMenu::OperateInput()
{
	if (_kbhit())
	{
		char key = _getch();

		switch (key)
		{
		case ESC:
			bSceneEnd = true;
			break;
		default:
			break;
		}
	}
}

void cMenu::Update()
{
}

void cMenu::Render()
{
	system("cls");

	std::cout << "플레이어위치 : " << player.GetPlayerX() << "," << player.GetPlayerY() << std::endl;

	std::cout << "■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■           이름 : 이정수                ■ " << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■  HP  : 100   ■     아이템목록         ■ " << std::endl;
	std::cout << "■  MP  : 100   ■■■■■■■■■■■■■■ " << std::endl;
	std::cout << "■  ATK :  10   ■   ▶    빵 X 10        ■ " << std::endl;
	std::cout << "■  DEF :  10   ■   ▶  우유 X 10        ■ " << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■ " << std::endl;
	std::cout << "■  EXP :   0                             ■ " << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■ " << std::endl;
}

void cMenu::Release()
{
}
