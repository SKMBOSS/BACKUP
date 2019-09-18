#include "Simulation.h"
#include <time.h>
#include <cstring>
#include <conio.h>

Simulation::Simulation()
{
}

Simulation::~Simulation()
{
}

void Simulation::Init()
{
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		floor[i].SetFloor(i);
	}

	srand(time(nullptr));

	for (int ei = 0; ei < MAX_ELEVATOR; ei++)
	{
		int random = rand() % MAX_FLOOR;
		elevator[ei].SetCurrentFloor(random);
	}
}

void Simulation::Input()
{
	if (_kbhit() )
	{
		char ch = _getch();

		if (ch == 'q')
			autoMode = false;
	}

	if (autoMode)
		randomInput();
	else
		userInput();
}

void Simulation::Render()
{
	system("cls");
	for (int curF = MAX_FLOOR - 1; curF >= 0; curF--)
	{
		PrintLeftScreen(curF);

		for (int ei = 0; ei < MAX_ELEVATOR; ei++)
		{
			PrintMiddleScreen(curF, ei);
		}
		PrintRightScreen(curF);
	}
	PrintEelevatorInfo();
}

void Simulation::Update()
{
	int curF[MAX_ELEVATOR];

	for (int ei = 0; ei < MAX_ELEVATOR; ei++)
	{
		curF[ei] = elevator[ei].GetCurrentFloor();
		OutElevator(curF, ei);

		if (IsStop(ei))
		{
			Wait(curF[ei], elevator[ei]);
		}

		if (elevator[ei].isUp)
		{
			while (floor[curF[ei]].GetUpNum() > 0)
			{
				if (!elevator[ei].Empty())
				{
					if (elevator[ei].OverWeight(elevator[ei].GetFrontPerson()->GetWeight()))
						break;
				}
				elevator[ei].InsertPerson(floor[curF[ei]].OutUpPerson());

				for (int ej = 0; ej < MAX_ELEVATOR; ej++)
				{
					if (ej == ei)
						continue;

					if (elevator[ej].Empty())
					{
						TurnOff_UP(ej);
					}
				}
			}

			if (!elevator[ei].Empty())
				elevator[ei].SetDestFloor(elevator[ei].GetBackPerson()->GetDestFloor());

			if (elevator[ei].GetDestFloor() == curF[ei])
			{
				elevator[ei].isUp = false;
			}
			else
				elevator[ei].UpFloor();
		}

		else if (elevator[ei].isDown)
		{
			while (floor[curF[ei]].GetDownNum() > 0)
			{
				if (!elevator[ei].Empty())
				{
					if (elevator[ei].OverWeight(elevator[ei].GetFrontPerson()->GetWeight()))
						break;
				}
				elevator[ei].InsertPerson(floor[curF[ei]].OutDownPerson());

				for (int ej = 0; ej < MAX_ELEVATOR; ej++)
				{
					if (ej == ei)
						continue;

					if (elevator[ej].Empty())
					{
						TurnOff_DOWN(ej);
					}			
				}
			}
			if (!elevator[ei].Empty())
				elevator[ei].SetDestFloor(elevator[ei].GetBackPerson()->GetDestFloor());

			if (elevator[ei].GetDestFloor() == curF[ei])
			{
				elevator[ei].isDown = false;
			}
			else
				elevator[ei].DownFloor();
		}
	}
}

void Simulation::PrintLeftScreen(int _curF)
{
	floor[_curF].upWatingPrint();
	cout << " ";
	cout.width(2);
	cout.fill('0');
	cout << _curF + 1;
	cout << "\t ";
}

void Simulation::PrintRightScreen(int _curF)
{
	cout << "\t";
	cout.width(2);
	cout.fill('0');
	cout << _curF + 1 << " ";
	floor[_curF].downWatingPrint();
	cout << endl;
}

void Simulation::PrintMiddleScreen(int _curF, int _idx)
{
	if (elevator[_idx].GetCurrentFloor() == _curF)
		elevator[_idx].Print();
	else
		cout << "□";
}

void Simulation::PrintEelevatorInfo()
{
	cout << endl;
	for (int ei = 0; ei < MAX_ELEVATOR; ei++)
	{
		cout << ei + 1 << "호기 : ";
		elevator[ei].PrintInfo();
	}
}

void Simulation::OutElevator(int *_curF, int _idx)
{
	while (!elevator[_idx].Empty())
	{
		if (_curF[_idx] == elevator[_idx].GetFrontPerson()->GetDestFloor())
			elevator[_idx].OutPerson();
		else
			break;
	}
}

