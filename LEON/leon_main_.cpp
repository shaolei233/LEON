#include "leon.h"
/*
1.����Ŀ�Ѷ�LEON�Զ������������˳�ʼ��Ʒ,��ʼ��������¼��
2.����Ŀʹ�ö�ά����������ݴ洢
3.����Ŀ������1557��
*/

 Goods leon[SIZE][SIZE];//�Ѽٶ��������������30���������Ʒ,ÿ����Ʒ�����30��
 int exit_face_num[9];// �ʼ���Զ��������ڵĲ�ͬ��ֵ��ֽ������ = {10 , 2 , 2 , 1 , 1, 1 , 1 , 0, 0}

int main()
{
	FILE * fp;
	FILE * fp2;
	if ((fp = fopen("LEON Management Operation System", "rb+")) == NULL)
	{
		fprintf(stdout, "�޷��� \"LEON Management Operation System\"�ļ�\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	if ((fp2 = fopen("The Balance Of LEON Management Operation System", "rb+")) == NULL)
	{
		fprintf(stdout, "�޷��� \"The Balance Of LEON Management Operation System\"�ļ�\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp2);
	printf("�Ѵ���/��\"LEON Management Operation System\"�ļ�,����ʼִ��.\n\n");
	printf("�Ѵ���/��\"The Balance Of LEON Management Operation System\"�ļ�,����ʼִ��.\n\n");
	initialize(leon, fp);
	initial_face_num(exit_face_num, fp2);//!stream.has_any_of(IOREAD) consecutive write and read ��������ô����
	//std::thread now(shread_show_now);
	//Sleep(1000);
	rewind(fp);
	rewind(fp2);
	std::thread sign_overdued(shread_sign_overdue, leon , fp);
	printf("��ȴ�5��,������׼�����");
	//һ��СС�ĵȴ�����,Ϊ�ȴ�main�е�sign_overdued�����Թ�����Ʒ�����
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
