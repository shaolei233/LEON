#include "leon.h"

extern  Goods leon[SIZE][SIZE];
extern int exit_face_num[9];


//������Ա��غ���
void maintain(Goods leon[][SIZE], char ** complain_list, FILE *fp , FILE*fp2)
{
	printf("���������Ա��Կ:\n");
	char code[SIZE];
	s_gets(code, SIZE);
	if (strcmp(code, "12345") != false)
		printf("��Կ�������.\n");
	else
	{
		system("cls");
		puts("\n/****LEON�Զ�������������Ա��̨����ģ�鿪��****/\n");
		char nji[SIZE];
		printf("������Ҫ�ػ���?(0Ϊ��Ҫ,���������Ϊ����Ҫ)  ����:");
		s_gets(nji, SIZE);
		if (strcmp(nji, "0") == false)
		{
			printf("�����ر�now��֧�߳�\n");//�߳��Զ��ر�
			printf("�����ر�sign_goods__overdued��֧�߳�\n");
			printf("�Ƿ񱣴�LEONĿǰ����Ʒ��Ϣ?\n����\"�ǵ�\"������,�������벻����\n");
			char temp[SIZE];
			s_gets(temp, SIZE);
			if (strcmp(temp, "�ǵ�") == false)
			{
				rewind(fp);
				fwrite(leon, sizeof(Goods), SIZE*SIZE, fp);
				fwrite(exit_face_num, sizeof(int), 9, fp2);
				rewind(fp);
				printf("�ѱ���!\n");
			}
			else
				printf("δ����!\n");
			printf("LEON�Զ��ۻ��������ػ�!\n");
			int s = 0;//һ��СС�ĵȴ�����
			for (; s < 3; s++)
			{
				printf("�ػ���");
				int j = 0;
				for (; j < 3; j++)
				{
					printf("��");
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
			printf("�ۻ���Ϊ��!\n");
		}
		else
			printf("\r                                                             \n");
		printf("�ѽ���LEON��̨����\n\n/**LEON�Զ�������������Ա���¼�ģ�鿪��**/\n\n������Ҫ�������ʲô����?\n a)ȡ��������Ʒ   b)��������Ʒ  c)ȡ������δ������Ʒ  d)���ֽ������ \n(�س���Ϊ�˳�)������:");
		char choice[SIZE];
		while (s_gets(choice, SIZE) && strcmp(choice, "") != false)
		{
			if (strcmp(choice, "a") == false)
			{
				printf("\n/*�¼ܹ�����Ʒģ�鿪��*/\n\n");
				fetch(leon);
				puts("");
				if (0 == prin(leon, SERVER))
				{
					printf("\r                                                             \n");
					printf("�ۻ���Ϊ��!\n");
				}
				else
					printf("\r                                                             \n");
				printf("\n�����������,������:(�س���Ϊ�˳�) a)ȡ��������Ʒ   b)��������Ʒ    c)ȡ������δ������Ʒ  d)���ֽ������ ");
			}
			else if (strcmp(choice, "b") == false)
			{
				printf("\n/*�ϼ�����Ʒģ�鿪��*/\n\n");
				putOnSale(leon);
				puts("");
				if (0 == prin(leon, SERVER))
				{
					printf("\r                                                             \n");
					printf("�ۻ���Ϊ��!\n");
				}
				else
					printf("\r                                                             \n");
				printf("\n�����������,������:(�س���Ϊ�˳�) a)ȡ��������Ʒ   b)��������Ʒ    c)ȡ������δ������Ʒ  d)���ֽ������ ");
			}
			else if (strcmp(choice, "c") == false)
			{
				printf("\n/*�¼�����δ������Ʒģ�鿪��*/\n\n");
				bring(leon);
				puts("");
				if (0 == prin(leon, SERVER))
				{
					printf("\r                                                             \n");
					printf("�ۻ���Ϊ��!\n");
				}
				else
					printf("\r                                                             \n");
				printf("\n�����������,������:(�س���Ϊ�˳�) a)ȡ��������Ʒ   b)��������Ʒ    c)ȡ������δ������Ʒ  d)���ֽ������ ");
			}
			else if (strcmp(choice, "d") == false)
			{
				printf("\n/*����ۻ���ֽ������ģ�鿪��*/\n\n");
				check(leon);
				printf("\n�����������,������:(�س���Ϊ�˳�) a)ȡ��������Ʒ   b)��������Ʒ    c)ȡ������δ������Ʒ  d)���ֽ������ ");
			}
			else
				printf("�����ʽ����,����������:(�س���Ϊ�˳�)");
		}

		printf("\n����LEON�Զ���������������Ʒ��:\n");
		if (0 == prin(leon, SERVER))
		{
			printf("\r                                                             \n");
			printf("�ۻ���Ϊ��!\n");
		}
		else
			printf("\r                                                             \n");
		puts("\n\n/**LEON�Զ�������������Ա���¼�ģ��ر�**/\n\n");
		puts("/**LEON�Զ�������������Ա����Ͷ��ģ�鿪��**/\n");
		if (complain_list == NULL)
		{
			printf("\n���޿ͻ�Ͷ��!\n���������!\n\n");
			puts("\n/**LEON�Զ�������������Ա����Ͷ��ģ��ر�**/\n");
		}
		else
		{
			int gh = 0;//Ͷ����Ŀ����
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
				printf("\n���޿ͻ�Ͷ��!\n���������!\n\n");
				puts("\n/**LEON�Զ�������������Ա����Ͷ��ģ��ر�**/\n");
			}

			else
			{
				int numt = 0;//��¼�ͻ�Ͷ����Ŀ
				printf("�ͻ�Ͷ���о�����:\n\n");
				printf("һ�����ĸ�LEON�Զ��ۻ������������Ͷ��:\n\n");
				int d = 0;
				for (; d < COMPSIZE; d++)
				{
					if (d == 4)
						printf("\n�����ͻ�����Ͷ����Ŀ����:\n");
					if (d < 4)//�˴������޸�����!!!
					{
						if (strpbrk(complain_list[d], "123456789") != NULL)
						{
							if (d == 0)
								printf("   1:  ���������û�з�Ӧ      %s��\n", complain_list[d]);
							else if (d == 1)
								printf("   2:  ���۹��ڲ�Ʒ            %s��\n", complain_list[d]);
							else if (d == 2)
								printf("   3:  �����������ڸ���        %s��\n", complain_list[d]);
							else if (d == 3)
								printf("   4:  ��Ʒ����̫��            %s��\n", complain_list[d]);
						}
					}
					else
					{
						if (strcmp(complain_list[d], "") != false)
							printf("\n  %2d.  ֱ��Ͷ������:  %s\n", ++numt, complain_list[d]);
					}
				}
				printf("\n�о����,��Ҫ���иĽ�!\n\n");
				puts("\n/**LEON�Զ�������������Ա����Ͷ��ģ��ر�**/\n");
			}
		}
	}
	puts("\n/****LEON�Զ�������������Ա��̨����ģ��ر�****/\n");
}

void putOnSale(Goods leon[][SIZE])
{
	printf("�����뽫Ͷ�ŵ���Ʒ��Ŀ:");
	int number;
	while (scanf("%d", &number) != 1)
	{
		printf("�������,����������!  ");
		EATLINE;
	}
	EATLINE;
	Goods * temp = (Goods *)calloc(number, sizeof(Goods));
	int i = 0;
	for (; i < number; i++)
	{
		printf("����:");
		s_gets(temp[i].kind[0], SIZE);
		printf("�̱�:");
		s_gets(temp[i].kind[1], SIZE);
		printf("������(ml/g):");
		s_gets(temp[i].kind[2], SIZE);
		printf("�۸�:");
		scanf("%f", &temp[i].prize);
		EATLINE;
		while (true)
		{
			printf("��:");
			scanf("%d", &temp[i].date[0]);
			EATLINE;
			printf("��:");
			scanf("%d", &temp[i].date[1]);
			EATLINE;
			printf("��:");
			scanf("%d", &temp[i].date[2]);
			EATLINE;
			tagDate date1;
			SetDate(temp[i].date[0], temp[i].date[1], temp[i].date[2], &date1);
			if (IsDateValid(date1) == 0)
				printf("������������ղ��Ϸ�,����������:\n");
			else
				break;
		}
		printf("������:(��λ:��)");
		scanf("%f", &temp[i].qgp);
		EATLINE;
		printf("/**����:%-12s�̱�:%-12s������(ml/g):%-10s �۸�:%4.1f      ��������:%4d/%02d/%02d   ������(�·�):%5.1f**/\n",
			temp[i].kind[0], temp[i].kind[1], temp[i].kind[2], temp[i].prize, temp[i].date[0],
			temp[i].date[1], temp[i].date[2], temp[i].qgp);
		temp[i].judge_if_vacancy = 1;//������Ʒ�Ѵ��� 
		temp[i].judge_if_overdue = 0;//������ƷΪδ���� 

		int x = 0;//�жϸ���Ʒһ���Ƿ����� 
		int m = 0;
		int a_judge = 0;//�ж��Ƿ�װ�غ�������
		int ac_judge = 0;//���Կ���Ͷ�ź���Ʒ��ֵתΪ1
		for (; m < SIZE; m++)
		{
			int j = 0;
			for (; j < SIZE; j++)
			{
				if (leon[m][j].judge_if_vacancy == 1)
					if (judgeIsSameKind(leon[m][j], temp[i]) == true)//�����Ѵ��ڵ���Ʒ�������μ��� 
					{												//�ж��Ƿ�����ͬ���Ƶ���Ʒ
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
							printf("ÿ����Ʒ���װ��30��,����Ʒ����\n�޷�װ��,����������һ����Ʒ\n");
							break;
						}
						if (a_judge == 1)
							break;
					}

				if (m == SIZE - 1 && j == SIZE - 1)//������������Ʒ���ƶ���ͬ�ĵ���Ʒ���м��� 
				{

					for (m = 0; m < SIZE; m++)
					{
						int exit_vacant_line = 0;//�����Ϊ����,���Ϊ1
						int j = 0;
						for (; j < SIZE; j++)//ÿһ���ṹ����м��� 
						{
							if (leon[m][j].judge_if_vacancy == 1)//������д�����Ʒ 
							{
								exit_vacant_line = 1;
								break;
							}
						}
						if (exit_vacant_line == 0)//�������Ϊ��,�򽫸��е�һ����Ʒ���� 
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
	printf("\n/*�ϼ�����Ʒģ��ر�*/\n\n");
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
		printf("�����ڹ�����Ʒ!\n");
	else
	{
		printf("���¼����¹�����Ʒ:\n");
		for (i = 0; i < num; i++)
		{
			printf("/**����:%-12s�̱�:%-12s������(ml/g):%-10s �۸�:%4.1f      ��������:%4d/%02d/%02d   ������(�·�):%5.1f**/\n",
				overdue[i]->kind[0], overdue[i]->kind[1], overdue[i]->kind[2], overdue[i]->prize, overdue[i]->date[0],
				overdue[i]->date[1], overdue[i]->date[2], overdue[i]->qgp);
			overdue[i]->judge_if_overdue = 0;
			overdue[i]->judge_if_vacancy = 0;
		}
		puts("");
		int s = 0;//һ��СС�ĵȴ�����
		for (; s < 3; s++)
		{
			printf("�¼���");
			int j = 0;
			for (; j < 5; j++)
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
	printf("\n/*�¼ܹ�����Ʒģ��ر�*/\n\n");
}

void bring(Goods leon[][SIZE])
{
	int exit = 0;//������ڵ���Ʒ��
	int m = 0;
	for (; m < SIZE; m++)
	{
		int j = 0;
		for (; j < SIZE; j++)
		{
			if (leon[m][j].judge_if_vacancy == 1 && leon[m][j].judge_if_overdue == 0)//�ͻ��ɼ�����
				exit++;
		}
	}
	printf("���뽫�¼ܵ���Ʒ����:");
	int num;
	while (scanf("%d", &num) != 1 || num < 0) //***********************************************ע��������
	{
		printf("�������,����������!  ");
		EATLINE;
	}
	EATLINE;
	if (num == 0)
	{
		printf("�����¼ܵ���Ʒ����Ϊ0\n");
	}
	else if (num > exit)
	{
		printf("��������¼���Ʒ�����ѳ���LEON�ۻ���������δ������Ʒ��\n");
	}
	else
	{
		Goods * temp = (Goods *)calloc(num, sizeof(Goods));
		int i = 0;
		for (; i < num; i++)
		{
			printf("����:");
			s_gets(temp[i].kind[0], SIZE);
			printf("�̱�:");
			s_gets(temp[i].kind[1], SIZE);
			printf("������(ml/g):");
			s_gets(temp[i].kind[2], SIZE);
			printf("�۸�:");
			scanf("%f", &temp[i].prize);
			EATLINE;
			printf("������:");
			scanf("%f", &temp[i].qgp);
			EATLINE;
			while (true)
			{
				printf("��:");
				scanf("%d", &temp[i].date[0]);
				EATLINE;
				printf("��:");
				scanf("%d", &temp[i].date[1]);
				EATLINE;
				printf("��:");
				scanf("%d", &temp[i].date[2]);
				EATLINE;
				tagDate date1;
				SetDate(temp[i].date[0], temp[i].date[1], temp[i].date[2], &date1);
				if (IsDateValid(date1) == 0)
					printf("������������ղ��Ϸ�,����������:\n");
				else
					break;
			}
			printf("/**����:%-12s�̱�:%-12s������(ml/g):%-10s �۸�:%4.1f      ��������:%4d/%02d/%02d   ������(�·�):%5.1f**/\n",
				temp[i].kind[0], temp[i].kind[1], temp[i].kind[2], temp[i].prize, temp[i].date[0],
				temp[i].date[1], temp[i].date[2], temp[i].qgp);
			temp[i].judge_if_vacancy = 1;//������Ʒ�Ѵ��� 
			temp[i].judge_if_overdue = 0;//������ƷΪδ���� 
			int judg = 0;//�Ƿ�ȡ��δ������Ʒ,��Ϊ1,��Ϊ0
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
						printf("\n��ȡ������Ʒ:\n");
						leon[m][j].judge_if_vacancy = 0;
						if (i != num - 1)
							printf("��ȡ��һ����Ʒ:\n");
						judg = 1;
					}	
				}
			}
			if(judg == 0)
				printf("��δ������Ʒ������\n��ȡ��һ����Ʒ:\n");
		}
		free(temp);
	}
}

void check(Goods leon[][SIZE])
{
	printf("\nLEON�Զ��ۻ�����������ֵ������Ϊ:\n");
	printf("  (1.һ��:   %2d    (2.���:   %2d    (3.һԪ:   %2d  \n" , exit_face_num[0] , exit_face_num[1], exit_face_num[2] );
	printf("  (4.��Ԫ:   %2d    (5.��Ԫ:   %2d    (6.ʮԪ:   %2d  \n", exit_face_num[3], exit_face_num[4], exit_face_num[5]);
	printf("(7.��ʮԪ:   %2d  (8.��ʮԪ:   %2d  (9.һ��Ԫ:   %2d  \n", exit_face_num[6], exit_face_num[7], exit_face_num[8]);
	printf("\n�Ƿ�ȷ�ϸ�������?(�����ǻ��)     1)��     2)��   ");
	char tem[SIZE];
	while (s_gets(tem, SIZE))
	{
		if (strcmp(tem, "��") == false)
		{
			printf("\n��Ͷ����һ���ȡ������?(����Ͷ��ȡ���˳�)     1)Ͷ     2)ȡ     3)�˳�   ");
			while (s_gets(tem, SIZE))
			{
				if (strcmp(tem, "Ͷ") == false)
				{
					change_face_num(1);
					printf("\n����� (����Ͷ��ȡ���˳�)     1)Ͷ     2)ȡ     3)�˳�   ");
				}
				else if (strcmp(tem, "ȡ") == false)
				{
					change_face_num(2);
					printf("\n����� (����Ͷ��ȡ���˳�)     1)Ͷ     2)ȡ     3)�˳�   ");
				}
				else if (strcmp(tem, "�˳�") == false)
					break;
				else
					printf("\n�������,����������Ͷȡ���˳�!   ");
			}
			break;
		}
		else if (strcmp(tem, "��") == false)
			break;
		else
			printf("�������,�����������Ƿ�!\n");
	}
	printf("\n/*����ۻ���ֽ������ģ��ر�*/\n\n");
}

void change_face_num(int judge)
{

	if (judge == 1)
	{
		Count * prev, *current;
		Count * head = NULL;
		int tem[9];
		printf("������ÿ����ֵ(�˴�һ����һ��Ԫ��1-9���Ա�ʾ)��ҪͶ�ŵ�����:\n");
		for (int i = 0; i < 9; i++)//��9����ֵ��������д������,��������
		{
			printf("  %d : ", i + 1);
			while (scanf("%d", &tem[i]) != 1)//δ�Ը������з������
			{
				printf("  �������,����������: ");
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

		current = head;//������������,����ԭLEON�ں��еĻ����������д���
		int vb = 0;
		while (current != NULL)
		{
			exit_face_num[vb] += current->count;
			vb++;
			current = current->next;
		}

		/*current = head;//�������,�ͷ��ڴ�ռ�
		while (current != NULL) // �˴�����
		{
			current = head;
			head = current->next;
			free(current);
		}*/
		prev = head;
		while (prev)//�������,�ͷ��ڴ�ռ�
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
		printf("������ÿ����ֵ(�˴�һ����һ��Ԫ��1-9���Ա�ʾ)��Ҫȡ��������:\n");
		for (int i = 0; i < 9; i++)//��9����ֵ��������д������,��������
		{
			printf("  %d : ", i + 1);
			while (scanf("%d", &tem[i]) != 1)//δ�Ը������з������
			{
				printf("  �������,����������: ");
				EATLINE;
			}
			EATLINE;
			while (tem[i] > exit_face_num[i])
			{
				printf("  LEON�н���%d��,���޷�ȡ��ָ������!��鿴����������!  ", exit_face_num[i]);
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

		current = head;//������������,����ԭLEON�ں��еĻ����������д���
		int vb = 0;
		while (current != NULL)
		{
			exit_face_num[vb] -= current->count;
			vb++;
			current = current->next;
		}

		prev = head;
		while (prev)//�������,�ͷ��ڴ�ռ�
		{
			current = prev->next;
			free(prev);
			prev = current;
		}

	}
	else
		printf("ϵͳ����!\n");
	printf("\nLEON�Զ��ۻ�����������ֵ������Ϊ:\n");
	printf("  (1.һ��:   %2d    (2.���:   %2d    (3.һԪ:   %2d  \n", exit_face_num[0], exit_face_num[1], exit_face_num[2]);
	printf("  (4.��Ԫ:   %2d    (5.��Ԫ:   %2d    (6.ʮԪ:   %2d  \n", exit_face_num[3], exit_face_num[4], exit_face_num[5]);
	printf("(7.��ʮԪ:   %2d  (8.��ʮԪ:   %2d  (9.һ��Ԫ:   %2d  \n", exit_face_num[6], exit_face_num[7], exit_face_num[8]);
}

void prin_face_number(void)
{
	printf("\nLEON�Զ��ۻ�����������ֵ������Ϊ:\n");
	printf("  (1.һ��:   %2d    (2.���:   %2d    (3.һԪ:   %2d  \n", exit_face_num[0], exit_face_num[1], exit_face_num[2]);
	printf("  (4.��Ԫ:   %2d    (5.��Ԫ:   %2d    (6.ʮԪ:   %2d  \n", exit_face_num[3], exit_face_num[4], exit_face_num[5]);
	printf("(7.��ʮԪ:   %2d  (8.��ʮԪ:   %2d  (9.һ��Ԫ:   %2d  \n", exit_face_num[6], exit_face_num[7], exit_face_num[8]);
}