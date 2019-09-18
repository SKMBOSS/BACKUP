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
	cout << "1.입력" << endl;
	cout << "2.출력" << endl;
	cout << "3.저장" << endl;
	cout << "4.정렬" << endl;
	cout << "5.종료" << endl;
}

void StudentManager::SelectStudent()
{
	cout << "1.이과 2.문과" << endl;
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
	cout << "번호\t이름\t국어\t영어\t수학\t수학2\t역사\t총점\t평균" << endl;
	//vector<Student*>::iterator
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		//(*iter)->PrintLine();
		//연산우선순위 생각하자 빠가야
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
	cout << "1.국어 2.평균" << endl;
	cin >> s;
}

void StudentManager::Sort()
{
	//sort(st.begin(), st.end(), less< Student>());
}