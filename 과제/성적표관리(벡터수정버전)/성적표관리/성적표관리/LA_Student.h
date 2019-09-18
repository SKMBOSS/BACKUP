#pragma once
#include "Student.h"

class LA_Student :public Student
{
private:
	int history;
public:
	virtual void PrintLine();
	virtual void InputLine(const int iCurStudent);
	virtual void LoadStudent(FILE* pFile);
	virtual void SaveStudent(FILE* pFile);

	LA_Student();
	~LA_Student();
};

