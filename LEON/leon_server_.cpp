#include "leon.h"

extern  Goods leon[SIZE][SIZE];
extern int exit_face_num[9];


//工作人员相关函数
void maintain(Goods leon[][SIZE], char ** complain_list, FILE *fp , FILE*fp2)
{
	printf("请输入管理员密钥:\n");
	char code[SIZE];
	s_gets(code, SIZE);
	if (strcmp(code, "12345") != false)
		printf("密钥输入错误.\n");
	else
	{
		system("cls");
		puts("\n/****LEON自动售卖机工作人员后台程序模块开启****/\n");
		char nji[SIZE];
		printf("请问需要关机吗?(0为需要,其他任意键为不需要)  输入:");
		s_gets(nji, SIZE);
		if (strcmp(nji, "0") == false)
		{
			printf("即将关闭now分支线程\n");//线程自动关闭
			printf("即将关闭sign_goods__overdued分支线程\n");
			printf("是否保存LEON目前的商品信息?\n输入\"是的\"将保存,其他输入不保存\n");
			char temp[SIZE];
			s_gets(temp, SIZE);
			if (strcmp(temp, "是的") == false)
			{
				rewind(fp);
				fwrite(leon, sizeof(Goods), SIZE*SIZE, fp);
				fwrite(exit_face_num, sizeof(int), 9, fp2);
				rewind(fp);
				printf("已保存!\n");
			}
			else
				printf("未保存!\n");
			printf("LEON自动售货机即将关机!\n");
			int s = 0;//一个小小的等待函数
			for (; s < 3; s++)
			{
				printf("关机中");
				int j = 0;
				for (; j < 3; j++)
				{
					printf("。");
					Sleep(750);
				}
				for (j = 0; j < 16; j++)
					printf("\b");
				for (j = 0; j < 16; j++)
					printf(" ");
				for (j = 0; j < 16; j++)
					printf("\b");
			}
			system("pause");
			exit(EXIT_SUCCESS);
		}
		puts("");
		if (0 == prin(leon, SERVER))
		{
			printf("\r                                                             \n");
			printf("售货机为空!\n");
		}
		else
			printf("\r                                                             \n");
		printf("已进入LEON后台程序\n\n/**LEON自动售卖机工作人员上下架模块开启**/\n\n请问需要对其进行什么操作?\n a)取出过期商品   b)放入新商品  c)取出已有未过期商品  d)检查纸币数量 \n(回车键为退出)请输入:");
		char choice[SIZE];
		while (s_gets(choice, SIZE) && strcmp(choice, "") != false)
		{
			if (strcmp(choice, "a") == false)
			{
				printf("\n/*下架过期商品模块开启*/\n\n");
				fetch(leon);
				puts("");
				if (0 == prin(leon, SERVER))
				{
					printf("\r                                                             \n");
					printf("售货机为空!\n");
				}
				else
					printf("\r                                                             \n");
				printf("\n如需继续操作,请输入:(回车键为退出) a)取出过期商品   b)放入新商品    c)取出已有未过期商品  d)检查纸币数量 ");
			}
			else if (strcmp(choice, "b") == false)
			{
				printf("\n/*上架新商品模块开启*/\n\n");
				putOnSale(leon);
				puts("");
				if (0 == prin(leon, SERVER))
				{
					printf("\r                                                             \n");
					printf("售货机为空!\n");
				}
				else
					printf("\r                                                             \n");
				printf("\n如需继续操作,请输入:(回车键为退出) a)取出过期商品   b)放入新商品    c)取出已有未过期商品  d)检查纸币数量 ");
			}
			else if (strcmp(choice, "c") == false)
			{
				printf("\n/*下架已有未过期商品模块开启*/\n\n");
				bring(leon);
				puts("");
				if (0 == prin(leon, SERVER))
				{
					printf("\r                                                             \n");
					printf("售货机为空!\n");
				}
				else
					printf("\r                                                             \n");
				printf("\n如需继续操作,请输入:(回车键为退出) a)取出过期商品   b)放入新商品    c)取出已有未过期商品  d)检查纸币数量 ");
			}
			else if (strcmp(choice, "d") == false)
			{
				printf("\n/*检查售货机纸币数量模块开启*/\n\n");
				check(leon);
				printf("\n如需继续操作,请输入:(回车键为退出) a)取出过期商品   b)放入新商品    c)取出已有未过期商品  d)检查纸币数量 ");
			}
			else
				printf("输入格式错误,请重新输入:(回车键为退出)");
		}

		printf("\n现在LEON自动售卖机内所含商品有:\n");
		if (0 == prin(leon, SERVER))
		{
			printf("\r                                                             \n");
			printf("售货机为空!\n");
		}
		else
			printf("\r                                                             \n");
		puts("\n\n/**LEON自动售卖机工作人员上下架模块关闭**/\n\n");
		puts("/**LEON自动售卖机工作人员接受投诉模块开启**/\n");
		if (complain_list == NULL)
		{
			printf("\n暂无客户投诉!\n请继续保持!\n\n");
			puts("\n/**LEON自动售卖机工作人员接受投诉模块关闭**/\n");
		}
		else
		{
			int gh = 0;//投诉条目计数
			int d = 0;
			for (; d < COMPSIZE; d++)
			{
				if (d <= 4)
					if (strpbrk(complain_list[d], "123456789") != NULL)
						gh++;
					else if (strcmp(complain_list[d], "") != false)
						gh++;
			}
			if (gh == 0)
			{
				printf("\n暂无客户投诉!\n请继续保持!\n\n");
				puts("\n/**LEON自动售卖机工作人员接受投诉模块关闭**/\n");
			}

			else
			{
				int numt = 0;//记录客户投诉数目
				printf("客户投诉列举如下:\n\n");
				printf("一、对四个LEON自动售货机常见问题的投诉:\n\n");
				int d = 0;
				for (; d < COMPSIZE; d++)
				{
					if (d == 4)
						printf("\n二、客户具体投诉条目如下:\n");
					if (d < 4)//此处不能修改括号!!!
					{
						if (strpbrk(complain_list[d], "123456789") != NULL)
						{
							if (d == 0)
								printf("   1:  机器付款后没有反应      %s次\n", complain_list[d]);
							else if (d == 1)
								printf("   2:  出售过期产品            %s次\n", complain_list[d]);
							else if (d == 2)
								printf("   3:  机器操作过于复杂        %s次\n", complain_list[d]);
							else if (d == 3)
								printf("   4:  商品种类太少            %s次\n", complain_list[d]);
						}
					}
					else
					{
						if (strcmp(complain_list[d], "") != false)
							printf("\n  %2d.  直接投诉内容:  %s\n", ++numt, complain_list[d]);
					}
				}
				printf("\n列举完毕,需要进行改进!\n\n");
				puts("\n/**LEON自动售卖机工作人员接受投诉模块关闭**/\n");
			}
		}
	}
	puts("\n/****LEON自动售卖机工作人员后台程序模块关闭****/\n");
}

