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
			cout << "이름 국어 영어 수학 : ";
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
	cout << "<성적표>" << endl;
	cout << "1.입력" << endl;
	cout << "2.출력" << endl;
	cout << "3.종료" << endl;
}