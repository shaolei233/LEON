#include "leon.h"

extern  Goods leon[SIZE][SIZE];
extern int exit_face_num[9];
static int money_num_calculate[9];//客户投入的纸币数目

//顾客的相关函数
void purchase(int numb, Goods leon[][SIZE])
{	
	int a;
	if (numb == 0)
		;
	else
	{
		printf("\n请问您一共需要购买几种商品呢?");
		if (scanf("%d", &a) == 1)
		{
			EATLINE;
			int i = 0;
			for (i; i < a; i++)
			{
				printf("第%d种商品:\n", i + 1);
				buy(leon);
			}
		}
		else
		{
			printf("您的输入错误\n");
			EATLINE;
		}

	}
	if (a == 0)
		printf("您输入的购买数量为0\n");
	printf("购买系统关闭,如需继续购买,请继续执行操作!\n感谢您的支持!\n");
}

void buy(Goods leon[][SIZE])//对同一类商品进行购买
{
	char name[SIZE];//名称 
	char brand[SIZE];//商标
	char size[SIZE];//净含量 
	printf("名称:");
	s_gets(name, SIZE);
	printf("商标:");
	s_gets(brand, SIZE);
	printf("净含量(ml/g):");
	s_gets(size, SIZE);
	printf("数量:");
	int number;
	while (scanf("%d", &number) != 1)
	{
		printf("您输入的格式不正确!\n");
		EATLINE;
	}
	EATLINE;
	if (number == 0)
		printf("您输入的数量为0\n");
	else
	{
		int i = 0;
		int pu = 1;//判断找钱是否失败,失败为2,成功为0 , 未知为1
		char tem[SIZE];
		int exit_number = 0;//该商品剩余个数
		int judge_success = 0;//判断是否购买成功,是则为1,否则为0
		int judge_exit = 0;//商品是否存在,存在为1,否则为0
		int judge_num = 1;//商品数量不够则为0,否则为1
		for (; i < SIZE; i++)
		{
			int j = 0;
			for (; j < SIZE; j++)
			{
				if (leon[i][j].judge_if_vacancy == 1 && leon[i][j].judge_if_overdue == 0)//针对LEON自动售卖机上的存在的未过期商品进行检索
					if (strcmp(name, leon[i][j].kind[0]) == false && strcmp(brand, leon[i][j].kind[1]) == false
						&& strcmp(size, leon[i][j].kind[2]) == false) // 若LEON自动售卖机上的存在的商品符合要求
					{
						judge_exit = 1;
						int u = j;
						for (u; u < SIZE; u++)
							if (strcmp(name, leon[i][u].kind[0]) == false && strcmp(brand, leon[i][u].kind[1]) == false
								&& strcmp(size, leon[i][u].kind[2]) == false && leon[i][u].judge_if_vacancy == 1
								&& leon[i][u].judge_if_overdue == 0) // 若LEON自动售卖机上的存在的商品符合要求
								exit_number++;
						if (exit_number < number)
						{
							printf("很抱歉,该商品的数量不够了\n");
							printf("该商品信息为:\n");
							printf("/**名称:%-12s商标:%-12s净含量(ml/g):%-10s 价格:%4.1f      生产日期:%4d/%02d/%02d   保质期(月份):%5.1f**/\n",
								leon[i][j].kind[0], leon[i][j].kind[1], leon[i][j].kind[2], leon[i][j].prize, leon[i][j].date[0],
								leon[i][j].date[1], leon[i][j].date[2], leon[i][j].qgp);
							printf("仅有%d个剩余\n", exit_number);
							judge_num = 0;
							break;
						}

						puts("");
						u = j;
						int desiration1 = number;
						for (u; u < SIZE; u++)
							if (strcmp(name, leon[i][u].kind[0]) == false && strcmp(brand, leon[i][u].kind[1]) == false
								&& strcmp(size, leon[i][u].kind[2]) == false && leon[i][u].judge_if_vacancy == 1
								&& leon[i][u].judge_if_overdue == 0) // 若LEON自动售卖机上的存在的商品符合要求
							{
								if (desiration1 == 0)
									break;
								printf("/**名称:%-12s商标:%-12s净含量(ml/g):%-10s 价格:%4.1f      生产日期:%4d/%02d/%02d   保质期(月份):%5.1f**/\n",
									leon[i][u].kind[0], leon[i][u].kind[1], leon[i][u].kind[2], leon[i][u].prize, leon[i][u].date[0],
									leon[i][u].date[1], leon[i][u].date[2], leon[i][u].qgp);
								desiration1--;
							}
						puts("");
						printf("是否确认购买?(输入是或否)     1)是     2)否\n");
						while (s_gets(tem, SIZE))
						{
							if (strcmp(tem, "是") == false)
							{
								pu = money(number * leon[i][j].prize);
								if (pu == 2)//找钱失败
									break;
								else
								{

									int s = 0;//一个小小的等待函数
									if (pu != 0)
										for (; s < 3; s++)
										{
											printf("处理金额中");
											int j = 0;
											for (; j < 3; j++)
											{
												printf("。");
												Sleep(900);
											}
											for (j = 0; j < 20; j++)
												printf("\b");
											for (j = 0; j < 20; j++)
												printf(" ");
											for (j = 0; j < 20; j++)
												printf("\b");
										}

									for (s = 0; s < 3; s++)//一个小小的等待函数
									{
										printf("出货中");
										int j = 0;
										for (; j < 3; j++)
										{
											printf("。");
											Sleep(900);
										}
										for (j = 0; j < 16; j++)
											printf("\b");
										for (j = 0; j < 16; j++)
											printf(" ");
										for (j = 0; j < 16; j++)
											printf("\b");
									}
									printf("该商品已出货,请及时拿取\n");
									puts("");

									u = j;
									int desiration2 = number;
									for (u; u < SIZE; u++)
										if (strcmp(name, leon[i][u].kind[0]) == false && strcmp(brand, leon[i][u].kind[1]) == false
											&& strcmp(size, leon[i][u].kind[2]) == false && leon[i][u].judge_if_vacancy == 1
											&& leon[i][u].judge_if_overdue == 0) // 若LEON自动售卖机上的存在的商品符合要求
										{
											if (desiration2 == 0)
												break;
											leon[i][u].judge_if_vacancy = 0;
											desiration2--;
										}
									judge_success = 1;
									break;
								}
							}
							else if (strcmp(tem, "否") == false)
							{
								printf("已取消购买!\n");
								break;
							}
							else
								printf("输入错误,请重新输入是否!\n");
						}
						if (judge_success == 1 || strcmp(tem, "否") == false)
							break;
					}
					if (pu == 2)
						break;
			}
			if (judge_num == 0 || judge_success == 1 || strcmp(tem, "否") == false || pu == 2)
				break;
		}
	//已检索完毕
	if (judge_exit == 0)
		printf("很抱歉,您要的商品LEON没有了\n");
	}	
}

