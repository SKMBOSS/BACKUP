#include "cIntro.h"
#include <iostream>
#include <conio.h>

cIntro::cIntro()
{
}

cIntro::~cIntro()
{
}

void cIntro::Init()
{
	system("cls");
	inFile.open("introText.txt", std::ios::in);

	LoadIntroText();
	std::cout << introText << std::endl;
}

void cIntro::Update()
{
	if (bEnter)
		LoadIntroText();
}

void cIntro::Render()
{
	if (bEnter)
	{
		std::cout << introText << std::endl;
		bEnter = false;
	}
}

void cIntro::Release()
{
}

void cIntro::OperateInput()
{
	if (_kbhit())
	{
		char key = _getch();

		switch (key)
		{
		case ENTER:
			bEnter = true;

			if (FileEnd())
				bSceneEnd = true;
		default:
			break;
		}
	}
}