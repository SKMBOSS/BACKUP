#include <iostream>
#include <stdio.h>
using namespace std;

struct student
{
	int no;
	char szName[256];
	int kor;
	int eng;
	int math;
};

// 학생 최대수 3명
//성적표 
//1.입력
//2.출력
//3.종료
//
//1입력 이름 국 영 수
//2
//번호	이름	국	영	수	평균	총점
//

void inputStudent(student st[] , int iCurStudent)
{
	st[iCurStudent].no = iCurStudent + 1;
	cout << "이름" << endl;
	cin >> st[iCurStudent].szName;
	cout << "국어" << endl;
	cin >> st[iCurStudent].kor;
	cout << "영어" << endl;
	cin >> st[iCurStudent].eng;
	cout << "수학" << endl;
	cin >> st[iCurStudent].math;
	iCurStudent++;
}

void printMenu()
{
	cout << "1.입력" << endl;
	cout << "2.출력" << endl;
	cout << "3.종료" << endl;
}

char* my_strstr(char* szDest,const char* szFind)
{
	int i = 0;
	int j = 0;
	while (true)
	{
		j = 0;
		if (szDest[i] == szFind[j])
		{
			while (true)
			{
				if (szFind[j] == NULL)
					return &szDest[i];

				if (szDest[i + j] != szFind[j])
					break;

				j++;
			}
		}

		if (szDest[i] == NULL)
			break;

		i++;
	}

	return nullptr;
}

char* my_strchr(char* szDest, char ch)
{
	int i = 0;
	while (true)
	{
		if (szDest[i] == ch)
			return &szDest[i];

		if (szDest[i] == NULL)
			break;

		i++;
	}

	return nullptr;
}

void my_strcpy(char* szDest, const char* szSource)
{
	int i = 0;
	while (true)
	{
		szDest[i] = szSource[i];
		if (szSource[i] == NULL)
			break;

		i++;
	}
}

int main()
{
	char szly[1024 * 10] = "The snow glows white on the mountain tonight\
		Not a footprint to be seen\
		A kingdom of isolation\
		And it looks like I'm the queen\
		The wind is howling like this swirling storm inside\
		Couldn't keep it in, heaven knows I've tried\
		Don't let them in, don't let them see\
		Be the good girl you always have to be\
		Conceal, don't feel, don't let them know\
		Well, now they know\
		Let it go, let it go\
		Can't hold it back anymore\
		Let it go, let it go\
		Turn away and slam the door\
		I don't care what they're going to say\
		Let the storm rage on\
		The cold never bothered me anyway\
		Let it go, let it go\
		Can't hold it back anymore\
		Let it go, let it go\
		Turn away and slam the door\
		Let it go(go, go, go go, go go, go go, go, go, go go)\
		Let it go\
		Let it go\
		Let it go\
		It's funny how some distance makes everything seem small\
		And the fears that once controlled me can't get to me at all\
		It's time to see what I can do\
		To test the limits and break through\
		No right, no wrong, no rules for me\
		I'm free\
		Let it go, let it go\
		I am one with the wind and sky\
		Let it go, let it go\
		You'll never see me cry\
		Here I stand and here I stay\
		Let the storm rage on\
		My power flurries through the air into the ground\
		My soul is spiraling in frozen fractals all around\
		And one thought crystallizes like an icy blast\
		I'm never going back, the past is in the past\
		Let it go\
		The cold never bothered me anyway\
		Let it go, let it go\
		And I'll rise like the break of dawn\
		Let it go, let it go\
		That perfect girl is gone\
		Here I stand in the light of day\
		Let the storm rage on";

	char* szFind = szly;
	int iCount = 0;
	while (true)
	{
		szFind = strstr(szFind, "Let it go");
		iCount++;
		if (szFind == NULL)
			break;

		szFind++;
	}

	cout << iCount << endl;

	/*
	char szName[256] = "asdsad";

	my_strcpy(szName, "zxzxzx");//szName = "zxzxzx";
	int len = strlen(szName);//구현 mystrlen
	strcat(szName, "asdasd");// szName += "asdasd"
	int same = strcmp(szName, "zxzxzxasdasd"); //리턴값이 0이면 같다
	//char* szOut = strchr(szName, 'a');
	char* szOut = my_strstr(szName, "xa"); // mystrstr
	cout << szOut << endl;
	cout << szName << endl;*/


	/*
	student st[3];
	int iCurStudent = 0;

	while (true)
	{
		int input = 0;

		printMenu();

		cin >> input;

		if (input == 1)
		{
			inputStudent(st , iCurStudent);
		}
		else if (input == 2)
		{
			cout << "번호\t이름\t국어\t영어\t수학\t총점\t평균" << endl;
			for (int i = 0; i < iCurStudent; i++)
			{
				float fSum = st[i].kor + st[i].eng + st[i].math;
				float fAvg = fSum / 3;
				cout << st[i].no << "\t" << st[i].szName << "\t" <<
					st[i].kor << "\t" << st[i].eng << "\t" <<
					st[i].math << "\t" <<
					fSum << "\t" << fAvg << endl;
			}
		}
		else if (input == 3)
		{
			break;
		}
	}*/
	
	return 0;
}