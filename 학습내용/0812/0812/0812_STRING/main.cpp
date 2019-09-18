#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::string str;
	str.reserve(256); //예약

	str = "zznagjungsu";

	str.find('c',0); // 문자열찾기
	str.c_str(); //

	system("pause");
	return 0;
}