#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MINIGAME.h"

using namespace std;

int main()
{
	MINIGAME MYGAME;
	MYGAME.Init();
	MYGAME.DrawMap();

	while (true)
	{
		MYGAME.OperateInput();
		MYGAME.DrawMap();
	}

	system("pause");
	return 0;
}