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
	int a : 4; //4����Ʈ¥���� 4��Ʈ�� ���ٴ�
};

int main()
{
	
	void(*pfun) (); //�Լ������� �����
	pfun = &print; // �Լ������� ����?
	(*pfun) ();

	system("pause");
	return 0;
}