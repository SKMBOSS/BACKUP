/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	ofstream outfile("a.txt", ios::in);
	outfile << "zzangjungsu" << endl;
	outfile.close();

	char szBuf[256];
	ifstream inFile("a.txt");
	//inFile.getline();
	inFile >> szBuf;
	cout << szBuf;

	//iostream input

	system("pause");
	return 0;
}
*/