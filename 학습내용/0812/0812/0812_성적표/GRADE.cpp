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
	cout << "��ȣ\t�̸�\t����\t����\t����\t���\t����" << endl;
	cout << no << "\t";
	cout << strName.c_str() << "\t";
	cout << kor << "\t";
	cout << eng << "\t";
	cout << math << "\t";	
	cout << (math + kor + eng) / 3 << "\t";
	cout << (math + kor + eng) << endl;
}