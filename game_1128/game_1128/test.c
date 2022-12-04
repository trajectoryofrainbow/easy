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
	//�������߳���������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initboard(board,ROW,COL);
	//��ӡ����
	Displayboard(board,ROW,COL);
	//����
	while (1) 
	{
		//�������
		PlayerMove(board,ROW,COL);
		Displayboard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ����Ϸ	
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
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
		printf("��һ�ʤ\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}	
	else if (ret == 'Q')
	{
		printf("����ƽ��\n");
	}

}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {

		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}

	} while (input);


}



int main()
{
	test();
	return 0;
}