#include <iostream>
#include <conio.h>

using namespace std;

#define MAP_SIZE 19

#define BLANK 0
#define WALL -1

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32

struct Point
{
	int x;
	int y;
};

int board[MAP_SIZE][MAP_SIZE];
Point point;

//초기화
void Init();

void InitBoard();
void InitPoint();

//맵그리기
void DrawMap();

//조작
void OperateInput();

int main()
{
	Init();
	DrawMap();

	while (true)
	{
		/*
		if (OperateInput())
			break;
		*/
		OperateInput();
		DrawMap();
	}

	system("pause");
	return 0;
}

void Init()
{
	InitPoint();
	InitBoard();
}

void InitPoint()
{
	point.x = MAP_SIZE / 2;
	point.y = MAP_SIZE / 2;
}

void InitBoard()
{
	for (int iy = 0; iy < MAP_SIZE; iy++)
	{
		for (int jx = 0; jx < MAP_SIZE; jx++)
		{
			if ((iy == 0) || (iy == MAP_SIZE - 1) || (jx == 0) || (jx == MAP_SIZE - 1))
				board[iy][jx] = WALL;

			else
				board[iy][jx] = BLANK;
		}
	}
}

void DrawMap()
{
	system("cls");

	for (int iy = 0; iy < MAP_SIZE; iy++)
	{
		for (int jx = 0; jx < MAP_SIZE; jx++)
		{
			if (iy == point.y && jx == point.x)
				cout << "□";

			else if (board[iy][jx] == WALL)
			{
				cout << "■";
			}
			else
				cout << "  ";
		}
		cout << endl;
	}
}

void OperateInput()
{
	char input = _getch();

	if (input == UP)
	{
		if(board[point.y-1][point.x] != WALL)
			point.y--;			
	}

	else if (input == DOWN)
	{
		if (board[point.y + 1][point.x] != WALL)
			point.y++;
	}
	else if (input == LEFT)
	{
		
		if (board[point.y][point.x-1] != WALL)
			point.x--;
	}

	else if (input == RIGHT)
	{
		if (board[point.y][point.x+1] != WALL)
			point.x++;
	}

	else if (input == SPACE)
	{
		board[point.y][point.x] = WALL;
	}
}