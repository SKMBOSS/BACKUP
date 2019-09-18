#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile("myData.csv");
	ofstream outFile("myData.h");

	string inLine;

	string typeName;
	int tCount = 0;

	string varName;
	int vCount = 0;

	string remark;
	int rCount = 0;
	
	getline(inFile, varName);
	getline(inFile, typeName);
	getline(inFile, remark);

	outFile << "struct MYDATA";
	outFile << "\n{\n";

	while (true)
	{
		outFile << "\t";
		while (typeName[tCount] != ',')
		{
			if (tCount == typeName.length())
				break;

			outFile << typeName[tCount++];
		}
		outFile << " ";

		while (varName[vCount] != ',')
		{
			if (vCount == varName.length())
				break;

			outFile << varName[vCount++];
		}
		outFile << "; //";

		while (remark[rCount] != ',')
		{
			if (rCount == remark.length())
				break;

			outFile << remark[rCount++];
		}
		tCount++, vCount++, rCount++;

		if (tCount >= typeName.length())
			break;

		outFile << "\n";

	}
	outFile << "\n};";
	
	system("pause");
	return 0;
}