void putOnSale(Goods leon[][SIZE])
{
	printf("请输入将投放的商品数目:");
	int number;
	while (scanf("%d", &number) != 1)
	{
		printf("输入错误,请重新输入!  ");
		EATLINE;
	}
	EATLINE;
	Goods * temp = (Goods *)calloc(number, sizeof(Goods));
	int i = 0;
	for (; i < number; i++)
	{
		printf("名称:");
		s_gets(temp[i].kind[0], SIZE);
		printf("商标:");
		s_gets(temp[i].kind[1], SIZE);
		printf("净含量(ml/g):");
		s_gets(temp[i].kind[2], SIZE);
		printf("价格:");
		scanf("%f", &temp[i].prize);
		EATLINE;
		while (true)
		{
			printf("年:");
			scanf("%d", &temp[i].date[0]);
			EATLINE;
			printf("月:");
			scanf("%d", &temp[i].date[1]);
			EATLINE;
			printf("日:");
			scanf("%d", &temp[i].date[2]);
			EATLINE;
			tagDate date1;
			SetDate(temp[i].date[0], temp[i].date[1], temp[i].date[2], &date1);
			if (IsDateValid(date1) == 0)
				printf("您输入的年月日不合法,请重新输入:\n");
			else
				break;
		}
		printf("保质期:(单位:月)");
		scanf("%f", &temp[i].qgp);
		EATLINE;
		printf("/**名称:%-12s商标:%-12s净含量(ml/g):%-10s 价格:%4.1f      生产日期:%4d/%02d/%02d   保质期(月份):%5.1f**/\n",
			temp[i].kind[0], temp[i].kind[1], temp[i].kind[2], temp[i].prize, temp[i].date[0],
			temp[i].date[1], temp[i].date[2], temp[i].qgp);
		temp[i].judge_if_vacancy = 1;//设置商品已存在 
		temp[i].judge_if_overdue = 0;//设置商品为未过期 

		int x = 0;//判断该商品一行是否已满 
		int m = 0;
		int a_judge = 0;//判断是否装载好了饮料
		int ac_judge = 0;//当对空行投放好商品是值转为1
		for (; m < SIZE; m++)
		{
			int j = 0;
			for (; j < SIZE; j++)
			{
				if (leon[m][j].judge_if_vacancy == 1)
					if (judgeIsSameKind(leon[m][j], temp[i]) == true)//对于已存在的商品进行依次检索 
					{												//判断是否有相同名称的商品
						int q = 0;
						for (; q < SIZE; q++)
						{
							if (leon[m][q].judge_if_vacancy == 0)
							{
								leon[m][q] = temp[i];
								a_judge = 1;
								int x = 1;
								break;
							}
						}
						if (x == 1)
						{
							printf("每种商品最多装入30个,该商品已满\n无法装入,请继续添加下一个商品\n");
							break;
						}
						if (a_judge == 1)
							break;
					}

				if (m == SIZE - 1 && j == SIZE - 1)//对于与输入商品名称都不同的的商品进行检索 
				{

					for (m = 0; m < SIZE; m++)
					{
						int exit_vacant_line = 0;//如果不为空行,则改为1
						int j = 0;
						for (; j < SIZE; j++)//每一个结构体进行检索 
						{
							if (leon[m][j].judge_if_vacancy == 1)//如果该行存在物品 
							{
								exit_vacant_line = 1;
								break;
							}
						}
						if (exit_vacant_line == 0)//如果该行为空,则将该行第一个商品设置 
						{
							ac_judge = 1;
							leon[m][0] = temp[i];
							break;
						}
					}
					if (ac_judge == 1)
						break;
				}
			}
			if (ac_judge == 1 || a_judge == 1 || x == 1)
				break;
		}

	}
	printf("\n/*上架新商品模块关闭*/\n\n");
	free(temp);
}

