//�л� �ִ�� 3��
//����ǥ
//1. �Է�
//2. ���
//3. ����
//
//1 �Է� �̸� �� �� ��
//2 ��ȣ �̸� �� �� �� ��� ���� (�� Ȱ�� \��)

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

