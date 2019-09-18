//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//template<typename T>
//class Objectinfo
//{
//	T data;
//public:
//	Objectinfo(const T& d) : data(d) {}
//
//	void Print()
//	{
//		cout << "타입 : " << typeid(data).name() << endl;
//		cout << "크기 : " << sizeof(data) << endl;
//		cout << "값   : " << data << endl;
//		cout << endl;
//	}
//};
//
//int main()
//{
//	Objectinfo<int> d1(10);
//	d1.Print();
//
//	Objectinfo<double> d2(5.5);
//	d2.Print();
//
//	Objectinfo<string> d3("Hello!");
//	d3.Print();
//
//	system("pause");
//	return 0;
//}