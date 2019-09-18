//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//
//using namespace std;
//
//class Point
//{
//	int x;
//	int y;
//
//public:
//	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
//	void Print() const { cout << x << ',' << y << endl; }
//	//void PrintInt(int n) { cout << "테스트 정수 : " << n << endl; }
//};
//
////일반화 함수 템플릿
//template<typename T>
//void Print(T a)
//{
//	cout << a << endl;
//}
//
////특수화 함수 템플릿
//template<>
//void Print(Point a)
//{
//	cout << "Print 특수화 버전 : ";
//	a.Print();
//}
//
//int main()
//{
//	int n = 10;
//	double d = 2.5;
//	Point pt(2, 3);
//
//	Print(n);
//	Print(d);
//	Print(pt);
//
//	system("pause");
//	return 0;
//}