#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory>
#include "TestClass.h"
using namespace std;

int main()
{
	//auto_ptr<TestClass>(); <<-옛날방식임;;; 있다라는걸알자

	unique_ptr<TestClass> uptr(new TestClass()); // 하나만존재하고싶은애, 복사되면안되는애, 복사도안됨, 복사를하고싶으면 명시적으로 함수를 넘기면됨
	unique_ptr<TestClass> uptr2 = move(uptr); //소유권을 이전시키는개념 이전시키면 uptr은 null임

	//뭔가 배열로 선언함;;;;;
	//배열을 안쓰는이유 상수넣어야해서 안씀

	//shared_ptr<TestClass> sptrl(new TestClass());
	vector<shared_ptr<TestClass>> vec;
	vec.push_back(make_shared<TestClass>());

	shared_ptr<TestClass> sptr1 = make_shared<TestClass>();
	shared_ptr<TestClass> spter2 = sptr1;
	

	weak_ptr<TestClass> wptr1 = sptr1;
	wptr1.lock()->a;
	cout << sptr1.use_count() << endl;

	//메모리의 해제의 책임을 누가지느냐
	//매니져들 끝날때 보통 해제함
	//new와 delete가 따른곳에서 이루어지면 ㅄ임
	//쓰기만할거고 할당해제 신경쓰지않겟다 -> weak_ptr

	system("pause");
	return 0;
}
