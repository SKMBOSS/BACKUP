﻿#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

#define FPS 30

#define HEIGHT 30
#define WIDTH  20
#define MAX_DDONG 1000

#define BLANK 0
#define WALL -1
#define DDONG -2

#define LEFT 75
#define RIGHT 77

#define SPEED_LEVEL4 0
#define SPEED_LEVEL3 1
#define SPEED_LEVEL2 2
#define SPEED_LEVEL1 4


struct Player
{
	int x;
	int y;
};

struct DDong
{
	int x;
	int y;

	int speed;
	int count;

	bool alive;
	//bool dCrash;
};

Player player;

DDong ddong[MAX_DDONG];
int ddongNum = 0;

int board[HEIGHT][WIDTH];
int score = 0;

bool isPlaying = true;

//초기화
void Init();
void InitBoard();
void InitPlayer();
void InitDDong();

//맵그리기
void Draw();

//조작
void Input();

//업뎃
void Update();

//미구현
void Relase();

int main()
{
	Init();
	Draw();

	while (isPlaying)
	{
		Input();
		Update();
		Draw();
		Sleep(1000 / FPS);
		
	}
	Relase();

	system("pause");
	return 0;
}

void Init()
{
	//시드를 시간으로 넣어야제
	srand(time(nullptr));

	InitPlayer();
	InitDDong();
	InitBoard();
}

void InitPlayer()
{
	player.x = WIDTH / 2;
	player.y = HEIGHT - 2;
}

void InitDDong()
{
	for (int i = 0; i < MAX_DDONG; i++)
	{
		ddong[i].alive = false;
		ddong[i].x = -1;
		ddong[i].y = -1;
		ddong[i].speed = 0;
		ddong[i].count = 0;
		//ddong[i].dCrash = false;
	}
}

void InitBoard()
{
	for (int iy = 0; iy < HEIGHT; iy++)
	{
		for (int jx = 0; jx < WIDTH; jx++)
		{
			if ((iy == HEIGHT - 1) || (jx == 0) || (jx == WIDTH - 1))
				board[iy][jx] = WALL;

			else
				board[iy][jx] = BLANK;
		}
	}
}

void Draw()
{
	system("cls");

	for (int iy = 0; iy < HEIGHT; iy++)
	{
		for (int jx = 0; jx < WIDTH; jx++)
		{
			if (iy == player.y && jx == player.x)
				cout << "□";

			else if (board[iy][jx] == WALL)
			{
				cout << "■";
			}
			else if (board[iy][jx] == DDONG)
			{
				cout << "☆";
			}

			else if (board[iy][jx] == BLANK)
				cout << "  ";
		}
		cout << endl;
	}
	cout << "score : " << score << endl;
}

void Input()
{
	if (_kbhit()) //리턴이 있다는 것은 키보드를 누른것 ㅇㅋ?
	{
		char input = _getch();


		if (input == LEFT)
		{

			if (board[player.y][player.x - 1] != WALL)
				player.x--;
		}

		else if (input == RIGHT)
		{
			if (board[player.y][player.x + 1] != WALL)
				player.x++;
		}
	}
}

void Update()
{
	//똥초기화
	ddong[ddongNum].alive = true;
	ddong[ddongNum].x = rand() % (WIDTH - 2) + 1;
	ddong[ddongNum].y = 0;
	
	//똥스피드배분
	int random = rand() % 100;

	if (random >= 90)
		ddong[ddongNum].speed = SPEED_LEVEL1;
	else if (random >= 70)
		ddong[ddongNum].speed = SPEED_LEVEL2;
	else if (random >= 40)
		ddong[ddongNum].speed = SPEED_LEVEL3;
	else
		ddong[ddongNum].speed = SPEED_LEVEL4;

	//똥그리기
	for (int i = 0; i <= ddongNum; i++)
	{
		if (!ddong[i].alive)
			continue;

		//속도조절
		if (ddong[i].count++ != ddong[i].speed)
			continue;
		
		//똥끼리충돌 ㅠㅠ
		/*
		■ <-빠른놈  □
		■ <-느린놈  ■ -<겹쳐짐 □ <-느린놈 대기시간동안 안나옴
		□           □          ■ <-빠른놈이 느린놈 지움
		*/
		
		//바닥충돌
		if (board[ddong[i].y + 1][ddong[i].x] == WALL)
		{
			ddong[i].alive = false;
			board[ddong[i].y][ddong[i].x] = BLANK;
			score++;
		}

		else
		{
			ddong[i].count = 0;
			ddong[i].y++; //똥내려가게

			if (board[ddong[i].y - 1][ddong[i].x] != BLANK)
			{
				board[ddong[i].y - 1][ddong[i].x] = BLANK; //이전똥 지우기
			}

			board[ddong[i].y][ddong[i].x] = DDONG; //똥 업데이트

		}
	}

	ddongNum++;

	//종료조건
	if (ddongNum == MAX_DDONG || board[player.y][player.x] == DDONG)
	{
		isPlaying = false;
	}
}

void Relase()
{}






