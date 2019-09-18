#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>

class MyString
{
	char *str;
	int length;

public:

	MyString(const char* _str)
	{

		length = strlen(_str) + 1;
		str = new char[length];
		strcpy(str, _str);
	}
	~MyString();




	operator const char* () const
	{
		return str;
	}
};