void Simulation::Wait(int _curF, Elevator& e)
{
	if (_curF >= MAX_FLOOR / 2)
	{
		for (int i = MAX_FLOOR-1; i >= 0; i--)
		{
			if (floor[i].ExistUpPeople() || floor[i].ExistDownPeople())
			{
				if (i > _curF)
				{
					e.isUp = true;
				}
				else if (i < _curF)
					e.isDown = true;
				else if (i == _curF)
				{
					if (floor[i].ExistUpPeople())
						e.isUp = true;
					else if (floor[i].ExistDownPeople())
						e.isDown = true;
				}
				if (floor[i].ExistUpPeople())
					e.SetDFF(e.UP);

				else if (floor[i].ExistDownPeople())
					e.SetDFF(e.DOWN);

				else if (floor[i].ExistUpPeople() && floor[i].ExistDownPeople())
					e.SetDFF(e.BOTH);

				e.SetDestFloor(i);
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < MAX_FLOOR; i++)
		{
			if (floor[i].ExistUpPeople() || floor[i].ExistDownPeople())
			{
				if (i > _curF)
				{
					e.isUp = true;
				}
				else if (i < _curF)
					e.isDown = true;
				else if (i == _curF)
				{
					if (floor[i].ExistUpPeople())
						e.isUp = true;
					else if (floor[i].ExistDownPeople())
						e.isDown = true;
				}
				if (floor[i].ExistUpPeople())
					e.SetDFF(e.UP);

				else if (floor[i].ExistDownPeople())
					e.SetDFF(e.DOWN);

				else if (floor[i].ExistUpPeople() && floor[i].ExistDownPeople())
					e.SetDFF(e.BOTH);

				e.SetDestFloor(i);
				break;
			}
		}
	}
}

void Simulation::TurnOff_UP(int _idx)
{
	if (elevator[_idx].GetDFF() == elevator[_idx].UP)
	{
		if (!floor[elevator[_idx].GetDestFloor()].ExistUpPeople())
		{
			elevator[_idx].isUp = false;
			elevator[_idx].SetDestFloor(elevator[_idx].GetCurrentFloor());
		}
	}
}

void Simulation::TurnOff_DOWN(int _idx)
{
	if (elevator[_idx].GetDFF() == elevator[_idx].DOWN)
	{
		if (!floor[elevator[_idx].GetDestFloor()].ExistDownPeople())
		{
			elevator[_idx].isDown = false;
			elevator[_idx].SetDestFloor(elevator[_idx].GetCurrentFloor());
		}
	}
}

void Simulation::userInput()
{
	int input = 0;
	int whereFloor = 0;
	int destFloor = 0;
	int weight = 0;;

	cout <<endl<< "1.추가 2.진행 3.유저모드종료 4.시뮬레이션종료:";
	cin >> input;

	switch (input)
	{
	case 1:
	{
		cout << endl << "몇층에 있습니까? :";
		cin >> whereFloor;
		cout << "목적지가 어딥니까? : ";
		cin >> destFloor;
		cout << "몸무게가 몇입니까? :";
		cin >> weight;

		Person* newPerson = new Person(destFloor - 1, weight);
		floor[whereFloor - 1].InsertPerson(newPerson);

		for (int ei = 0; ei < MAX_ELEVATOR; ei++)
		{
			if (elevator[ei].isUp && newPerson->GetDestFloor() > elevator[ei].GetDestFloor())
			{
				elevator[ei].SetDestFloor(newPerson->GetDestFloor());
			}

			else if (elevator[ei].isDown && newPerson->GetDestFloor() < elevator[ei].GetDestFloor())
			{
				elevator[ei].SetDestFloor(newPerson->GetDestFloor());
			}
		}
		cout << endl << "사람넣기 완료" << endl;
		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{
		autoMode = true;
		break;
	}

	case 4:
	{
		isOperating = false;
		break;
	}
		
	}
}

void Simulation::randomInput()
{
	int input = 0;
	int whereFloor = 0;
	int destFloor = 0;
	int weight = 0;

	whereFloor = rand() % MAX_FLOOR;
	destFloor = rand() % MAX_FLOOR;
	weight = rand() % 60 + 50;

	Person* newPerson = new Person(destFloor, weight);
	floor[whereFloor].InsertPerson(newPerson);

	for (int ei = 0; ei < MAX_ELEVATOR; ei++)
	{
		if (elevator[ei].isUp && newPerson->GetDestFloor() > elevator[ei].GetDestFloor())
		{
			elevator[ei].SetDestFloor(newPerson->GetDestFloor());
		}

		else if (elevator[ei].isDown && newPerson->GetDestFloor() < elevator[ei].GetDestFloor())
		{
			elevator[ei].SetDestFloor(newPerson->GetDestFloor());
		}
	}
}