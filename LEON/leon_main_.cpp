#include "leon.h"
/*
1.本项目已对LEON自动售卖机进行了初始商品,初始货币数量录入
2.本项目使用二维数组进行数据存储
3.本项目行数共1557行
*/

 Goods leon[SIZE][SIZE];//已假定该售卖机最多存放30个种类的商品,每种商品最多存放30个
 int exit_face_num[9];// 最开始的自动售卖机内的不同面值的纸币数量 = {10 , 2 , 2 , 1 , 1, 1 , 1 , 0, 0}

int main()
{
	FILE * fp;
	FILE * fp2;
	if ((fp = fopen("LEON Management Operation System", "rb+")) == NULL)
	{
		fprintf(stdout, "无法打开 \"LEON Management Operation System\"文件\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	if ((fp2 = fopen("The Balance Of LEON Management Operation System", "rb+")) == NULL)
	{
		fprintf(stdout, "无法打开 \"The Balance Of LEON Management Operation System\"文件\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp2);
	printf("已创建/打开\"LEON Management Operation System\"文件,程序开始执行.\n\n");
	printf("已创建/打开\"The Balance Of LEON Management Operation System\"文件,程序开始执行.\n\n");
	initialize(leon, fp);
	initial_face_num(exit_face_num, fp2);//!stream.has_any_of(IOREAD) consecutive write and read 究竟是怎么回事
	//std::thread now(shread_show_now);
	//Sleep(1000);
	rewind(fp);
	rewind(fp2);
	std::thread sign_overdued(shread_sign_overdue, leon , fp);
	printf("请等待5秒,待程序准备完毕");
	//一个小小的等待函数,为等待main中的sign_overdued函数对过期商品做标记
	int q = 0;
	Sleep(1000);
	int j = 0;
	for (j; j < 18; j++)
		printf("\b");
	for (; q < 5; q++)
	{
		printf("%d\b", 5 - q - 1);
		Sleep(1000);
	}
	puts("");
	system("cls");
	menu(leon , fp , fp2);
	fclose(fp);
	fclose(fp2);
	system("pause");
	return 0;
}
