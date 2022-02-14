#include "leon.h"

extern  Goods leon[SIZE][SIZE];
extern int exit_face_num[9];

//商品列表初始化函数
void initialize(Goods leon[][SIZE], FILE *fp)
{
	rewind(fp);
	printf("已建立初始商品列表\n该商品列表由\"LEON Management Operation System\"文件内商品信息决定\n\n");
	fread(leon, sizeof(Goods), SIZE*SIZE, fp);
	rewind(fp);
}


void initial_face_num(int * exit_face_num, FILE * fp2)
{
	rewind(fp2);
	printf("已建立LEON自动售货机内部纸/硬币统计列表\n");
	printf("该统计列表由\"The Balance Of LEON Management Operation System\"");
	printf("文件内不同面值纸/硬币余额决定\n\n");
	fread(exit_face_num , sizeof(int) , 9  , fp2);
	puts("");
	rewind(fp2);
}

//程序打印及显示菜单函数
void menu(Goods leon[][SIZE], FILE *fp , FILE *fp2)
{

	int c;
	char ** complain_list = NULL;
	while (true)
	{
		/* 在屏幕上画一个主菜单 */
		printf("/**********自动售卖机LEON管理系统**********/\n\n");
		printf("  1:  查看机器所含商品信息\n\n");
		printf("  2:  购买商品\n\n");
		printf("  3:  投诉服务\n\n");
		printf("  4:  商品上下架(针对工作人员)\n\n");
		printf("/******************************************/\n\n");
		printf("请选择所需要的操作:");
		while (scanf("%d", &c) != 1)
		{
			EATLINE;
			printf("您输入的格式不正确,请重新输入:");
		}
		EATLINE;
		/* 输入选择项 */
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
			printf("您的输入不正确,请重新输入,感谢配合\n");
			system("pause");
			system("cls");
			continue;
		}
		system("pause");
		system("cls");
	}
}

int prin(Goods leon[][SIZE], int person)//打印机器所含全部未过期商品信息 
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
					printf("/**名称:%-12s商标:%-12s净含量(ml/g):%-10s 价格:%4.1f      生产日期:%4d/%02d/%02d   保质期(月份):%5.1f**/\n",
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
					printf("/**名称:%-12s商标:%-12s净含量(ml/g):%-10s 价格:%4.1f      生产日期:%4d/%02d/%02d   保质期(月份):%5.1f**/\n",
						leon[i][j].kind[0], leon[i][j].kind[1], leon[i][j].kind[2], leon[i][j].prize, leon[i][j].date[0],
						leon[i][j].date[1], leon[i][j].date[2], leon[i][j].qgp);
					number_exit = 1;
				}
			}
		}
	}


	printf("\n");
	if (number_exit == 0)
		printf("LEON中商品已售罄,已无法购买,非常抱歉!       ");
	else
		printf("LEON中的商品展示完毕!                       ");
	return  number_exit;
}

