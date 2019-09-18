#include "cTitle.h"
#include <iostream>
#include <conio.h>

cTitle::cTitle()
{
}

cTitle::~cTitle()
{
}

void cTitle::Init()
{
	titleState = START;

}

void cTitle::Update()
{

}

void cTitle::Render()
{
	system("cls");
	PrintTitle();
}

void cTitle::Release()
{
}

void cTitle::PrintTitle() const
{
	if (titleState == START)
		PrintStart();

	else if (titleState == LOAD)
		PrintLoad();
}

void cTitle::PrintStart() const
{
	std::cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	std::cout << "弛 Neople Jeju Academy 2019                                               弛\n";
	std::cout << "弛             Lee Jung Soo                                               弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                     忙式式式式式式式式式式式式式忖                     弛\n";
	std::cout << "弛                     弛    Ⅱ  Start Game        弛                     弛\n";
	std::cout << "弛                     弛        Load  Game        弛                     弛\n";
	std::cout << "弛                     戌式式式式式式式式式式式式式戎                     弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
}

void cTitle::PrintLoad() const
{
	std::cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	std::cout << "弛 Neople Jeju Academy 2019                                               弛\n";
	std::cout << "弛             Lee Jung Soo                                               弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                     忙式式式式式式式式式式式式式忖                     弛\n";
	std::cout << "弛                     弛        Start Game        弛                     弛\n";
	std::cout << "弛                     弛    Ⅱ  Load  Game        弛                     弛\n";
	std::cout << "弛                     戌式式式式式式式式式式式式式戎                     弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "弛                                                                        弛\n";
	std::cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
}

void cTitle::OperateInput()
{
	if (_kbhit())
	{
		char key = _getch();

		switch (key)
		{
		case UP:
		case DOWN:
			if (titleState == LOAD)
				titleState = START;

			else if (titleState == START)
				titleState = LOAD;
			break;
		case ENTER:
			if (titleState == START)
				bSceneEnd = true;

			else if (titleState == LOAD)
			{
				bSceneEnd = true;
				bSceneLoad = true;
			}
			break;		
		default:
			break;
		}
	}
}