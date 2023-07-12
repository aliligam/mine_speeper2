#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS ROW+2

#define COUNT 10
void init_board(char mine[ROWS][COLS], char s);
void set_mine(char mine[ROWS][COLS]);
void display_board(char arr[ROWS][COLS]);
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int* pwin);

