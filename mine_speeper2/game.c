#include"game.h"


void init_board(char arr[ROWS][COLS], char s)
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			arr[i][j] = s;
}

void set_mine(char mine[ROWS][COLS])
{
	int x, y;
	for (int n = 0; n < COUNT; )
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			n++;
		}
	}
}

void display_board(char arr[ROWS][COLS])
{
	int i, j;
	for (i = 0; i <= COL; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= ROW;i++ )
	{
		printf("%d ", i);
		for (j = 1; j <= COL; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}
}

char around(char mine[ROWS][COLS], int x, int y)
{
	
	int num=0;
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (mine[i][j] == '1' && !(x == i && y == j))
				num++;
		return num + '0';
}

void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int* pend)
{
	
	if (x > 0 && y > 0 && x <= ROW && y <= COL)		//legal input
		if (show[x][y] == '*')	//unknown choice
			if (mine[x][y] == '1') //mine explode
			{
				*pend = -1;
			}
			else
			{
				show[x][y] = around(mine,x,y);
				(*pend)--;
			}
		else
			printf("repeat input.\n");
	else
		printf("illegal input.\n");
	

}