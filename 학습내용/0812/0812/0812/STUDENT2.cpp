#define _CRT_SECURE_NO_WARNINGS

#include "STUDENT2.h"
using namespace std;

int STUDENT2::aaa = 0;

STUDENT2::STUDENT2(int no)
{
	cout << "생성자 호출" << endl;
	no = 0;
	pOut = new char[256];
	memset(szName, 0, 256);
}

STUDENT2::~STUDENT2()
{
	cout << "소멸자 호출" << endl;
}

STUDENT2::STUDENT2(const STUDENT2 &other)
{
	no = other.no;
	pOut = new char[256]; //deep copy
	strcpy(pOut, other.pOut);
}

void STUDENT2::print()
{
	//this->no;
	cout << "print()" << endl;
}