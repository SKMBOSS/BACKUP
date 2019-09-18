#include <iostream>
#include <conio.h>

using namespace std;

/**********************************************************/
#define SIZE 19

#define BLANK 0
#define WHITE 1
#define BLACK 2

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
/**********************************************************/

int board[SIZE][SIZE];

int x=0;
int y=0;

int player=0;
int turnCount=0;
bool isChangePlayer = false;

/**********************************************************/

void Init();
void DrawBoard();
void PrintTurn();

void OperateInput();

bool isWin();
void PrintWinner();

void ChangePlayer();
/**********************************************************/

//게임종료 체크하기 (승부가 나지않았을때) **미구현
bool isEnd();

//실험중
bool isWin2();

int main()
{
	Init();
	DrawBoard();
	PrintTurn();

	while (true)
	{
		OperateInput();

		if (isWin())
		{
			PrintWinner();
			break;
		}

		ChangePlayer();

		DrawBoard();
		PrintTurn();
	}


	system("pause");
	return 0;
}

void Init()
{
	x = SIZE / 2;
	y = SIZE / 2;

	player = BLACK;
	turnCount = 1;
	isChangePlayer = false;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			board[i][j] = BLANK;
	}
}

void DrawBoard()
{
	system("cls");

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{

			if (i == y && j == x && player == BLACK)
				cout << "☆";

			else if (i == y && j == x && player == WHITE)
				cout << "★";

			else if (board[i][j] == BLACK)
				cout << "○";

			else if (board[i][j] == WHITE)
				cout << "●";

			else if (board[i][j] == BLANK)
			{
				if (i == 0 && j == 0)
					cout << "┌";

				else if (i == SIZE - 1 && j == 0)
					cout << "└";

				else if (i == 0 && j == SIZE - 1)
					cout << "┐";

				else if (i == SIZE - 1 && j == SIZE - 1)
					cout << "┘";

				else if (i == 0)
					cout << "┬";

				else if (i == SIZE - 1)
					cout << "┴";

				else if (j == 0)
					cout << "├";

				else if (j == SIZE - 1)
					cout << "┤";

				else
					cout << "┼";
			}
		}
		cout << endl;

	}
}

void PrintTurn() 
{
	cout << "Turn : " << turnCount;

	if (player == BLACK)
		cout << "(흑)";

	else if (player == WHITE)
		cout << "(백)";
}

void PrintWinner()
{
	cout << endl << endl;

	if (player == BLACK)
	{
		cout << "흑의 승리~!!" << endl;
	}
	else if (player == WHITE)
	{
		cout << "백의 승리~!!" << endl;
	}
	cout << endl;
}

void OperateInput()
{
	isChangePlayer = false;

	char ch = _getch();

	if (ch == UP)
	{
		y--;

		if (y == -1)
			y = SIZE - 1;
	}

	else if (ch == DOWN)
	{
		y++;

		if (y == SIZE)
			y = 0;
	}
	else if (ch == LEFT)
	{
		x--;

		if (x == -1)
			x = SIZE - 1;
	}

	else if (ch == RIGHT)
	{
		x++;

		if (x == SIZE)
			x = 0;
	}
	else if (ch == SPACE)
	{

		if (board[y][x] == BLANK)
		{
			board[y][x] = player;
			isChangePlayer = true;
			turnCount++;
		}

		else
		{
			cout << "이미 돌이 존재합니다.." << endl;
			//continue;
		}

	}
}

void ChangePlayer()
{
	if (isChangePlayer == true)
	{
		if (player == BLACK)
			player = WHITE;
		else
			player = BLACK;
	}
}

bool isWin() // 넘오래걸리는데 게에바임
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			// 가로(→) 방향 체크,
			if (board[y][x] == player && board[y][x + 1] == player &&
				board[y][x + 2] == player && board[y][x + 3] == player &&
				board[y][x + 4] == player)
				return true;

			// 세로(↓) 방향 체크,
			else if (board[y][x] == player && board[y + 1][x] == player &&
				board[y + 2][x] == player && board[y + 3][x] == player &&
				board[y + 4][x] == player)
				return true;

			// 대각선(↘) 방향 체크,
			else if (board[y][x] == player && board[y + 1][x + 1] == player &&
				board[y + 2][x + 2] == player && board[y + 3][x + 3] == player &&
				board[y + 4][x + 4] == player)
				return true;

			// 대각선(↙) 방향 체크,
			else if (board[y][x] == player && board[y + 1][x - 1] == player &&
				board[y + 2][x - 2] == player && board[y + 3][x - 3] == player &&
				board[y + 4][x - 4] == player)
				return true;
		}
	}


	return false;
}

bool isWin2() //도전중
{
	if (board[x][y] != BLANK)
	{
		//x0000
		if (board[y][x] == board[y][x + 1] &&
			board[y][x + 1] == board[y][x + 2] &&
			board[y][x + 2] == board[y][x + 3] &&
			board[y][x + 3] == board[y][x + 4])
			return true;

		//0x000
		else if (board[y][x] == board[y][x - 1] &&
			board[y][x - 1] == board[y][x + 1] &&
			board[y][x + 1] == board[y][x + 2] &&
			board[y][x + 2] == board[y][x + 3])
			return true;

		//00x00
		else if (board[y][x] == board[y][x - 1] &&
			board[y][x - 1] == board[y][x - 2] &&
			board[y][x - 2] == board[y][x + 1] &&
			board[y][x + 1] == board[y][x + 2])
			return true;

		//000x0
		else if (board[y][x] == board[y][x - 1] &&
			board[y][x - 1] == board[y][x - 2] &&
			board[y][x - 2] == board[y][x - 3] &&
			board[y][x - 3] == board[y][x + 1])
			return true;

		//0000x
		else if (board[y][x] == board[y][x - 1] &&
			board[y][x - 1] == board[y][x - 2] &&
			board[y][x - 2] == board[y][x - 3] &&
			board[y][x - 3] == board[y][x - 4])
			return true;

		//y0000
		else if (board[y][x] == board[y + 1][x] &&
			board[y + 1][x] == board[y + 2][x] &&
			board[y + 2][x] == board[y + 3][x] &&
			board[y + 3][x] == board[y + 4][x])
			return true;

		//0y000
		else if (board[y][x] == board[y - 1][x] &&
			board[y - 1][x] == board[y + 1][x] &&
			board[y + 1][x] == board[y + 2][x] &&
			board[y + 2][x] == board[y + 3][x])
			return true;

		//00y00
		else if (board[y][x] == board[y][x - 1] &&
			board[y][x - 1] == board[y][x - 2] &&
			board[y][x - 2] == board[y][x + 1] &&
			board[y][x + 1] == board[y][x + 2])
			return true;

		//000y0
		else if (board[y][x] == board[y - 1][x] &&
			board[y - 1][x] == board[y - 2][x] &&
			board[y - 2][x] == board[y - 3][x] &&
			board[y - 3][x] == board[y + 1][x])
			return true;

		//0000y
		else if (board[y][x] == board[y - 1][x] &&
			board[y - 1][x] == board[y - 2][x] &&
			board[y - 2][x] == board[y - 3][x] &&
			board[y - 3][x] == board[y - 4][x])
			return true;

		else
			false;
	}

	return false;


}



