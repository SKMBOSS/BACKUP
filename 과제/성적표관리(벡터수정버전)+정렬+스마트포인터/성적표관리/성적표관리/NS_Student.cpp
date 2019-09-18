#include "NS_Student.h"
#include <iostream>
using namespace std;

NS_Student::NS_Student()
{
}


NS_Student::~NS_Student()
{
}

void NS_Student::InputLine(const int iCurStudent)
{
	Student::InputLine(iCurStudent);

	cout << "수학2 : ";
	cin >> math2;
}

float NS_Student::GetSum()
{
	return kor + eng + math + math2;
}

void NS_Student::PrintLine()
{
	float fSum = GetSum();
	float fAvg = fSum / 4;
	cout << no << "\t" << szName << "\t" <<
		kor << "\t" << eng << "\t" <<
		math << "\t" << math2 << "\t0\t" <<
		fSum << "\t" << fAvg << endl;
}

void NS_Student::LoadStudent(FILE* pFile)
{
	char szBuf[256];
	char XBuf[256];//하 나란 병신...
	fscanf(pFile, "%d %s %d %d %d %d %s\n", &no, szBuf,
		&kor, &eng, &math, &math2, XBuf);

	szName = szBuf;
}

void NS_Student::SaveStudent(FILE* pFile)
{
	fprintf(pFile, "1 %d %s %d %d %d %d 0\n", no, szName.c_str(),
		kor, eng, math, math2);
}