int money(float total_prize)//该函数假设客户已经将纸币均投入了LEON中
{                            //并且LEON也实现了找零,若需要详细设计,则应引入LEON硬件方面的接口
	int sr = 1;
	printf("\n您需要支付%3.1f 元\n请选择以下相应面值的纸币或硬币的类型和数量:\n\n", total_prize);
	int c;
	//int money_num_calculate[9];
	for (int i = 0; i < 9; i++)
		money_num_calculate[i] = 0;
	float sum = 0;//计算总投入金额	
	/* 在屏幕上画一个主菜单 */
	printf("/**********纸/硬币面值系统**********/\n");
	printf("  1:  一角    2:  五角    3:  一元\n");
	printf("  4:  贰元    5:  五元    6:  十元\n");
	printf("  7:  贰十元  8:  伍十元  9:  一百元\n");
	printf("/************************************/\n\n");
	int judge = 0;//判断是否支付金额
	while (true)
	{
		printf("请选择所需要投入的面值选项:(输入0表示支付完成)");
		while (scanf("%d", &c) != 1)
		{
			printf("您的输入有误,请再次输入:(输入0表示支付完成)");
			EATLINE;
		}
		EATLINE;
		switch (c)
		{
		case 1:
			printf("请输入您要投入的一角的数量:  ");
			while (scanf("%d", &money_num_calculate[0]) != 1)
			{
				printf("您的数量输入有误,请再次输入: ");
				EATLINE;
			}
			sum += money_num_calculate[0] * 0.1;
			break;
		case 2:
			printf("请输入您要投入的五角的数量:  ");
			while (scanf("%d", &money_num_calculate[1]) != 1)
			{
				printf("您的数量输入有误,请再次输入: ");
				EATLINE;
			}
			sum += money_num_calculate[1] * 0.5;
			break;
		case 3:
			printf("请输入您要投入的一元的数量:  ");
			while (scanf("%d", &money_num_calculate[2]) != 1)
			{
				printf("您的数量输入有误,请再次输入: ");
				EATLINE;
			}
			sum += money_num_calculate[2] * 1;
			break;
		case 4:
			printf("请输入您要投入的贰元的数量:  ");
			while (scanf("%d", &money_num_calculate[3]) != 1)
			{
				printf("您的数量输入有误,请再次输入: ");
				EATLINE;
			}
			sum += money_num_calculate[3] * 2;
			break;
		case 5:
			printf("请输入您要投入的五元的数量:  ");
			while (scanf("%d", &money_num_calculate[4]) != 1)
			{
				printf("您的数量输入有误,请再次输入: ");
				EATLINE;
			}
			sum += money_num_calculate[4] * 5;
			break;
		case 6:
			printf("请输入您要投入的十元的数量:  ");
			while (scanf("%d", &money_num_calculate[5]) != 1)
			{
				printf("您的数量输入有误,请再次输入: ");
				EATLINE;
			}
			sum += money_num_calculate[5] * 10;
			break;
		case 7:
			printf("请输入您要投入的二十元的数量:  ");
			while (scanf("%d", &money_num_calculate[6]) != 1)
			{
				printf("您的数量输入有误,请再次输入: ");
				EATLINE;
			}
			sum += money_num_calculate[6] * 20;
			break;
		case 8:
			printf("请输入您要投入的五十元的数量:  ");
			while (scanf("%d", &money_num_calculate[7]) != 1)
			{
				printf("您的数量输入有误,请再次输入: ");
				EATLINE;
			}
			sum += money_num_calculate[7] * 50;
			break;
		case 9:
			printf("请输入您要投入的一百元的数量:  ");
			while (scanf("%d", &money_num_calculate[8]) != 1)
			{
				printf("您的数量输入有误,请再次输入: ");
				EATLINE;
			}
			sum += money_num_calculate[8] * 100;
			break;
		case 0:
			judge = 1;
			for (int n = 0; n < 9; n++)
				exit_face_num[n] += money_num_calculate[n];
			printf("您已投入的总金额为:%5.1f元\n", sum);
			if (fabs(sum - total_prize) < 0.000001)
				printf("您已投入等价金额\n");
			else if (sum < total_prize)
			{
				printf("您投入的金额还差:%5.1f元\n请继续投入\n", total_prize - sum);
				continue;
			}
			else
			{
				printf("您多投入了 <%5.1f > 元 \n", sum - total_prize);
				sr = give_change(sum - total_prize);//找零成功返回0,失败返回2
				if (sr == 0)
				{
					sum = total_prize;
					int s = 0;//一个小小的等待函数
					for (; s < 3; s++)
					{
						printf("找零中");
						int j = 0;
						for (; j < 3; j++)
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
			}
			break;
		default:
			printf("您的面值输入不正确,请重新输入\n");
			continue;
		}
		if ( (judge == 1 && fabs(sum - total_prize) < 0.000001 ) || sr == 2)
			break;
	}
	return sr;//找零失败返回2,成功返回0( 返回1)
}

int give_change(float change)
{
	int face_value[9] = { 1,5,10,20,50,100,200,500,1000 };//转换为角单位
	int Change = (int)(change * 10);//转换为角单位
	int face_value_num[9] = { 0 };//要找零的钱
	int temp[9];//作为exit_face_num的替代品
	memcpy(temp, exit_face_num, 9 * sizeof(int));
	//以下三者都是替代品,为促使下方循环从新开始
	int tem[9];
	int face_value_num_temp[9];
	int Change1 = Change;
	
	const char * face[9] = { "一角","五角","一元","贰元","五元","十元","二十元","五十元","一百元" };
	for (int j = 0; j < 9; j++)
	{
		Change1 = Change;
		memcpy(tem, temp , 9 * sizeof(int));
		memcpy(face_value_num_temp, face_value_num , 9 * sizeof(int));
		int i = j;
		for (; i < 9; i++)
		{
			while (tem[8 - i] != 0)
			{
				if (Change1 / face_value[8 - i])
				{
					Change1 -= face_value[8 - i];
					tem[8 - i]--;
					face_value_num_temp[8 - i] ++;
				}
				else
					break;
			}
		}
		if (Change1 == 0 || i == 8)
			break;
	}
	if (Change1 == 0)
	{
		printf("系统将找零,面值分别为: ");
		int i;
		for (i = 0; i < 9; i++)
			if (face_value_num_temp[i] != 0)
				printf("%d个%s ", face_value_num_temp[i], face[i]);
		for (i = 0; i < 9; i++)
			exit_face_num[i] -= face_value_num_temp[i];
		puts("");
		return 0;
	}
	else
	{
		printf("我们非常抱歉,机器内的纸币不够了,无法为您找零\n机器将立刻退还您投入的纸币!\n");
		for (int i = 0; i < 9; i++)
			exit_face_num[i] -= money_num_calculate[i];

		int s = 0;//一个小小的等待函数
		for (; s < 3; s++)
		{
			printf("退还中");
			int j = 0;
			for (; j < 3; j++)
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
		return 2;
	}
}

void inputComp(char ** ptr, int size)
{
	int j = 4;
	for (j; j < size; j++)
		if (strcmp(*(ptr + j), "") == false && printf("请输入您的建议:(点击换行符退出)") && s_gets(*(ptr + j), size))
			if (strcmp(*(ptr + j), "") == false)
				break;
}

char** complaint(void)
{
	static char comp[COMPSIZE][COMPSIZE];
	static int judge_first = 0;//判断程序是否是第一次打开
	judge_first++;
	int p = 0;
	static int temp[4] = { 0,0,0,0 };
	static char * t[COMPSIZE];
	for (; p < COMPSIZE; p++)
		t[p] = comp[p];
	if (judge_first == 1)
	{
		p = 0;
		for (; p < COMPSIZE; p++)
			strcpy(t[p], "");
	}


	while (true)
	{
		printf("/**********自动售卖机LEON投诉系统**********/\n\n");
		printf("一.机器质量及投放商品问题\n");
		printf("   1:  机器付款后没有反应\n");
		printf("   2:  出售过期产品\n");
		printf("   3:  机器操作过于复杂\n");
		printf("   4:  商品种类太少\n");
		printf("二.发送投诉信息\n");
		printf("   5:  输入投诉内容\n");
		printf("三.联系工作人员\n");
		printf("   工作人员:小明\n");
		printf("   联系电话:123456789\n");
		printf("四.退出自动售卖机LEON投诉系统\n");
		printf("    6:  退出\n\n");
		printf("/******************************************/\n");
		printf("尊敬的顾客,请问您希望我们在什么地方需要改进以更好地为您提供服务呢(请输入数字1-6)\n");
		int c;
		scanf("%d", &c);				/* 输入选择项 */
		EATLINE;
		switch (c)
		{
		case 1:
			temp[0]++;
			break;
		case 2:
			temp[1]++;
			break;
		case 3:
			temp[2]++;
			break;
		case 4:
			temp[3]++;
			break;
		case 5:
			inputComp(t, COMPSIZE);
			break;
		case 6:
			printf("已退出!");
			break;
		default:
			printf("您的输入不正确,请重新输入,感谢配合\n");
			system("pause");
			system("cls");
			continue;
		}
		if (c == 6)
			break;
		int vb = 0;
		for (; vb < 4; vb++)
			sprintf(comp[vb], "%d", temp[vb]);
		printf("已记录您的投诉!请点击任意键继续执行\n\n");
		system("pause");
		system("cls");
	}
	printf("我们会竭诚为您处理您面临的问题,您的每一句建议都是对我们最大的帮助!\n");
	printf("谢谢您的建议!\n");
	return t;
}
