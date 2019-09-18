#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

template<typename T>
struct Plus
{
	T operator() (const T& left, const T& right)
	{
		return left + right;
	}
};

void Print(int n)
{
	cout << n << " ";
}

bool Pred(int left, int right)
{
	return abs(right - left) < 10;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	cout<< accuma

	system("pause");
	return 0;
}
