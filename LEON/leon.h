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
//**********工作人员密码为:12345
typedef struct {
	char kind[3][SIZE];//商品的种类,包含名称,商标,净含量 
	float prize;//价格 
	int  date[3];//生产日期分别存储年月日
	float qgp;//quality guarantee period 保质期
	int judge_if_vacancy;//用于判断该商品是否可供客户购买的记号,存在则为1,否则为0 
	int judge_if_overdue;//用于判断商品是否过期,是则为1,不是为0
}Goods;

// kind中的元素分别代表了以下含义
//	char name[SIZE];//名称 
//	char size[SIZE];//净含量 
//	char brand[SIZE];//商标

//创建日期结构体
struct tagDate
{
	int year;//年
	int month;//月
	int day;//日
};

typedef struct face_count {
	int count;
	struct face_count * next;
}Count;//用于构建工作人员检查货币时投入或取出的货币数





//初始化函数,用于预先在LEON自动售货机上存储商品,同时方便调试
void initialize(Goods leon[][SIZE], FILE * fp);
void initial_face_num(int * exit_face_num, FILE * fp);
//程序打印及显示菜单函数
void menu(Goods leon[][SIZE], FILE *fp , FILE * fp2);
int prin(Goods leon[][SIZE], int person);
//顾客的相关函数
void purchase(int numb, Goods leon[][SIZE]);
void buy(Goods leon[][SIZE]);
int money(float total_prize);//投币
int give_change(float change);//当投入数超过金额时找零
void inputComp(char ** comp, int size);//投诉模块中用户输入投诉内容
char ** complaint(void);//投诉模块
//工作人员相关函数
void maintain(Goods leon[][SIZE], char ** complain_list, FILE *fp , FILE * fp2);
void putOnSale(Goods leon[][SIZE]);//上架新商品
void fetch(Goods leon[][SIZE]);//将过期商品全部下架
void bring(Goods leon[][SIZE]);//仅下架指定的未过期产品
void check(Goods leon[][SIZE]);//用于检查货币数量
void change_face_num(int judge);//工作人员用于修改机器内部的钱币数量
void prin_face_number(void);//打印货币数目
//部分辅助函数,专用于判断,字符串操作,控制线程,时间计算
int judgeIsSameKind(Goods a, Goods b);
int s_gets(char *st, int n);
void shread_show_now(void);//该线程用于控制当前时间打印,时间误差恒定,始终小于等于59秒
						   //当面临秒数跳动时,输入数据对时间会有偏差,概率为0.016 = 1.6%,但不影响数据本身
void shread_sign_overdue(Goods leon[][SIZE], FILE * fp);//用于对每一件产品进行跟踪,当产品过期时,自动为产品表明已过期,防止客户购买到
void SetDate(int y, int m, int d, tagDate *date);//设置日期 
int IsLeapYear(int year);//是否闰年
int GetLastDay(tagDate date);//得到date.month的最大天数 
void AddDay(tagDate *date);//date+1
int Compare(tagDate date1, tagDate date2);//date1比date2小返回值为1，否则为0 
long DateDiff(tagDate date1, tagDate date2);//计算两个日期的间隔天数
int IsDateValid(tagDate date);//日期是否合法 


#endif
