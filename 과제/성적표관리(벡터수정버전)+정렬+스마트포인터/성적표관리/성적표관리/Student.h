#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
using namespace std;

class Student
{
protected:
	int no;
	string szName;
	int kor;
	int eng;
	int math;
	
public:
	virtual float GetSum() = 0;
	virtual void LoadStudent(FILE* pFile);
	virtual void SaveStudent(FILE* pFile);
	virtual void PrintLine();
	virtual void InputLine(const int iCurStudent);

	inline 	virtual int GetKor()
	{
		return kor;
	}

	inline 	virtual int GetNo()
	{
		return no;
	}

	Student();
	virtual ~Student();
};

