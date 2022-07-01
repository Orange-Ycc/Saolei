#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("******************************\n");
	printf("******		1、play		******\n");
	printf("******		0、exit		******\n");
	printf("******************************\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化棋盘    Initial 初始
	InitialBoard(mine, ROWS, COLS, '0');
	InitialBoard(show, ROWS, COLS, '*');

	//打印排查雷的棋盘	display 陈列
	DisplayBoard(show, ROW, COL);

	//布置雷区
	SetMine(mine, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新选择！");
			break;
		}
	} while (input);
}