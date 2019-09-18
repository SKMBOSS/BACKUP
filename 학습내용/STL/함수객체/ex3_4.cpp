/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

/////////////클라이언트/////////////
struct Functor1
{
	void operator() (int n)
	{
		cout << n << " ";
	}
};

struct Functor2
{
	void operator() (int n)
	{
		cout << n*n << " ";
	}
};

struct Functor3
{
	void operator() (int n)
	{
		cout << "정수 : " << n << endl;
	}
};


int main()
{
	int arr[5] = { 10,20,30,40,50 };

	for_each(arr, arr + 5, Functor1());
	cout << endl;

	for_each(arr, arr + 5, Functor2());
	cout << endl;

	for_each(arr, arr + 5, Functor3());
	cout << endl;

	system("pause");
	return 0;
}
*/