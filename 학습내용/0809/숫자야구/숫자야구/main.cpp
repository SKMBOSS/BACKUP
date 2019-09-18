#include <iostream>
#include <time.h>

using namespace std;

int targetNumber_H = 0;
int targetNumber_T = 0;
int targetNumber_O = 0;

int userNumber = 0;

int strike = 0;
int ball = 0;


//1. 숫자뿌리기
//2. 숫자쓰기
//3. 숫자검사하기
//4. 종료하기

int main()
{
	//1. 숫자뿌리기
	srand(time(nullptr));

	targetNumber_H = rand() % 8 + 1;

	while (true)
	{
		targetNumber_T = rand() % 10;

		if (targetNumber_H != targetNumber_T)
			break;
	}

	while (true)
	{
		targetNumber_O = rand() % 10;

		if (targetNumber_T == targetNumber_O) 
			continue;
		if (targetNumber_H == targetNumber_O)
			continue;

		break;
	}


	cout << targetNumber_H << targetNumber_T << targetNumber_O << endl;


	while (true)
	{
		cout << "숫자를 입력해보세용 : ";
		cin >> userNumber;

		int userNumber_H = userNumber / 100;
		int	userNumber_T = (userNumber % 100) / 10;
		int	userNumber_O = userNumber % 10;

		//cout << userNumber_H << userNumber_T << userNumber_O << endl;
	
		if (userNumber_H == targetNumber_H)
			strike++;
		if (userNumber_T == targetNumber_T)
			strike++;
		if (userNumber_O == targetNumber_O)
			strike++;


		if (userNumber_H == targetNumber_T)
			ball++;
		if (userNumber_H == targetNumber_O)
			ball++;
		if (userNumber_T == targetNumber_H)
			ball++;
		if (userNumber_T == targetNumber_O)
			ball++;
		if (userNumber_O == targetNumber_H)
			ball++;
		if (userNumber_O == targetNumber_T)
			ball++;

		cout <<strike<< "S" << ball << "B" << endl;
		if (strike == 3)
		{
			cout << "정답!!!!!!!!!!" << endl;
			break;
		}

		strike = 0;
		ball = 0;

		
	}


	system("pause");
	return 0;
}