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

	cout << "¼öÇÐ2 : ";
	cin >> math2;
}

void NS_Student::PrintLine()
{
	float fSum = kor + eng + math + math2;
	float fAvg = fSum / 4;
	cout << no << "\t" << szName << "\t" <<
		kor << "\t" << eng << "\t" <<
		math << "\t" << math2 << "\tX\t" <<
		fSum << "\t" << fAvg << endl;
}

void NS_Student::LoadStudent(FILE* pFile)
{
	char szBuf[256];
	char XBuf=NULL;
	fscanf(pFile, "%d %s %d %d %d %d %s\n", &no, szBuf,
		&kor, &eng, &math, &math2, XBuf);

	szName = szBuf;
}

void NS_Student::SaveStudent(FILE* pFile)
{
	fprintf(pFile, "%d %s %d %d %d %d X\n", no, szName.c_str(),
		kor, eng, math, math2);
}