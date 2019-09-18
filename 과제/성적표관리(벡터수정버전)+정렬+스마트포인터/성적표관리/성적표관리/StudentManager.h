#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "LA_Student.h"
#include "NS_Student.h"
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

enum SELECT
{
	NO,
	NS,
	LA
};

class StudentManager
{
private:
	vector<shared_ptr<Student>> st;
	//vector<Student*> st;
public:
	void LoadFile();
	void InputStudent();
	void OutputStudent();
	void SaveFile();
	void PrintMenu();
	void Sort();

	StudentManager();
	~StudentManager();
};

