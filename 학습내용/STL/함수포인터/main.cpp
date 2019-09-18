/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void Print(int n)
{
	cout << "전역 함수 :  " << n << endl;
}

namespace A
{
	void Print(int n)
	{
		cout << "namespace A 전역함수 :  " << n << endl;
	}
}

void Print()
{
	cout << "정적 함수 Print()" << endl;
}

class Point
{
	int x;
	int y;

public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "테스트 정수 : " << n << endl; }
};

int main()
{
	/*
	cout << "예제 2-2 함수 포인터 선언과 사용" << endl;
	//void Print(int n) 의함수 포인터 선언
	void(*pf) (int);
	//함수의 이름은 함수의 시작 주소
	pf = Print;

	Print(10); // 1.함수 호출
	pf(10);    // 2.포인터를 이용한 함수 호출, 첫번째 방법
	(*pf)(10); // 3.포인터를 이용한 함수 호출, 두번째 방법

	cout << endl;
	cout << Print << endl;
	cout << pf << endl;
	cout << *pf << endl;
	

	/*
	cout << "예제 2-3 c++ 함수호출 방식" << endl;
	Point pt;
	Point* p = &pt;

	Print();
	pt.Print();
	p->Print();

	system("pause");
	

	/*
	cout << "예제 2-4 정적 함수 포인터" << endl;
	void(*pf) (int);

	Print(10);
	A::Print(10);
	Point::Print(10);

	pf = Print;
	pf(10);
	pf = A::Print;
	pf(10);
	pf = Point::Print;
	pf(10);
	

	cout << "예제 2-5 Point 클래스의 멤버 함수 포인터" << endl;
	Point pt(2, 3);
	Point *p = &pt;

	void (Point::*pf1) () const;
	pf1 = &Point::Print;

	void (Point::*pf2) (int);
	pf2 = &Point::PrintInt;

	pt.Print();
	pt.PrintInt(10);
	cout << endl;

	system("pause");
	return 0;
}
*/