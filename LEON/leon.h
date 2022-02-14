#ifndef LEON_H
#define LEON_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <string>
#include <iostream>
#include <thread>
#include <conio.h>
#include <iomanip>
#define EATLINE while(getchar() != '\n')
#define SIZE 30
#define true 1
#define false 0
#define COMPSIZE 100
#define CUSTOMER 1
#define SERVER 2
//**********������Ա����Ϊ:12345
typedef struct {
	char kind[3][SIZE];//��Ʒ������,��������,�̱�,������ 
	float prize;//�۸� 
	int  date[3];//�������ڷֱ�洢������
	float qgp;//quality guarantee period ������
	int judge_if_vacancy;//�����жϸ���Ʒ�Ƿ�ɹ��ͻ�����ļǺ�,������Ϊ1,����Ϊ0 
	int judge_if_overdue;//�����ж���Ʒ�Ƿ����,����Ϊ1,����Ϊ0
}Goods;

// kind�е�Ԫ�طֱ���������º���
//	char name[SIZE];//���� 
//	char size[SIZE];//������ 
//	char brand[SIZE];//�̱�

//�������ڽṹ��
struct tagDate
{
	int year;//��
	int month;//��
	int day;//��
};

typedef struct face_count {
	int count;
	struct face_count * next;
}Count;//���ڹ���������Ա������ʱͶ���ȡ���Ļ�����





//��ʼ������,����Ԥ����LEON�Զ��ۻ����ϴ洢��Ʒ,ͬʱ�������
void initialize(Goods leon[][SIZE], FILE * fp);
void initial_face_num(int * exit_face_num, FILE * fp);
//�����ӡ����ʾ�˵�����
void menu(Goods leon[][SIZE], FILE *fp , FILE * fp2);
int prin(Goods leon[][SIZE], int person);
//�˿͵���غ���
void purchase(int numb, Goods leon[][SIZE]);
void buy(Goods leon[][SIZE]);
int money(float total_prize);//Ͷ��
int give_change(float change);//��Ͷ�����������ʱ����
void inputComp(char ** comp, int size);//Ͷ��ģ�����û�����Ͷ������
char ** complaint(void);//Ͷ��ģ��
//������Ա��غ���
void maintain(Goods leon[][SIZE], char ** complain_list, FILE *fp , FILE * fp2);
void putOnSale(Goods leon[][SIZE]);//�ϼ�����Ʒ
void fetch(Goods leon[][SIZE]);//��������Ʒȫ���¼�
void bring(Goods leon[][SIZE]);//���¼�ָ����δ���ڲ�Ʒ
void check(Goods leon[][SIZE]);//���ڼ���������
void change_face_num(int judge);//������Ա�����޸Ļ����ڲ���Ǯ������
void prin_face_number(void);//��ӡ������Ŀ
//���ָ�������,ר�����ж�,�ַ�������,�����߳�,ʱ�����
int judgeIsSameKind(Goods a, Goods b);
int s_gets(char *st, int n);
void shread_show_now(void);//���߳����ڿ��Ƶ�ǰʱ���ӡ,ʱ�����㶨,ʼ��С�ڵ���59��
						   //��������������ʱ,�������ݶ�ʱ�����ƫ��,����Ϊ0.016 = 1.6%,����Ӱ�����ݱ���
void shread_sign_overdue(Goods leon[][SIZE], FILE * fp);//���ڶ�ÿһ����Ʒ���и���,����Ʒ����ʱ,�Զ�Ϊ��Ʒ�����ѹ���,��ֹ�ͻ�����
void SetDate(int y, int m, int d, tagDate *date);//�������� 
int IsLeapYear(int year);//�Ƿ�����
int GetLastDay(tagDate date);//�õ�date.month��������� 
void AddDay(tagDate *date);//date+1
int Compare(tagDate date1, tagDate date2);//date1��date2С����ֵΪ1������Ϊ0 
long DateDiff(tagDate date1, tagDate date2);//�����������ڵļ������
int IsDateValid(tagDate date);//�����Ƿ�Ϸ� 


#endif
