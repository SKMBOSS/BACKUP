#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class POINT
{
public:
	int x;
	int y;

	POINT operator+(POINT& right)
	{
		x += right.x;
		y += right.y;
		return *this;
	}
};

int main()
{
	POINT a, b;
	POINT c = a + b;


	system("pause");
	return 0;
}