/*class 문법*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "STUDENT2.h"

using namespace std;

class POINT
{
public :
	int x;
	int y;

	void AddPoint(POINT ptOther)
	{
		x += ptOther.x;
	}

	static void AddPoint(POINT ptSour, POINT ptOther)
	{
		ptSour.x += ptOther.x;
	}
};


int main()
{
	STUDENT2* st = new STUDENT2(10); // 생성자

	cout << "main" << endl;

	delete st;

	system("pause");
	return 0;
}