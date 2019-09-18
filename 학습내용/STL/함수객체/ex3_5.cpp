#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

bool Pred_less(int a, int b)
{
	return a < b;
}

struct Less
{
	bool operator() (int a, int b)
	{
		return a < b;
	}
};


int main()
{
	Less l;
	
	cout << Pred_less(10, 20) << endl;
	cout << Pred_less(20, 10) << endl;
	cout << endl;
	cout << l(10, 20) << endl;
	cout << l(20, 10) << endl;
	cout << Less() (10, 20) << endl;
	cout << Less() (20, 10) << endl;
	cout << endl;
	cout << l.operator()(10, 20) << endl;
	cout << Less().operator()(10, 10) << endl;

	system("pause");
	return 0;
}