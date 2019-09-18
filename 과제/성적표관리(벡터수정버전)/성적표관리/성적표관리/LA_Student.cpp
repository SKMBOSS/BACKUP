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
	no = iCurStudent + 1;

	cout << "¿ª»ç : ";
	cin >> history;
}

void LA_Student::PrintLine()
{
	float fSum = kor + eng + math + history;
	float fAvg = fSum / 4;
	cout << no << "\t" << szName << "\t" <<
		kor << "\t" << eng << "\t" <<
		math << "\t" <<"X\t"<<history <<"\t" <<
		fSum << "\t" << fAvg << endl;
}

void LA_Student::LoadStudent(FILE* pFile)
{
	char szBuf[256];
	char XBuf = NULL;
	fscanf(pFile, "%d %s %d %d %d %s %d\n", &no, szBuf,
		&kor, &eng, &math,XBuf, &history);

	szName = szBuf;
}

void LA_Student::SaveStudent(FILE* pFile)
{
	fprintf(pFile, "%d %s %d %d %d X %d\n", no, szName.c_str(),
		kor, eng, math, history);
}