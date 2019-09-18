#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
	map<int, int> m;

	m[5] = 100;
	m[3] = 100;
	m[4] = 30;
	m[1] = 40;
	m[7] = 70;
	m[9] = 50;

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "( " << (*iter).first << " " << (*iter).second << ")" << " ";
	cout << endl;

	m[5] = 200;

	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "( " << (*iter).first << " " << (*iter).second << ")" << " ";
	cout << endl;

	system("pause");
	return 0;
}
