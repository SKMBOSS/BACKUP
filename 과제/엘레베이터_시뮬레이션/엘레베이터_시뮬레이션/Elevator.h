#pragma once
#include "Person.h"
#include <deque>

class Elevator
{
public:
	enum DEST_FLOOR_FOR
	{
		UP,
		DOWN,
		BOTH,
		OFF
	};

private:
	const int MAX_WEIGHT = 600;
	int totalWeight = 0;
	int destFloor = 0;
	DEST_FLOOR_FOR dff = OFF;
	int currentFloor = 0;
	std::deque<Person*> peopleInEv;

public:
	bool isUp = false;
	bool isDown = false;
	void InsertPerson(Person* p);
	void OutPerson();
	void SortPeople();
	void Print();
	void PrintInfo();
	inline bool OverWeight(int _weight)
	{
		if (totalWeight+_weight > MAX_WEIGHT)
			return true;
		else
			return false;
	}
	inline bool Empty()
	{
		return peopleInEv.empty();
	}
	inline Person* GetFrontPerson()
	{
		Person* outPerson = peopleInEv.front();
		return outPerson;
	}
	inline Person* GetBackPerson()
	{
		Person* outPerson = peopleInEv.back();
		return outPerson;
	}
	inline int GetDestFloor()
	{
		return destFloor;
	}
	inline void SetDestFloor(int _destFloor)
	{
		destFloor = _destFloor;
	}
	inline DEST_FLOOR_FOR GetDFF()
	{
		return dff;
	}
	inline void SetDFF(DEST_FLOOR_FOR _dff)
	{
		dff = _dff;
	}
	inline int GetCurrentFloor()
	{
		return currentFloor;
	}
	inline void SetCurrentFloor(int random)
	{
		currentFloor = random;
	}
	inline void UpFloor()
	{
		currentFloor++;
	}
	inline void DownFloor()
	{
		currentFloor--;
	}

	Elevator();
	~Elevator();
};

