#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include "GRADE.h"

using namespace std;

void showMenu();

int main()
{
	GRADE myGrade[10];
	string strName;
	int kor = 0;
	int eng = 0;
	int math = 0;


	while(true)
	{ 
		system("cls");
		showMenu();

		char input = _getch();

		if (input == '1')
		{
			system("cls");
			cout << "�̸� ���� ���� ���� : ";
			cin >> strName >> kor >> eng >> math;
			myGrade[myGrade->no].InputData(strName, kor, eng, math);
		}

		else if (input == '2')
		{
			system("cls");
			for (int i = 0; i < myGrade->no; i++)
				myGrade[i].PrintGrade();

			system("pause");
		}

		else if (input == '3')
			break;
	}

	system("pause");
	return 0;
}

void showMenu()
{
	cout << "<����ǥ>" << endl;
	cout << "1.�Է�" << endl;
	cout << "2.���" << endl;
	cout << "3.����" << endl;
}