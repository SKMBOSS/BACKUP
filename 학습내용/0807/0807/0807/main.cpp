#include <iostream>
#include <conio.h>
using namespace std;

#define MAX_STUDENT_NO 3

void showMenu();

void my_strcpy(char* szDest, const char* szSource);

int my_strlen();
char* my_strstr(char * const _String, char const * const _SubString);

//����ü
struct student
{
	int no;
	char szName[256];
	int kor;
	int eng;
	int math;
};
//�л� �ִ�� 3��
//����ǥ
//1. �Է�
//2. ���
//3. ����
//
//1 �Է� �̸� �� �� ��
//2 ��ȣ �̸� �� �� �� ��� ���� (�� Ȱ�� \��)

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

		//�Է�
		if (input == '1')
		{
			system("cls");
			cout << "�̸� ���� ���� ���� : ";

			if (studentNo < MAX_STUDENT_NO)
			{
				st[studentNo].no = studentNo + 1;

				cin >> st[studentNo].szName >> st[studentNo].kor >> st[studentNo].eng >> st[studentNo].math;
			
				studentNo++;

				continue;
			}
			
			else
				cout << "�л����� �ʰ��Ͽ����ϴ�." << endl;

		}
		//���
		else if (input == '2')
		{
			system("cls");

			cout << "��ȣ\t�̸�\t����\t����\t����\t���\t����" << endl;

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
		//����
		else if (input == '3')
		{
			break;
		}

	}
	*/
	
	char szName[256] = "LeeJungSu";

	//my_strcpy(szName, "zxzxzx"); 
	cout << szName << endl;

	int len = strlen(szName); //����
	//strcat(szName, "zzang"); // ����

	char* szOut = my_strstr(szName, "Jung");

	cout << szOut << endl;


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