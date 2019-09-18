#include "GRADE.h"

int GRADE::no = 0;

GRADE::GRADE()
{
	strName = "";
	kor = 0;
	eng = 0;
	math = 0;
}


GRADE::~GRADE()
{
}

void GRADE::InputData(string _strName, int _kor, int _eng, int _math)
{
	strName = _strName;
	kor = _kor;
	eng = _eng;
	math = _math;
	no++;
}

void GRADE::PrintGrade()
{
	cout << "번호\t이름\t국어\t영어\t수학\t평균\t총점" << endl;
	cout << no << "\t";
	cout << strName.c_str() << "\t";
	cout << kor << "\t";
	cout << eng << "\t";
	cout << math << "\t";	
	cout << (math + kor + eng) / 3 << "\t";
	cout << (math + kor + eng) << endl;
}