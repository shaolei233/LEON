#include "leon.h"

extern  Goods leon[SIZE][SIZE];
extern int exit_face_num[9];
static int money_num_calculate[9];//�ͻ�Ͷ���ֽ����Ŀ

//�˿͵���غ���
void purchase(int numb, Goods leon[][SIZE])
{	
	int a;
	if (numb == 0)
		;
	else
	{
		printf("\n������һ����Ҫ��������Ʒ��?");
		if (scanf("%d", &a) == 1)
		{
			EATLINE;
			int i = 0;
			for (i; i < a; i++)
			{
				printf("��%d����Ʒ:\n", i + 1);
				buy(leon);
			}
		}
		else
		{
			printf("�����������\n");
			EATLINE;
		}

	}
	if (a == 0)
		printf("������Ĺ�������Ϊ0\n");
	printf("����ϵͳ�ر�,�����������,�����ִ�в���!\n��л����֧��!\n");
}

void buy(Goods leon[][SIZE])//��ͬһ����Ʒ���й���
{
	char name[SIZE];//���� 
	char brand[SIZE];//�̱�
	char size[SIZE];//������ 
	printf("����:");
	s_gets(name, SIZE);
	printf("�̱�:");
	s_gets(brand, SIZE);
	printf("������(ml/g):");
	s_gets(size, SIZE);
	printf("����:");
	int number;
	while (scanf("%d", &number) != 1)
	{
		printf("������ĸ�ʽ����ȷ!\n");
		EATLINE;
	}
	EATLINE;
	if (number == 0)
		printf("�����������Ϊ0\n");
	else
	{
		int i = 0;
		int pu = 1;//�ж���Ǯ�Ƿ�ʧ��,ʧ��Ϊ2,�ɹ�Ϊ0 , δ֪Ϊ1
		char tem[SIZE];
		int exit_number = 0;//����Ʒʣ�����
		int judge_success = 0;//�ж��Ƿ���ɹ�,����Ϊ1,����Ϊ0
		int judge_exit = 0;//��Ʒ�Ƿ����,����Ϊ1,����Ϊ0
		int judge_num = 1;//��Ʒ����������Ϊ0,����Ϊ1
		for (; i < SIZE; i++)
		{
			int j = 0;
			for (; j < SIZE; j++)
			{
				if (leon[i][j].judge_if_vacancy == 1 && leon[i][j].judge_if_overdue == 0)//���LEON�Զ��������ϵĴ��ڵ�δ������Ʒ���м���
					if (strcmp(name, leon[i][j].kind[0]) == false && strcmp(brand, leon[i][j].kind[1]) == false
						&& strcmp(size, leon[i][j].kind[2]) == false) // ��LEON�Զ��������ϵĴ��ڵ���Ʒ����Ҫ��
					{
						judge_exit = 1;
						int u = j;
						for (u; u < SIZE; u++)
							if (strcmp(name, leon[i][u].kind[0]) == false && strcmp(brand, leon[i][u].kind[1]) == false
								&& strcmp(size, leon[i][u].kind[2]) == false && leon[i][u].judge_if_vacancy == 1
								&& leon[i][u].judge_if_overdue == 0) // ��LEON�Զ��������ϵĴ��ڵ���Ʒ����Ҫ��
								exit_number++;
						if (exit_number < number)
						{
							printf("�ܱ�Ǹ,����Ʒ������������\n");
							printf("����Ʒ��ϢΪ:\n");
							printf("/**����:%-12s�̱�:%-12s������(ml/g):%-10s �۸�:%4.1f      ��������:%4d/%02d/%02d   ������(�·�):%5.1f**/\n",
								leon[i][j].kind[0], leon[i][j].kind[1], leon[i][j].kind[2], leon[i][j].prize, leon[i][j].date[0],
								leon[i][j].date[1], leon[i][j].date[2], leon[i][j].qgp);
							printf("����%d��ʣ��\n", exit_number);
							judge_num = 0;
							break;
						}

						puts("");
						u = j;
						int desiration1 = number;
						for (u; u < SIZE; u++)
							if (strcmp(name, leon[i][u].kind[0]) == false && strcmp(brand, leon[i][u].kind[1]) == false
								&& strcmp(size, leon[i][u].kind[2]) == false && leon[i][u].judge_if_vacancy == 1
								&& leon[i][u].judge_if_overdue == 0) // ��LEON�Զ��������ϵĴ��ڵ���Ʒ����Ҫ��
							{
								if (desiration1 == 0)
									break;
								printf("/**����:%-12s�̱�:%-12s������(ml/g):%-10s �۸�:%4.1f      ��������:%4d/%02d/%02d   ������(�·�):%5.1f**/\n",
									leon[i][u].kind[0], leon[i][u].kind[1], leon[i][u].kind[2], leon[i][u].prize, leon[i][u].date[0],
									leon[i][u].date[1], leon[i][u].date[2], leon[i][u].qgp);
								desiration1--;
							}
						puts("");
						printf("�Ƿ�ȷ�Ϲ���?(�����ǻ��)     1)��     2)��\n");
						while (s_gets(tem, SIZE))
						{
							if (strcmp(tem, "��") == false)
							{
								pu = money(number * leon[i][j].prize);
								if (pu == 2)//��Ǯʧ��
									break;
								else
								{

									int s = 0;//һ��СС�ĵȴ�����
									if (pu != 0)
										for (; s < 3; s++)
										{
											printf("��������");
											int j = 0;
											for (; j < 3; j++)
											{
												printf("��");
												Sleep(900);
											}
											for (j = 0; j < 20; j++)
												printf("\b");
											for (j = 0; j < 20; j++)
												printf(" ");
											for (j = 0; j < 20; j++)
												printf("\b");
										}

									for (s = 0; s < 3; s++)//һ��СС�ĵȴ�����
									{
										printf("������");
										int j = 0;
										for (; j < 3; j++)
										{
											printf("��");
											Sleep(900);
										}
										for (j = 0; j < 16; j++)
											printf("\b");
										for (j = 0; j < 16; j++)
											printf(" ");
										for (j = 0; j < 16; j++)
											printf("\b");
									}
									printf("����Ʒ�ѳ���,�뼰ʱ��ȡ\n");
									puts("");

									u = j;
									int desiration2 = number;
									for (u; u < SIZE; u++)
										if (strcmp(name, leon[i][u].kind[0]) == false && strcmp(brand, leon[i][u].kind[1]) == false
											&& strcmp(size, leon[i][u].kind[2]) == false && leon[i][u].judge_if_vacancy == 1
											&& leon[i][u].judge_if_overdue == 0) // ��LEON�Զ��������ϵĴ��ڵ���Ʒ����Ҫ��
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
							else if (strcmp(tem, "��") == false)
							{
								printf("��ȡ������!\n");
								break;
							}
							else
								printf("�������,�����������Ƿ�!\n");
						}
						if (judge_success == 1 || strcmp(tem, "��") == false)
							break;
					}
					if (pu == 2)
						break;
			}
			if (judge_num == 0 || judge_success == 1 || strcmp(tem, "��") == false || pu == 2)
				break;
		}
	//�Ѽ������
	if (judge_exit == 0)
		printf("�ܱ�Ǹ,��Ҫ����ƷLEONû����\n");
	}	
}

int money(float total_prize)//�ú�������ͻ��Ѿ���ֽ�Ҿ�Ͷ����LEON��
{                            //����LEONҲʵ��������,����Ҫ��ϸ���,��Ӧ����LEONӲ������Ľӿ�
	int sr = 1;
	printf("\n����Ҫ֧��%3.1f Ԫ\n��ѡ��������Ӧ��ֵ��ֽ�һ�Ӳ�ҵ����ͺ�����:\n\n", total_prize);
	int c;
	//int money_num_calculate[9];
	for (int i = 0; i < 9; i++)
		money_num_calculate[i] = 0;
	float sum = 0;//������Ͷ����	
	/* ����Ļ�ϻ�һ�����˵� */
	printf("/**********ֽ/Ӳ����ֵϵͳ**********/\n");
	printf("  1:  һ��    2:  ���    3:  һԪ\n");
	printf("  4:  ��Ԫ    5:  ��Ԫ    6:  ʮԪ\n");
	printf("  7:  ��ʮԪ  8:  ��ʮԪ  9:  һ��Ԫ\n");
	printf("/************************************/\n\n");
	int judge = 0;//�ж��Ƿ�֧�����
	while (true)
	{
		printf("��ѡ������ҪͶ�����ֵѡ��:(����0��ʾ֧�����)");
		while (scanf("%d", &c) != 1)
		{
			printf("������������,���ٴ�����:(����0��ʾ֧�����)");
			EATLINE;
		}
		EATLINE;
		switch (c)
		{
		case 1:
			printf("��������ҪͶ���һ�ǵ�����:  ");
			while (scanf("%d", &money_num_calculate[0]) != 1)
			{
				printf("����������������,���ٴ�����: ");
				EATLINE;
			}
			sum += money_num_calculate[0] * 0.1;
			break;
		case 2:
			printf("��������ҪͶ�����ǵ�����:  ");
			while (scanf("%d", &money_num_calculate[1]) != 1)
			{
				printf("����������������,���ٴ�����: ");
				EATLINE;
			}
			sum += money_num_calculate[1] * 0.5;
			break;
		case 3:
			printf("��������ҪͶ���һԪ������:  ");
			while (scanf("%d", &money_num_calculate[2]) != 1)
			{
				printf("����������������,���ٴ�����: ");
				EATLINE;
			}
			sum += money_num_calculate[2] * 1;
			break;
		case 4:
			printf("��������ҪͶ��ķ�Ԫ������:  ");
			while (scanf("%d", &money_num_calculate[3]) != 1)
			{
				printf("����������������,���ٴ�����: ");
				EATLINE;
			}
			sum += money_num_calculate[3] * 2;
			break;
		case 5:
			printf("��������ҪͶ�����Ԫ������:  ");
			while (scanf("%d", &money_num_calculate[4]) != 1)
			{
				printf("����������������,���ٴ�����: ");
				EATLINE;
			}
			sum += money_num_calculate[4] * 5;
			break;
		case 6:
			printf("��������ҪͶ���ʮԪ������:  ");
			while (scanf("%d", &money_num_calculate[5]) != 1)
			{
				printf("����������������,���ٴ�����: ");
				EATLINE;
			}
			sum += money_num_calculate[5] * 10;
			break;
		case 7:
			printf("��������ҪͶ��Ķ�ʮԪ������:  ");
			while (scanf("%d", &money_num_calculate[6]) != 1)
			{
				printf("����������������,���ٴ�����: ");
				EATLINE;
			}
			sum += money_num_calculate[6] * 20;
			break;
		case 8:
			printf("��������ҪͶ�����ʮԪ������:  ");
			while (scanf("%d", &money_num_calculate[7]) != 1)
			{
				printf("����������������,���ٴ�����: ");
				EATLINE;
			}
			sum += money_num_calculate[7] * 50;
			break;
		case 9:
			printf("��������ҪͶ���һ��Ԫ������:  ");
			while (scanf("%d", &money_num_calculate[8]) != 1)
			{
				printf("����������������,���ٴ�����: ");
				EATLINE;
			}
			sum += money_num_calculate[8] * 100;
			break;
		case 0:
			judge = 1;
			for (int n = 0; n < 9; n++)
				exit_face_num[n] += money_num_calculate[n];
			printf("����Ͷ����ܽ��Ϊ:%5.1fԪ\n", sum);
			if (fabs(sum - total_prize) < 0.000001)
				printf("����Ͷ��ȼ۽��\n");
			else if (sum < total_prize)
			{
				printf("��Ͷ��Ľ���:%5.1fԪ\n�����Ͷ��\n", total_prize - sum);
				continue;
			}
			else
			{
				printf("����Ͷ���� <%5.1f > Ԫ \n", sum - total_prize);
				sr = give_change(sum - total_prize);//����ɹ�����0,ʧ�ܷ���2
				if (sr == 0)
				{
					sum = total_prize;
					int s = 0;//һ��СС�ĵȴ�����
					for (; s < 3; s++)
					{
						printf("������");
						int j = 0;
						for (; j < 3; j++)
						{
							printf("��");
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
			printf("������ֵ���벻��ȷ,����������\n");
			continue;
		}
		if ( (judge == 1 && fabs(sum - total_prize) < 0.000001 ) || sr == 2)
			break;
	}
	return sr;//����ʧ�ܷ���2,�ɹ�����0( ����1)
}

int give_change(float change)
{
	int face_value[9] = { 1,5,10,20,50,100,200,500,1000 };//ת��Ϊ�ǵ�λ
	int Change = (int)(change * 10);//ת��Ϊ�ǵ�λ
	int face_value_num[9] = { 0 };//Ҫ�����Ǯ
	int temp[9];//��Ϊexit_face_num�����Ʒ
	memcpy(temp, exit_face_num, 9 * sizeof(int));
	//�������߶������Ʒ,Ϊ��ʹ�·�ѭ�����¿�ʼ
	int tem[9];
	int face_value_num_temp[9];
	int Change1 = Change;
	
	const char * face[9] = { "һ��","���","һԪ","��Ԫ","��Ԫ","ʮԪ","��ʮԪ","��ʮԪ","һ��Ԫ" };
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
		printf("ϵͳ������,��ֵ�ֱ�Ϊ: ");
		int i;
		for (i = 0; i < 9; i++)
			if (face_value_num_temp[i] != 0)
				printf("%d��%s ", face_value_num_temp[i], face[i]);
		for (i = 0; i < 9; i++)
			exit_face_num[i] -= face_value_num_temp[i];
		puts("");
		return 0;
	}
	else
	{
		printf("���Ƿǳ���Ǹ,�����ڵ�ֽ�Ҳ�����,�޷�Ϊ������\n�����������˻���Ͷ���ֽ��!\n");
		for (int i = 0; i < 9; i++)
			exit_face_num[i] -= money_num_calculate[i];

		int s = 0;//һ��СС�ĵȴ�����
		for (; s < 3; s++)
		{
			printf("�˻���");
			int j = 0;
			for (; j < 3; j++)
			{
				printf("��");
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
		if (strcmp(*(ptr + j), "") == false && printf("���������Ľ���:(������з��˳�)") && s_gets(*(ptr + j), size))
			if (strcmp(*(ptr + j), "") == false)
				break;
}

char** complaint(void)
{
	static char comp[COMPSIZE][COMPSIZE];
	static int judge_first = 0;//�жϳ����Ƿ��ǵ�һ�δ�
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
		printf("/**********�Զ�������LEONͶ��ϵͳ**********/\n\n");
		printf("һ.����������Ͷ����Ʒ����\n");
		printf("   1:  ���������û�з�Ӧ\n");
		printf("   2:  ���۹��ڲ�Ʒ\n");
		printf("   3:  �����������ڸ���\n");
		printf("   4:  ��Ʒ����̫��\n");
		printf("��.����Ͷ����Ϣ\n");
		printf("   5:  ����Ͷ������\n");
		printf("��.��ϵ������Ա\n");
		printf("   ������Ա:С��\n");
		printf("   ��ϵ�绰:123456789\n");
		printf("��.�˳��Զ�������LEONͶ��ϵͳ\n");
		printf("    6:  �˳�\n\n");
		printf("/******************************************/\n");
		printf("�𾴵Ĺ˿�,������ϣ��������ʲô�ط���Ҫ�Ľ��Ը��õ�Ϊ���ṩ������(����������1-6)\n");
		int c;
		scanf("%d", &c);				/* ����ѡ���� */
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
			printf("���˳�!");
			break;
		default:
			printf("�������벻��ȷ,����������,��л���\n");
			system("pause");
			system("cls");
			continue;
		}
		if (c == 6)
			break;
		int vb = 0;
		for (; vb < 4; vb++)
			sprintf(comp[vb], "%d", temp[vb]);
		printf("�Ѽ�¼����Ͷ��!�������������ִ��\n\n");
		system("pause");
		system("cls");
	}
	printf("���ǻ�߳�Ϊ�����������ٵ�����,����ÿһ�佨�鶼�Ƕ��������İ���!\n");
	printf("лл���Ľ���!\n");
	return t;
}
