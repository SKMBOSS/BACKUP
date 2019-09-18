#include "Elevator.h"
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

Elevator::Elevator()
{
}

Elevator::~Elevator()
{
	for (auto iter = peopleInEv.begin(); iter != peopleInEv.end(); ++iter)
		delete *iter;

	peopleInEv.clear();	
	deque<Person*>().swap(peopleInEv);
}

void Elevator::InsertPerson(Person* p)
{
	totalWeight += p->GetWeight();

	peopleInEv.push_back(p);
	SortPeople();
}

void Elevator::SortPeople()
{
	if (isUp)
		sort(peopleInEv.begin(), peopleInEv.end(), [](Person* left, Person* right)
			->bool {return left->GetDestFloor() < right->GetDestFloor(); });

	else if (isDown)
		sort(peopleInEv.begin(), peopleInEv.end(), [](Person* left, Person* right)
			->bool {return left->GetDestFloor() > right->GetDestFloor(); });
}

void Elevator::OutPerson()
{
	totalWeight -= peopleInEv.front()->GetWeight();

	delete peopleInEv.front();
	peopleInEv.pop_front();
}

void Elevator::Print()
{
	if (isUp)
		cout << "¡ã";
	else if (isDown)
		cout << "¡å";
	else if(!isUp && !isDown)
		cout << "¡á";
}

void Elevator::PrintInfo()
{
	cout << "[";

	cout.width(3);
	cout.fill(' ');
	cout<<totalWeight << "/" << MAX_WEIGHT << "]  ";

	cout.width(2);
	cout.fill(' ');
	cout << currentFloor + 1 << "Ãþ µµÂø! ";
	cout << "[";
	for (auto iter = peopleInEv.begin(); iter != peopleInEv.end(); ++iter)
	{
		cout << (*iter)->GetDestFloor() + 1 << "/";
	}
	cout << "]"; cout << endl;
}