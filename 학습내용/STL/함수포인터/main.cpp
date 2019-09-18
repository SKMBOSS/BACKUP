/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void Print(int n)
{
	cout << "���� �Լ� :  " << n << endl;
}

namespace A
{
	void Print(int n)
	{
		cout << "namespace A �����Լ� :  " << n << endl;
	}
}

void Print()
{
	cout << "���� �Լ� Print()" << endl;
}

class Point
{
	int x;
	int y;

public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "�׽�Ʈ ���� : " << n << endl; }
};

int main()
{
	/*
	cout << "���� 2-2 �Լ� ������ ����� ���" << endl;
	//void Print(int n) ���Լ� ������ ����
	void(*pf) (int);
	//�Լ��� �̸��� �Լ��� ���� �ּ�
	pf = Print;

	Print(10); // 1.�Լ� ȣ��
	pf(10);    // 2.�����͸� �̿��� �Լ� ȣ��, ù��° ���
	(*pf)(10); // 3.�����͸� �̿��� �Լ� ȣ��, �ι�° ���

	cout << endl;
	cout << Print << endl;
	cout << pf << endl;
	cout << *pf << endl;
	

	/*
	cout << "���� 2-3 c++ �Լ�ȣ�� ���" << endl;
	Point pt;
	Point* p = &pt;

	Print();
	pt.Print();
	p->Print();

	system("pause");
	

	/*
	cout << "���� 2-4 ���� �Լ� ������" << endl;
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
	

	cout << "���� 2-5 Point Ŭ������ ��� �Լ� ������" << endl;
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