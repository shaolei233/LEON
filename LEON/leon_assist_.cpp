#include "leon.h"

extern  Goods leon[SIZE][SIZE];
extern int exit_face_num[9];

//���ָ�������,ר�����жϼ��ַ�������
int judgeIsSameKind(Goods a, Goods b)
{
	if (strcmp(a.kind[0], b.kind[0]) == false)
		if (strcmp(a.kind[1], b.kind[1]) == false)
			if (strcmp(a.kind[2], b.kind[2]) == false)
				return true;
	return false;
}

int s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return true;
}

void shread_show_now(void)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//��þ��
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	COORD coordScreen = { 80 , 0 };//�����λ��(ʱ����ʾλ����ִ��������ʱλ�ý����л�)	
	tm * ltm;
	while (true)
	{
		GetConsoleScreenBufferInfo(hConsole, &bInfo);
		time_t now = time(0);
		ltm = localtime(&now);// ��� ltm �ṹ�ĸ�����ɲ���
		COORD coordScreen = { 80 , 0 };
		SetConsoleCursorPosition(hConsole, coordScreen);
		std::cout << "��ǰʱ��:" << 1900 + ltm->tm_year << "��" << std::setfill('0') << std::setw(2)
			<< 1 + ltm->tm_mon << "��" << std::setw(2) << ltm->tm_mday << "��" << std::setw(2) << ltm->tm_hour << ":"
			<< std::setw(2) << ltm->tm_min << ":" << std::setw(2) << ltm->tm_sec;
		coordScreen = { bInfo.dwCursorPosition.X ,bInfo.dwCursorPosition.Y };
		SetConsoleCursorPosition(hConsole, coordScreen);
		Sleep(984);//ǰ������ʱ��16ms
	}

}

void shread_sign_overdue(Goods leon[][SIZE], FILE * fp)
{
	tagDate date1, date2;
	while (true)
	{
		int i = 0;
		for (; i < SIZE; i++)
		{
			int j = 0;
			for (; j < SIZE; j++)
			{
				if (leon[i][j].judge_if_vacancy == 1 && leon[i][j].judge_if_overdue == 0)//��ÿһ�����ڵ���δ���ڵ���Ʒ���д���
				{
					tm * ltm;
					time_t now = time(0);
					ltm = localtime(&now);// ��� ltm �ṹ�ĸ�����ɲ���
					SetDate(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, &date1);
					//printf("\n����:%d   %d   %d  \n", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
					SetDate(leon[i][j].date[0], leon[i][j].date[1], leon[i][j].date[2], &date2);
					//printf("\n��ȥ%d   %d   %d  \n", leon[i][j].date[0], leon[i][j].date[1], leon[i][j].date[2]);
					if ( (int)(leon[i][j].qgp * 30) < DateDiff(date1, date2))
					{
						leon[i][j].judge_if_overdue = 1;
						//printf("�����˹���!\n");�Ϸ��������ڼ��ú����Ƿ�ʵ���˹��ڻ�ʳƷ����ʶ
					}
				}
			}
		}
		rewind(fp);
		fwrite(leon, SIZE*SIZE, sizeof(Goods), fp);
		rewind(fp);
		Sleep(1000 * 60 * 60 * 24);//ÿһ�����һ��
	}
}

void SetDate(int y, int m, int d, tagDate *date)//�������� 
{
	date->year = y;
	date->month = m;
	date->day = d;
}

int les(int har)
{
	for (int i = 0; i < 10; i++)
	{
		i++;
		puts("");
	}
}

int IsLeapYear(int year)//�Ƿ�����
{
	return ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0);
}

int GetLastDay(tagDate date)//�õ�date.month��������� 
{
	int num;
	switch (date.month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		num = 31;
		break;
	case 2:
		num = 28 + IsLeapYear(date.year);
		break;
	default:
		num = 30;
	}
	return num;
}

void AddDay(tagDate * date)//date+1
{
	date->day++;
	if (date->day > GetLastDay(*date))
	{
		date->day = 1;
		date->month++;
		if (date->month > 12)
		{
			date->month = 1;
			date->year++;
		}
	}
}

int Compare(tagDate date1, tagDate date2)//date1��date2С����ֵΪ1������Ϊ0 
{
	if (date1.year < date2.year)
		return 1;
	if (date1.year <= date2.year && date1.month < date2.month)
		return 1;
	if (date1.year <= date2.year && date1.month <= date2.month && date1.day < date2.day)
		return 1;

	return 0;
}

long DateDiff(tagDate date1, tagDate date2)//�����������ڵļ������
{
	long delta = 0;
	tagDate date3;
	//��date1 > date2,����date1,date2  
	if (!Compare(date1, date2))
	{
		date3 = date2;
		date2 = date1;
		date1 = date3;
	}

	//date1��date2��ʱ��date1���ڼ�1  
	while (Compare(date1, date2))
	{
		AddDay(&date1);
		delta++;
	}
	return delta;
}

int IsDateValid(tagDate date)//�����Ƿ�Ϸ� 
{
	if (date.year < 0 || date.month < 1 || date.month> 12)
		return 0;

	if (date.day <1 || date.day> GetLastDay(date))
		return 0;

	return 1;
}