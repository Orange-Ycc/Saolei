#include "game.h"
#define  _CRT_SECURE_NO_WARNINGS 1

void InitialBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------扫雷游戏---------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------扫雷游戏---------\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int get_min_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1、输入排查的坐标
	//2、检查坐标处是不是雷
		//（1）是雷， 很遗憾你被炸死了，游戏结束
		//（2）不是雷  统计坐标周围有几个雷  存储排查雷的信息到show数组中，游戏继续

	int x = 0;
	int y = 0;
	int win = 0;
	
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入你要排查的坐标：");
		scanf("%d%d", &x, &y);//x = 1~9  //y = 1~9

		//判断输入的坐标是否合法
		if (x >= 1 && x <= row & y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n游戏结束！\n");
				DisplayBoard(mine, row, col);
			}
			else
			{
				//不是雷，统计x.y坐标周围有几个雷
				int count = get_min_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入！\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}
