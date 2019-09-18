#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>

using namespace std;

class parent
{
protected:
	int a = 0;
public:
	virtual void print() = 0;
};

class child1 : public parent
{
private:
	int c = 10;
public :
	virtual void print()
	{
		cout << c << endl;
	}
};

class child2 : public parent
{
private:
	int c = 10;
public:
	virtual void print()
	{
		cout << a << endl;
	}

	void printAll()
	{
		cout << "printALL" << endl;
	}
};

using namespace std;

int main()
{
	vector<parent*> vec;

	vec.push_back(new child1());
	vec.push_back(new child2());

	for (auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		//child2* pch = (child2*)(*iter);
		child2* pch = dynamic_cast<child2*>(*iter);
		if (pch)
			pch->printAll();
		(*iter)->print();
	}

	//vec[0]->print();
	//vec[1]->print();

	system("pause");
	return 0;
}