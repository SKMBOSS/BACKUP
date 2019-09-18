//학생 최대수 3명
//성적표
//1. 입력
//2. 출력
//3. 종료
//
//1 입력 이름 국 영 수
//2 번호 이름 국 영 수 평균 총점 (탭 활용 \ㅅ)

#pragma once

#include <iostream>
#include <string>

using namespace std;

class GRADE
{
private :
	string strName;
	int kor;
	int eng;
	int math;

public:
	GRADE();
	~GRADE();
	void PrintGrade();
	void InputData(string _strName, int _kor, int _eng, int _math);

	static int no;

};

