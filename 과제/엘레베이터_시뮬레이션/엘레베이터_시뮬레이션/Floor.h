#pragma once
#include <deque>
#include "Person.h"
#include "Elevator.h"

class Floor
{
private:
	int thF; //자신이몇층
	std::deque<Person*> upWaitingPeople;
	std::deque<Person*> downWaitingPeople;
public:
	void InsertPerson(Person *p); 
	Person* OutUpPerson();
	Person* OutDownPerson();
	void upWatingPrint();
	void downWatingPrint();
	inline bool ExistUpPeople()
	{
		if (upWaitingPeople.empty())
			return false;

		else
			return true;
	}
	inline bool ExistDownPeople()
	{
		if (downWaitingPeople.empty())
			return false;

		else
			return true;
	}
	inline void SetFloor(int _thF)
	{
		thF = _thF;
	}
	inline int GetUpNum()
	{
		return upWaitingPeople.size();
	}
	inline int GetDownNum()
	{
		return downWaitingPeople.size();
	}

	Floor();
	~Floor();
};

