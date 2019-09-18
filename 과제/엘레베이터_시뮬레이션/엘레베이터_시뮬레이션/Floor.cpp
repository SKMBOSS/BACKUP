#include "Floor.h"
#include <iostream>
using namespace std;

Floor::Floor()
{
}

Floor::~Floor()
{
	for (auto iter = upWaitingPeople.begin(); iter != upWaitingPeople.end(); ++iter)
		delete *iter;

	for (auto iter = downWaitingPeople.begin(); iter != downWaitingPeople.end(); ++iter)
		delete *iter;

	upWaitingPeople.clear();
	downWaitingPeople.clear();

	deque<Person*>().swap(upWaitingPeople);
	deque<Person*>().swap(downWaitingPeople);
}

void Floor::InsertPerson(Person *p)
{
	if (thF > p->GetDestFloor())
	{
		downWaitingPeople.push_back(p);
	}	

	else if (thF < p->GetDestFloor())
	{
		upWaitingPeople.push_back(p);
	}
}

Person* Floor::OutUpPerson()
{
	Person* outPerson = upWaitingPeople.front();
	upWaitingPeople.pop_front();
	return outPerson;
}

Person* Floor::OutDownPerson()
{
	Person* outPerson = downWaitingPeople.front();
	downWaitingPeople.pop_front();
	return outPerson;
}

void Floor::upWatingPrint()
{
	cout << "| ";
	for (int i = 10; i >upWaitingPeople.size(); i--)
	{
		cout << "  ";
	}

	for (int i = 0; i < upWaitingPeople.size(); i++)
	{
		cout << "§Ù";
	}
	cout << " ";
}

void Floor::downWatingPrint()
{
	cout << " ";
	for (int i = 0; i < downWaitingPeople.size(); i++)
	{
		cout << "§Ù";
	}
	for (int i = downWaitingPeople.size(); i < 10; i++)
	{
		cout << "  ";
	}
	cout << "| ";
}