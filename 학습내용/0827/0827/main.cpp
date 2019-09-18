#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	cout << "[v.begin(), v.(end)의 원소 개수 : " <<
		distance(v.begin(), v.end()) << endl;
	system("pause");
	return 0;
}
