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
//	//void PrintInt(int n) { cout << "�׽�Ʈ ���� : " << n << endl; }
//};
//
////�Ϲ�ȭ �Լ� ���ø�
//template<typename T>
//void Print(T a)
//{
//	cout << a << endl;
//}
//
////Ư��ȭ �Լ� ���ø�
//template<>
//void Print(Point a)
//{
//	cout << "Print Ư��ȭ ���� : ";
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