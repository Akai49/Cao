#define  _CRT_SECURE_NO_WARNINGS 1

//������������Ϸ


#include "test.h"

void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");
	printf("********************\n");		
}

//   |   |   
//---|---|---
//   |   |  
//---|---|---
//   |   |   


//��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	//����-����߳���������Ϣ
	char qipan[ROW][COL] = { 0 };//ȫ���ո�
	//��ʼ������
	InitQipan(qipan, ROW, COL);
	//��ӡ����
	DisplayQipan(qipan, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayerGo(qipan, ROW, COL);
		DisplayQipan(qipan, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(qipan, ROW, COL);
		if (ret != 'R')
		{
			break;		
		}
		//��������
		ComputerGo(qipan, ROW, COL);
		DisplayQipan(qipan, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(qipan, ROW, COL);
		if (ret != 'R')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
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