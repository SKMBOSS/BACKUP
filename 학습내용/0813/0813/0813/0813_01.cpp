#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

template <typename T, typename T2>
T sum(T a, T2 b)
{
	return a + b;
}

int main()
{
	vector<int> vc;
	vc.reserve(1024);
	vc.push_back(10);
	vc.push_back(20);
	vc.push_back(30);

	for (vector<int>::iterator iter = vc.begin(); iter != vc.end(); iter++)
	{
		cout << *iter << endl;
	}

	for (auto iter = vc.begin(); iter != vc.end(); iter++)
	{

	}

	for (int i = 0; i < vc.size(); i++)
		cout << vc[i] << endl;


	map<int, string> map;
	pair<int, string> p;
	p.first = 1;
	p.second = "asdasd";
	map.insert(p);

	map.insert(make_pair(1, "asdasd")); //편하게 쓰기가능
 	


	system("pause");
	return 0;
}