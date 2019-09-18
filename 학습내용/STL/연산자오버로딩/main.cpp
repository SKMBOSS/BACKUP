#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyString.h"
using namespace std;

struct FuncObject
{
public:
	void operator() (int arg) const
	{
		cout << "정수 : " << arg << endl;
	}
};

void Print1(int arg)
{
	cout << "정수 : " << arg << endl;
}

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}

	bool operator==(const Point& arg) const
	{
		return x == arg.x && y == arg.y ? true : false;
	}

	bool operator!=(const Point& arg) const
	{
		return !(*this == arg);
	}

	int operator[] (int idx) const
	{
		if (idx == 0)
			return x;
		else if (idx == 1)
			return y;
		else
			throw "이럴 수는 없는거야!";
	}

	operator int() const
	{
		return x;
	}

	int GetX() const{ return x; }
	int GetY() const{ return y; }
	void setX(int _x){ x = _x;}
	void setY(int _y){ y = _y;}
	void Print() const { cout << x << ',' << y << endl; }
};

const Point operator-(const Point& argL, const Point& argR)
{
	return Point(argL.GetX() - argR.GetX(), argL.GetY() - argR.GetY());
}

class PointPtr
{
	Point *ptr;

public:
	PointPtr(Point *p) :ptr(p) {}
	~PointPtr()
	{
		delete ptr;
	}
	Point* operator->() const
	{
		return ptr;
	}
	Point& operator*() const
	{
		return *ptr;
	}
};

class Array
{
	int *arr;
	int size;
	int capacity;

public:
	Array(int cap = 100) :arr(0), size(0), capacity(cap)
	{
		arr = new int[capacity];
	}
	~Array()
	{
		delete[] arr;
	}
	
	void Add(int data)
	{
		if (size < capacity)
			arr[size++] = data;
	}

	int Size() const
	{
		return size;
	}

	int operator[] (int idx) const
	{
		return arr[idx];
	}

	int operator[] (int idx)
	{
		return arr[idx];
	}
};

class A
{};

class B
{
public:
	operator A()
	{
		cout << "operator A() 호출" << endl;
		return A();
	}

	operator int()
	{
		cout << "operator int() 호출" << endl;
		return 10;
	}

	operator double()
	{
		cout << "operator double() 호출" << endl;
		return 5.5;
	}
};

int main()
{
	//const Point p1(2, 3);
	//Point p2(2, 3);

	//p1.Print();
	//p2.Print();

	//cout << "p1: " << p1.GetX() << ',' << p1.GetY() << endl;
	//cout << "p2: " << p2.GetX() << ',' << p2.GetY() << endl << endl;

	//cout << "==연산자오버로딩" << endl;
	//if (p1 == p2)
	//	cout << "p1 == p2" << endl<<endl;
	
	//cout << "함수호출연산자오버로딩" <<endl;
	//void(*Print2) (int) = Print1;
	//FuncObject Print3;

	//Print1(10);
	//Print2(10);

	//cout << endl << "[]연산자오버로딩" << endl;
	//Point pt(1, 2);
	//pt.Print();
	//cout << pt[0] << ',' << pt[1] << endl;

	//cout << endl << "MY ARRAY" << endl;
	//Array ar(10);
	//ar.Add(10);
	//ar.Add(20);
	//ar.Add(30);

	//cout << ar[0] << endl;
	//cout << endl;

	//const Array& ar2 = ar;
	//cout << ar2[0] << endl;
	//cout << endl;

	//ar[0] = 100;
	//ar2[0] = 100  에러

	//cout << "MY POINTPTR" << endl;
	//Point* p1 = new Point(2, 3);
	//PointPtr p2 = new Point(5, 5);

	//p1->Print();
	//p2->Print();
	//cout << endl;

	//(*p1).Print();
	//(*p2).Print();

	//delete p1;

	/*cout << "예제 1-26" << endl;
	A a;
	int n;
	double d;

	B b;
	a = b;
	n = b;
	d = b;

	cout << endl;
	a = b.operator A();
	n = b.operator int();
	d = b.operator double();*/

	//cout << "예제 1-27" << endl;
	//int n = 10;

	//Point pt(2, 3);
	//n = pt; //pt.operatro int() 암시적호출
	//cout << n << endl;
	
	cout << "문제 4" << endl;
	const char* sz = "Hi~!";
	MyString s("Hello!");

	//const char* sz = s;
	//s = sz;
	cout << sz << endl;

	system("pause");
	return 0;
}
