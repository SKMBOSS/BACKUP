#include "LA_Student.h"
#include <iostream>
using namespace std;

LA_Student::LA_Student()
{
}

LA_Student::~LA_Student()
{
}

void LA_Student::InputLine(const int iCurStudent)
{
	Student::InputLine(iCurStudent);

	cout << "¿ª»ç : ";
	cin >> history;
}

float LA_Student::GetSum()
{
	return kor + eng + math + history;
}

void LA_Student::PrintLine()
{
	float fSum = GetSum();
	float fAvg = fSum / 4;

	cout << no << "\t" << szName << "\t" <<
		kor << "\t" << eng << "\t" <<
		math << "\t" <<"0\t"<<history <<"\t" <<
		fSum << "\t" << fAvg << endl;
}

void LA_Student::LoadStudent(FILE* pFile)
{
	char szBuf[256];
	char XBuf[256];
	fscanf(pFile, "%d %s %d %d %d %s %d\n", &no, szBuf,
		&kor, &eng, &math,XBuf, &history);

	szName = szBuf;
}

void LA_Student::SaveStudent(FILE* pFile)
{
	fprintf(pFile, "0 %d %s %d %d %d 0 %d\n", no, szName.c_str(),
		kor, eng, math, history);
}