#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Elevator.h"
#include "Floor.h"
#include "Person.h"

using namespace std;

const int MAX_ELEVATOR = 4;
const int MAX_FLOOR = 20;

class Simulation
{
private:
	Elevator elevator[MAX_ELEVATOR];
	Floor floor[MAX_FLOOR];
	bool autoMode = true;
	bool isOperating = true;

public:
	void Init();
	void Input();
	void Render();
	void Update();

	void PrintLeftScreen(int _curF);
	void PrintRightScreen(int _curF);
	void PrintMiddleScreen(int _curF, int _idx);
	void PrintEelevatorInfo();
	
	void OutElevator(int *_curF, int _idx);
	inline bool IsStop(int _idx)
	{
		if (!elevator[_idx].isDown && !elevator[_idx].isUp)
			return true;
		else
			return false;
	}
	void Wait(int _curF, Elevator& e);
	void TurnOff_UP(int _idx);
	void TurnOff_DOWN(int _idx);
	
	void userInput();
	void randomInput();
	inline bool IsOperating()
	{
		return isOperating;
	}
	Simulation();
	~Simulation();
};

