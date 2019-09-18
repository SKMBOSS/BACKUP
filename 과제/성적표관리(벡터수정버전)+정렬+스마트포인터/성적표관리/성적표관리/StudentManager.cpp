#include "StudentManager.h"
#include <iostream>
using namespace std;

StudentManager::StudentManager()
{
	st.reserve(20);
}

StudentManager::~StudentManager()
{
	/*for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		delete *iter;
	}

	st.clear();*/
	//����Ʈ�����Ͷ� �ڵ����� ���ֳ�?
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
			int who = 0;
			fscanf(pFile, "%d ", &who);

			shared_ptr<Student> pNew = nullptr;

			if (who == 0)
				pNew = make_shared<LA_Student>();
			else if (who == 1)
				pNew = make_shared<NS_Student>();
		
			//Student* pNew = new Student();
			pNew->LoadStudent(pFile);
			st.push_back(pNew);
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

void StudentManager::InputStudent()
{
	int who = 0;

	cout << "1.�̰� 2.����" << endl;
	cin >> who;

	shared_ptr<Student> pNew =nullptr;

	if (who == NS)
		pNew = make_shared<NS_Student>();
	else if(who == LA)
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
		(*iter)->PrintLine();
	}
	
}

void StudentManager::SaveFile()
{
	FILE* pFile = fopen("save.txt", "w");
	fprintf(pFile, "%d\n", st.size());
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		(*iter)->SaveStudent(pFile);
	}
	fclose(pFile);
}

void StudentManager::Sort()
{
	int sortHow = 0;
	int sortMethod = 0;
	cout << "1.��ϼ� 2.��� 3.����" << endl;
	cin >> sortHow;
	cout << "1.�������� 2.��������" << endl;
	cin >> sortMethod;

	if (sortHow == 1 && sortMethod == 1)
	{
		sort(st.begin(), st.end(), [](shared_ptr<Student> left, shared_ptr<Student> right)
			->bool {return left->GetNo() < right->GetNo(); });
	}

	else if (sortHow == 1 && sortMethod == 2)
	{
		sort(st.begin(), st.end(), [](shared_ptr<Student> left, shared_ptr<Student> right)
			->bool {return left->GetNo() > right->GetNo(); });
	}

	else if (sortHow == 2 && sortMethod == 1)
	{
		sort(st.begin(), st.end(), [](shared_ptr<Student> left, shared_ptr<Student> right)
			->bool {return left->GetSum() < right->GetSum(); });
	}

	else if (sortHow == 2 && sortMethod == 2)
	{
		sort(st.begin(), st.end(), [](shared_ptr<Student> left, shared_ptr<Student> right)
			->bool {return left->GetSum() > right->GetSum(); });
	}

	else if (sortHow == 3 && sortMethod == 1)
	{
		sort(st.begin(), st.end(), [](shared_ptr<Student> left, shared_ptr<Student> right)
			->bool {return left->GetKor() < right->GetKor(); });
	}

	else if (sortHow == 3 && sortMethod == 2)
	{
		sort(st.begin(), st.end(), [](shared_ptr<Student> left, shared_ptr<Student> right)
			->bool {return left->GetKor() > right->GetKor(); });
	}

}
