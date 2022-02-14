#include "leon.h"

extern  Goods leon[SIZE][SIZE];
extern int exit_face_num[9];

//��Ʒ�б��ʼ������
void initialize(Goods leon[][SIZE], FILE *fp)
{
	rewind(fp);
	printf("�ѽ�����ʼ��Ʒ�б�\n����Ʒ�б���\"LEON Management Operation System\"�ļ�����Ʒ��Ϣ����\n\n");
	fread(leon, sizeof(Goods), SIZE*SIZE, fp);
	rewind(fp);
}


void initial_face_num(int * exit_face_num, FILE * fp2)
{
	rewind(fp2);
	printf("�ѽ���LEON�Զ��ۻ����ڲ�ֽ/Ӳ��ͳ���б�\n");
	printf("��ͳ���б���\"The Balance Of LEON Management Operation System\"");
	printf("�ļ��ڲ�ͬ��ֵֽ/Ӳ��������\n\n");
	fread(exit_face_num , sizeof(int) , 9  , fp2);
	puts("");
	rewind(fp2);
}

//�����ӡ����ʾ�˵�����
void menu(Goods leon[][SIZE], FILE *fp , FILE *fp2)
{

	int c;
	char ** complain_list = NULL;
	while (true)
	{
		/* ����Ļ�ϻ�һ�����˵� */
		printf("/**********�Զ�������LEON����ϵͳ**********/\n\n");
		printf("  1:  �鿴����������Ʒ��Ϣ\n\n");
		printf("  2:  ������Ʒ\n\n");
		printf("  3:  Ͷ�߷���\n\n");
		printf("  4:  ��Ʒ���¼�(��Թ�����Ա)\n\n");
		printf("/******************************************/\n\n");
		printf("��ѡ������Ҫ�Ĳ���:");
		while (scanf("%d", &c) != 1)
		{
			EATLINE;
			printf("������ĸ�ʽ����ȷ,����������:");
		}
		EATLINE;
		/* ����ѡ���� */
		switch (c)
		{
		case 1:
			prin(leon, CUSTOMER);
			break;
		case 2:
			purchase(prin(leon, CUSTOMER), leon);
			break;
		case 3:
			system("cls");
			complain_list = complaint();
			break;
		case 4:
			maintain(leon, complain_list, fp , fp2);
			break;
		default:
			printf("�������벻��ȷ,����������,��л���\n");
			system("pause");
			system("cls");
			continue;
		}
		system("pause");
		system("cls");
	}
}

int prin(Goods leon[][SIZE], int person)//��ӡ��������ȫ��δ������Ʒ��Ϣ 
{
	int number_exit = 0;
	if (person == 1)
	{
		int i = 0;
		for (; i < SIZE; i++)
		{
			int j = 0;
			for (; j < SIZE; j++)
			{
				if (leon[i][j].judge_if_vacancy == 1 && leon[i][j].judge_if_overdue == 0)
				{
					printf("/**����:%-12s�̱�:%-12s������(ml/g):%-10s �۸�:%4.1f      ��������:%4d/%02d/%02d   ������(�·�):%5.1f**/\n",
						leon[i][j].kind[0], leon[i][j].kind[1], leon[i][j].kind[2], leon[i][j].prize, leon[i][j].date[0],
						leon[i][j].date[1], leon[i][j].date[2], leon[i][j].qgp);
					number_exit = 1;
				}
			}
		}
	}
	else if (person == 2)
	{
		int i = 0;
		for (; i < SIZE; i++)
		{
			int j = 0;
			for (; j < SIZE; j++)
			{
				if (leon[i][j].judge_if_vacancy == 1)
				{
					printf("/**����:%-12s�̱�:%-12s������(ml/g):%-10s �۸�:%4.1f      ��������:%4d/%02d/%02d   ������(�·�):%5.1f**/\n",
						leon[i][j].kind[0], leon[i][j].kind[1], leon[i][j].kind[2], leon[i][j].prize, leon[i][j].date[0],
						leon[i][j].date[1], leon[i][j].date[2], leon[i][j].qgp);
					number_exit = 1;
				}
			}
		}
	}


	printf("\n");
	if (number_exit == 0)
		printf("LEON����Ʒ������,���޷�����,�ǳ���Ǹ!       ");
	else
		printf("LEON�е���Ʒչʾ���!                       ");
	return  number_exit;
}

