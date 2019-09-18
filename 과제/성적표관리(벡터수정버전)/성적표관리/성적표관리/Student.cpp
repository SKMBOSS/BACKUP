#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
}

Student::~Student()
{
}

void Student::InputLine(const int iCurStudent)
{
	no = iCurStudent + 1;
	cout << "�̸� : ";
	cin >> szName;
	cout << "���� : ";
	cin >> kor;
	cout << "���� : ";
	cin >> eng;
	cout << "���� : " ;
	cin >> math;
}

void Student::PrintLine()
{
	float fSum = kor + eng + math;
	float fAvg = fSum / 3;
	cout << no << "\t" << szName << "\t" <<
		kor << "\t" << eng << "\t" <<
		math << "\t" <<
		fSum << "\t" << fAvg << endl;
}

void Student::LoadStudent(FILE* pFile)
{
	char szBuf[256];
	fscanf(pFile, "%d %s %d %d %d\n", &no, szBuf,
		&kor, &eng, &math);

	szName = szBuf;
}

void Student::SaveStudent(FILE* pFile)
{
	fprintf(pFile, "%d %s %d %d %d\n", no, szName.c_str(),
		kor, eng, math);
}