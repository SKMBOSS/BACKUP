#include <iostream>
#include <conio.h>
using namespace std;

#define MAX_STUDENT_NO 3

void showMenu();

void my_strcpy(char* szDest, const char* szSource);

int my_strlen();
char* my_strstr(char * const _String, char const * const _SubString);

//구조체
struct student
{
	int no;
	char szName[256];
	int kor;
	int eng;
	int math;
};
//학생 최대수 3명
//성적표
//1. 입력
//2. 출력
//3. 종료
//
//1 입력 이름 국 영 수
//2 번호 이름 국 영 수 평균 총점 (탭 활용 \ㅅ)

int main()
{
	/*
	student st[MAX_STUDENT_NO];
	int studentNo = 0;

	while (true)
	{
		system("cls");
		showMenu();

		char input = _getch();

		//입력
		if (input == '1')
		{
			system("cls");
			cout << "이름 국어 영어 수학 : ";

			if (studentNo < MAX_STUDENT_NO)
			{
				st[studentNo].no = studentNo + 1;

				cin >> st[studentNo].szName >> st[studentNo].kor >> st[studentNo].eng >> st[studentNo].math;
			
				studentNo++;

				continue;
			}
			
			else
				cout << "학생수를 초과하였습니다." << endl;

		}
		//출력
		else if (input == '2')
		{
			system("cls");

			cout << "번호\t이름\t국어\t영어\t수학\t평균\t총점" << endl;

			for (int i = 0; i < studentNo; i++)
			{
				cout << st[i].no << "\t";
				cout << st[i].szName << "\t";
				cout << st[i].kor << "\t";
				cout << st[i].eng << "\t";
				cout << st[i].math << "\t";
				cout << (st[i].math + st[i].kor + st[i].eng) / 3 << "\t";
				cout<< (st[i].math + st[i].kor + st[i].eng) << endl;
			}
			system("pause");
		}
		//종료
		else if (input == '3')
		{
			break;
		}

	}
	*/
	
	char szName[256] = "LeeJungSu";

	//my_strcpy(szName, "zxzxzx"); 
	cout << szName << endl;

	int len = strlen(szName); //구현
	//strcat(szName, "zzang"); // 구현

	char* szOut = my_strstr(szName, "Jung");

	cout << szOut << endl;


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

void my_strcpy(char* szDest, const char* szSource)
{
	int i = 0;

	while (szSource[i] != NULL)
	{
		szDest[i] = szSource[i++];
	}

	szDest[i] = NULL;
}

char* my_strstr(char * const _String, char const * const _SubString)
{
	char result[] = "";

	int temp=0;

	int i = 0;
	int j = 0;

	int count = 0;

	while (count != strlen(_SubString) )
	{
		if (_String[i] == _SubString[j])
		{
			if (count == 0)
				temp = i;

			count++;
			j++;
		}

		else
		{
			temp = 0;
			count = 0;
			j = 0;
		}
		i++;

		if (i == strlen(_SubString)-1) break;
	}

	int k=0;

	for (int i = temp; i <= strlen(_String); i++)
	{
		result[k++] = _String[i];
	}
	
	return result;
}