#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

//////클라이언트//////
void Print1(int n)
{
	cout << n << ' ';
}

void Print2(int n)
{
	cout << n * n << ' ';
}

void Print3(int n)
{
	cout << "정수 : " << n << endl;
}

int main()
{
	int arr[5] = { 10,20,30,40,50 };



	system("pause");
	return 0;
}