void fetch(Goods leon[][SIZE])
{
	static Goods * overdue[SIZE*SIZE];
	int i = 0;
	for (; i < SIZE*SIZE; ++i)
		overdue[i] = NULL;
	int num = 0;
	for (i = 0; i < SIZE; i++)
	{
		int j = 0;
		for (; j < SIZE; j++)
		{
			if (leon[i][j].judge_if_vacancy == 1 && leon[i][j].judge_if_overdue == 1)
			{
				overdue[num] = &leon[i][j];
				num++;
			}
		}
	}

	if (num == 0)
		printf("不存在过期商品!\n");
	else
	{
		printf("请下架如下过期商品:\n");
		for (i = 0; i < num; i++)
		{
			printf("/**名称:%-12s商标:%-12s净含量(ml/g):%-10s 价格:%4.1f      生产日期:%4d/%02d/%02d   保质期(月份):%5.1f**/\n",
				overdue[i]->kind[0], overdue[i]->kind[1], overdue[i]->kind[2], overdue[i]->prize, overdue[i]->date[0],
				overdue[i]->date[1], overdue[i]->date[2], overdue[i]->qgp);
			overdue[i]->judge_if_overdue = 0;
			overdue[i]->judge_if_vacancy = 0;
		}
		puts("");
		int s = 0;//一个小小的等待函数
		for (; s < 3; s++)
		{
			printf("下架中");
			int j = 0;
			for (; j < 5; j++)
			{
				printf("。");
				Sleep(800);
			}
			for (j = 0; j < 16; j++)
				printf("\b");
			for (j = 0; j < 16; j++)
				printf(" ");
			for (j = 0; j < 16; j++)
				printf("\b");
		}

	}
	printf("\n/*下架过期商品模块关闭*/\n\n");
}

