#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory>
#include "TestClass.h"
using namespace std;

int main()
{
	//auto_ptr<TestClass>(); <<-���������;;; �ִٶ�°ɾ���

	unique_ptr<TestClass> uptr(new TestClass()); // �ϳ��������ϰ������, ����Ǹ�ȵǴ¾�, ���絵�ȵ�, ���縦�ϰ������ ��������� �Լ��� �ѱ���
	unique_ptr<TestClass> uptr2 = move(uptr); //�������� ������Ű�°��� ������Ű�� uptr�� null��

	//���� �迭�� ������;;;;;
	//�迭�� �Ⱦ������� ����־���ؼ� �Ⱦ�

	//shared_ptr<TestClass> sptrl(new TestClass());
	vector<shared_ptr<TestClass>> vec;
	vec.push_back(make_shared<TestClass>());

	shared_ptr<TestClass> sptr1 = make_shared<TestClass>();
	shared_ptr<TestClass> spter2 = sptr1;
	

	weak_ptr<TestClass> wptr1 = sptr1;
	wptr1.lock()->a;
	cout << sptr1.use_count() << endl;

	//�޸��� ������ å���� ����������
	//�Ŵ����� ������ ���� ������
	//new�� delete�� ���������� �̷������ ����
	//���⸸�ҰŰ� �Ҵ����� �Ű澲���ʰٴ� -> weak_ptr

	system("pause");
	return 0;
}
