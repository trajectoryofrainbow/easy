#define _CRT_SECURE_NO_WARNINGS 1

#include"game1.h"
void menu()
{
	printf("#####################\n");
	printf("###1.play   0.exit###\n");
	printf("#####################\n");
}

void game()
{
	char ret = 0;
	//数组存放走出的棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Initboard(board,ROW,COL);
	//打印棋盘
	Displayboard(board,ROW,COL);
	//下棋
	while (1) 
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		Displayboard(board, ROW, COL);
		//判断玩家是否赢得游戏	
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}	
	else if (ret == 'Q')
	{
		printf("本局平局\n");
	}

}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {

		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}

	} while (input);


}



int main()
{
	test();
	return 0;
}