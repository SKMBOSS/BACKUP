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

	std::cout << "�÷��̾���ġ : " << player.GetPlayerX() << "," << player.GetPlayerY() << std::endl;

	std::cout << "�����������������������" << std::endl;
	std::cout << "��           �̸� : ������                �� " << std::endl;
	std::cout << "�����������������������" << std::endl;
	std::cout << "��  HP  : 100   ��     �����۸��         �� " << std::endl;
	std::cout << "��  MP  : 100   ��������������� " << std::endl;
	std::cout << "��  ATK :  10   ��   ��    �� X 10        �� " << std::endl;
	std::cout << "��  DEF :  10   ��   ��  ���� X 10        �� " << std::endl;
	std::cout << "����������������������� " << std::endl;
	std::cout << "��  EXP :   0                             �� " << std::endl;
	std::cout << "����������������������� " << std::endl;
}

void cMenu::Release()
{
}