void bring(Goods leon[][SIZE])
{
	int exit = 0;//计算存在的商品数
	int m = 0;
	for (; m < SIZE; m++)
	{
		int j = 0;
		for (; j < SIZE; j++)
		{
			if (leon[m][j].judge_if_vacancy == 1 && leon[m][j].judge_if_overdue == 0)//客户可见内容
				exit++;
		}
	}
	printf("输入将下架的商品数量:");
	int num;
	while (scanf("%d", &num) != 1 || num < 0) //***********************************************注意正负数
	{
		printf("输入错误,请重新输入!  ");
		EATLINE;
	}
	EATLINE;
	if (num == 0)
	{
		printf("您将下架的商品数量为0\n");
	}
	else if (num > exit)
	{
		printf("您输入的下架商品数量已超过LEON售货机内已有未过期商品数\n");
	}
	else
	{
		Goods * temp = (Goods *)calloc(num, sizeof(Goods));
		int i = 0;
		for (; i < num; i++)
		{
			printf("名称:");
			s_gets(temp[i].kind[0], SIZE);
			printf("商标:");
			s_gets(temp[i].kind[1], SIZE);
			printf("净含量(ml/g):");
			s_gets(temp[i].kind[2], SIZE);
			printf("价格:");
			scanf("%f", &temp[i].prize);
			EATLINE;
			printf("保质期:");
			scanf("%f", &temp[i].qgp);
			EATLINE;
			while (true)
			{
				printf("年:");
				scanf("%d", &temp[i].date[0]);
				EATLINE;
				printf("月:");
				scanf("%d", &temp[i].date[1]);
				EATLINE;
				printf("日:");
				scanf("%d", &temp[i].date[2]);
				EATLINE;
				tagDate date1;
				SetDate(temp[i].date[0], temp[i].date[1], temp[i].date[2], &date1);
				if (IsDateValid(date1) == 0)
					printf("您输入的年月日不合法,请重新输入:\n");
				else
					break;
			}
			printf("/**名称:%-12s商标:%-12s净含量(ml/g):%-10s 价格:%4.1f      生产日期:%4d/%02d/%02d   保质期(月份):%5.1f**/\n",
				temp[i].kind[0], temp[i].kind[1], temp[i].kind[2], temp[i].prize, temp[i].date[0],
				temp[i].date[1], temp[i].date[2], temp[i].qgp);
			temp[i].judge_if_vacancy = 1;//设置商品已存在 
			temp[i].judge_if_overdue = 0;//设置商品为未过期 
			int judg = 0;//是否取出未过期商品,是为1,否为0
			int m = 0;
			for (; m < SIZE; m++)
			{
				int j = 0;
				for (; j < SIZE; j++)
				{
					if (leon[m][j].judge_if_vacancy == 1 && leon[m][j].judge_if_overdue == 0
						&& judgeIsSameKind(leon[m][j], temp[i]) == true && temp[i].date[0] == leon[m][j].date[0]
						&& temp[i].date[1] == leon[m][j].date[1] && temp[i].date[2] == leon[m][j].date[2]
						&& temp[i].qgp == leon[m][j].qgp && temp[i].prize == leon[m][j].prize)
					{
						printf("\n已取出该商品:\n");
						leon[m][j].judge_if_vacancy = 0;
						if (i != num - 1)
							printf("请取下一个商品:\n");
						judg = 1;
					}	
				}
			}
			if(judg == 0)
				printf("该未过期商品不存在\n请取下一个商品:\n");
		}
		free(temp);
	}
}

void check(Goods leon[][SIZE])
{
	printf("\nLEON自动售货机内现有面值及数量为:\n");
	printf("  (1.一角:   %2d    (2.五角:   %2d    (3.一元:   %2d  \n" , exit_face_num[0] , exit_face_num[1], exit_face_num[2] );
	printf("  (4.贰元:   %2d    (5.五元:   %2d    (6.十元:   %2d  \n", exit_face_num[3], exit_face_num[4], exit_face_num[5]);
	printf("(7.二十元:   %2d  (8.五十元:   %2d  (9.一百元:   %2d  \n", exit_face_num[6], exit_face_num[7], exit_face_num[8]);
	printf("\n是否确认更改数量?(输入是或否)     1)是     2)否   ");
	char tem[SIZE];
	while (s_gets(tem, SIZE))
	{
		if (strcmp(tem, "是") == false)
		{
			printf("\n是投入货币还是取出货币?(输入投或取或退出)     1)投     2)取     3)退出   ");
			while (s_gets(tem, SIZE))
			{
				if (strcmp(tem, "投") == false)
				{
					change_face_num(1);
					printf("\n请继续 (输入投或取或退出)     1)投     2)取     3)退出   ");
				}
				else if (strcmp(tem, "取") == false)
				{
					change_face_num(2);
					printf("\n请继续 (输入投或取或退出)     1)投     2)取     3)退出   ");
				}
				else if (strcmp(tem, "退出") == false)
					break;
				else
					printf("\n输入错误,请重新输入投取或退出!   ");
			}
			break;
		}
		else if (strcmp(tem, "否") == false)
			break;
		else
			printf("输入错误,请重新输入是否!\n");
	}
	printf("\n/*检查售货机纸币数量模块关闭*/\n\n");
}

