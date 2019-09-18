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
	std::cout << "����������������������������������������������������������������������������\n";
	std::cout << "�� Neople Jeju Academy 2019                                               ��\n";
	std::cout << "��             Lee Jung Soo                                               ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                     ������������������������������                     ��\n";
	std::cout << "��                     ��    ��  Start Game        ��                     ��\n";
	std::cout << "��                     ��        Load  Game        ��                     ��\n";
	std::cout << "��                     ������������������������������                     ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "����������������������������������������������������������������������������\n";
}

void cTitle::PrintLoad() const
{
	std::cout << "����������������������������������������������������������������������������\n";
	std::cout << "�� Neople Jeju Academy 2019                                               ��\n";
	std::cout << "��             Lee Jung Soo                                               ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                     ������������������������������                     ��\n";
	std::cout << "��                     ��        Start Game        ��                     ��\n";
	std::cout << "��                     ��    ��  Load  Game        ��                     ��\n";
	std::cout << "��                     ������������������������������                     ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "��                                                                        ��\n";
	std::cout << "����������������������������������������������������������������������������\n";
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