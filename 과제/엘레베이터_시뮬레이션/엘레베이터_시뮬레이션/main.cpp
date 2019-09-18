#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "Simulation.h"
using namespace std;

const int FPS = 30;

int main()
{
	Simulation *simulation = new Simulation();

	simulation->Init();
	simulation->Render();

	while (simulation->IsOperating())
	{
		simulation->Input();
		simulation->Update();
		simulation->Render();
		Sleep(1000/FPS);
	}
	delete simulation;
	
	return 0;
}
