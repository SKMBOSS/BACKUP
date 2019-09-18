#include "StudentManager.h"
#include <iostream>
using namespace std;

StudentManager::StudentManager()
{
	st.reserve(20);
}

StudentManager::~StudentManager()
{
	/*
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		delete *iter;
	}

	st.clear();
	*/
}

void StudentManager::LoadFile()
{
	FILE* pFile = fopen("save.txt", "r");
	if (pFile != nullptr)
	{
		int iCount = 0;
		fscanf(pFile, "%d\n", &iCount);
		for (int i = 0; i < iCount; i++)
		{
			Student* pNew = new Student();

			pNew->LoadStudent(pFile);
			st.push_back(make_shared<Student>(pNew)); 
		}
		fclose(pFile);
	}
}

void StudentManager::PrintMenu()
{
	cout << "1.�Է�" << endl;
	cout << "2.���" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
}

void StudentManager::SelectStudent()
{
	cout << "1.�̰� 2.����" << endl;
	cin >> who;
}

void StudentManager::InputStudent()
{
	shared_ptr<Student> pNew = nullptr;

	if (who == NS)
		pNew =  make_shared<NS_Student>();
	else if (who == LA)
		pNew = make_shared<LA_Student>();

	pNew->InputLine(st.size());
	st.push_back(pNew);
}

void StudentManager::OutputStudent()
{
	cout << "��ȣ\t�̸�\t����\t����\t����\t����2\t����\t����\t���" << endl;
	//vector<Student*>::iterator
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		//(*iter)->PrintLine();
		//����켱���� �������� ������
		(*iter)->PrintLine();
	}
}

void StudentManager::SaveFile()
{
	FILE* pFile = fopen("save.txt", "w");
	fprintf(pFile, "%d\n", st.size());
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		//fprintf(pFile, "%d ", who);
		(*iter)->SaveStudent(pFile);
	}
	fclose(pFile);
}

void StudentManager::SelectSort()
{
	cout << "1.���� 2.���" << endl;
	cin >> s;
}

void StudentManager::Sort()
{
	//sort(st.begin(), st.end(), less< Student>());
}