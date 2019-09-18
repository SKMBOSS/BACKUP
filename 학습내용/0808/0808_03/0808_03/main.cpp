#include <iostream>

using namespace std;

int Factorial(int num)
{
	if (num == 1) 
		return 1;

	return 
		num * Factorial(num - 1);
}

void print()
{

}

enum CLASS
{
	WARRIOR =1 >> 1,
	ARCHOR = 1 >> 2,
	WIZARD = 1 >>3
};

void addNum(int& a)
{
	a++;
}

struct ST
{
	int a : 4; //4바이트짜리를 4비트만 쓰겟다
};

int main()
{
	
	void(*pfun) (); //함수포인터 선언부
	pfun = &print; // 함수포인터 정의?
	(*pfun) ();

	system("pause");
	return 0;
}