#pragma once
#include "Student.h"

class NS_Student : public Student
{
private:
	int math2;
public:
	virtual void PrintLine();
	virtual void InputLine(const int iCurStudent);
	virtual void LoadStudent(FILE* pFile);
	virtual void SaveStudent(FILE* pFile);
	virtual float GetSum();

public:
	NS_Student();
	~NS_Student();
};