void change_face_num(int judge)
{

	if (judge == 1)
	{
		Count * prev, *current;
		Count * head = NULL;
		int tem[9];
		printf("请输入每种面值(此处一角至一百元以1-9加以表示)将要投放的数量:\n");
		for (int i = 0; i < 9; i++)//将9个面值数量数据写入链表,构建链表
		{
			printf("  %d : ", i + 1);
			while (scanf("%d", &tem[i]) != 1)//未对负数进行防错设计
			{
				printf("  输入错误,请重新输入: ");
				EATLINE;
			}
			EATLINE;
			current = (Count*)malloc(sizeof(Count));
			if (head == NULL)
				head = current;
			else
				prev->next = current;
			current->next = NULL;
			current->count = tem[i];
			prev = current;
		}

		current = head;//检索链表内容,并对原LEON内含有的货币数量进行处理
		int vb = 0;
		while (current != NULL)
		{
			exit_face_num[vb] += current->count;
			vb++;
			current = current->next;
		}

		/*current = head;//完成任务,释放内存空间
		while (current != NULL) // 此处错误
		{
			current = head;
			head = current->next;
			free(current);
		}*/
		prev = head;
		while (prev)//完成任务,释放内存空间
		{
			current = prev->next;
			free(prev);
			prev = current;
		}
	}
	else if (judge == 2)
	{
		Count * prev, *current;
		Count * head = NULL;
		int tem[9];
		printf("请输入每种面值(此处一角至一百元以1-9加以表示)将要取出的数量:\n");
		for (int i = 0; i < 9; i++)//将9个面值数量数据写入链表,构建链表
		{
			printf("  %d : ", i + 1);
			while (scanf("%d", &tem[i]) != 1)//未对负数进行防错设计
			{
				printf("  输入错误,请重新输入: ");
				EATLINE;
			}
			EATLINE;
			while (tem[i] > exit_face_num[i])
			{
				printf("  LEON中仅有%d个,已无法取出指定数量!请查看后认真输入!  ", exit_face_num[i]);
				scanf("%d", &tem[i]);
				EATLINE;
			}
			current = (Count*)malloc(sizeof(Count));
			if (head == NULL)
				head = current;
			else
				prev->next = current;
			current->next = NULL;
			current->count = tem[i];
			prev = current;
		}

		current = head;//检索链表内容,并对原LEON内含有的货币数量进行处理
		int vb = 0;
		while (current != NULL)
		{
			exit_face_num[vb] -= current->count;
			vb++;
			current = current->next;
		}

		prev = head;
		while (prev)//完成任务,释放内存空间
		{
			current = prev->next;
			free(prev);
			prev = current;
		}

	}
	else
		printf("系统出错!\n");
	printf("\nLEON自动售货机内现有面值及数量为:\n");
	printf("  (1.一角:   %2d    (2.五角:   %2d    (3.一元:   %2d  \n", exit_face_num[0], exit_face_num[1], exit_face_num[2]);
	printf("  (4.贰元:   %2d    (5.五元:   %2d    (6.十元:   %2d  \n", exit_face_num[3], exit_face_num[4], exit_face_num[5]);
	printf("(7.二十元:   %2d  (8.五十元:   %2d  (9.一百元:   %2d  \n", exit_face_num[6], exit_face_num[7], exit_face_num[8]);
}

void prin_face_number(void)
{
	printf("\nLEON自动售货机内现有面值及数量为:\n");
	printf("  (1.一角:   %2d    (2.五角:   %2d    (3.一元:   %2d  \n", exit_face_num[0], exit_face_num[1], exit_face_num[2]);
	printf("  (4.贰元:   %2d    (5.五元:   %2d    (6.十元:   %2d  \n", exit_face_num[3], exit_face_num[4], exit_face_num[5]);
	printf("(7.二十元:   %2d  (8.五十元:   %2d  (9.一百元:   %2d  \n", exit_face_num[6], exit_face_num[7], exit_face_num[8]);
}