#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "myData.h"

using namespace std;

void ReadData(vector<MYDATA> &info);
void PrintInfo(vector<MYDATA> info);

int main()
{
	vector<MYDATA> info;

	ReadData(info);
	PrintInfo(info);
		
	//cout << info.size();
	system("pause");
	return 0;
}

void ReadData(vector<MYDATA> &info)
{
	ifstream inFile("myData.csv");

	string inLine;
	string buf;

	for (int i = 0; i < 3; i++)
		getline(inFile, inLine);

	while (!inFile.eof())
	{
		MYDATA temp;

		getline(inFile, buf, ',');
		temp.index = atoi(buf.c_str());

		getline(inFile, buf, ',');
		strcpy(temp.name, buf.c_str());

		getline(inFile, buf, ',');
		temp.attack = atoi(buf.c_str());

		getline(inFile, buf, ',');
		temp.defense = atoi(buf.c_str());

		getline(inFile, buf, ',');
		temp.hp = atoi(buf.c_str());

		getline(inFile, buf);
		temp.mp = atoi(buf.c_str());

		//getline(inFile, buf, '\n');

		info.push_back(temp);
	}
}

void PrintInfo(vector<MYDATA> info)
{
	for (int i = 0; i < info.size(); i++)
	{
		cout << "info[" << i << "] ->>> ";
		cout << "index : " << info[i].index << " ";
		cout << " name : " << info[i].name << " ";
		cout << "attack : " << info[i].attack << " ";
		cout << "defense : " << info[i].defense << " ";
		cout << "   hp : " << info[i].hp << " ";
		cout << "   mp : " << info[i].mp << endl;
	}
}