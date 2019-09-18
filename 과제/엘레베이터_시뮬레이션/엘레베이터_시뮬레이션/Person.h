#pragma once
class Person
{
private:
	int destFloor;
	int weight;
public:
	inline Person(int _destFloor = 0, int _weight = 30)
	{
		destFloor = _destFloor;
		weight = _weight;
	}
	inline int GetDestFloor()
	{
		return destFloor;
	}
	inline int GetWeight()
	{
		return weight;
	}

	Person();
	~Person();
};

