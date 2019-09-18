
#include <iostream>
#include <conio.h>
#include <fstream>

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
	
	student st[MAX_STUDENT_NO];
	int studentNo = 0;

	ofstream outFile("mygrade.txt", std::ios_base::out | std::ios_base::app);
	ifstream inFile("mygrade.txt");
	char szBuf[256];

		

	while (true)
	{
		system("cls");
		cout << "��ȣ\t�̸�\t����\t����\t����\t���\t����" << endl;
		while (!inFile.eof()) {

			inFile.getline(szBuf, 100);

			cout << szBuf << endl;

		}
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

				outFile <<"\n"<<studentNo << "\t" << st[studentNo].szName <<" "<<st[studentNo].kor << "\t" << st[studentNo].eng << "\t" << st[studentNo].math;

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
	
	outFile.close();
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
