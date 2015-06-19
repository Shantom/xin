#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <conio.h>
#include <windows.h>				// ����Event�ں˶���
#include "EggAche.h"



#define STATE int8_t
#define VACANT 1
#define UP 2
#define DOWN 3
#define PAUSE 4
#define MAXFLOOR 9

#define PAUSE_TIME 5000
#define INTERVAL_TIME 1947
#define OPEN_NUMBER 2
#define POLICY_NUMBER 2


struct cmdList{
	int floor;
	struct cmdList *next;
};

/*˳�������Ե�ָʾ��*/
BOOL upCmd[8];
BOOL downCmd[8];
BOOL innerCmd[9];
BOOL call[100];


struct cmdList head;
struct cmdList *ptr;
struct cmdList *outPtr;

STATE state;
STATE prestate;
int8_t curFloor;//��ǰ¥��
int8_t aimFloor;//Ŀ��¥��
int8_t isPrtVct;
int8_t flag_1;
int8_t flag_2;
time_t curTime;
time_t startTime;
FILE *file;
int callNum;
char policy;
int i;


DWORD WINAPI input_1(LPVOID parameter);
DWORD WINAPI input_2(LPVOID parameter);
//DWORD WINAPI getPolicy(LPVOID parameter);
//DWORD WINAPI isPolicy(LPVOID parameter);
DWORD WINAPI win(LPVOID parameter);


//״̬ת������
void state_trans(void);

//�������
void print_message(void);

//�ж�Ŀ��¥��Ŀ��ƺ���
void control_1(void); //��һ����

void control_2(void);//�ڶ�����

void control_3(void);//��������

//void control_4(void);


void outToFile(FILE *);

void f1();
void f2();
void f3();
void f4(int x, int y);
void f5(int x, int y);
void f6(char ch);
void f7();


void dOpen(void);
void dClose(void);
void eUp(void);
void eDown(void);

Egg g_eggBG;
Egg g_eggTitle;
Egg g_eggDoorL;
Egg g_eggDoorR;
Egg g_eggButtonN;
Egg g_eggButtonUD;
Egg g_eggWell;
Egg g_eggminiEle;
char singleButton[12];
Egg g_eggLight[9];
Egg g_eggUpLight[8];
Egg g_eggDownLight[8];
Egg g_egglight;
char openBmp[11];
Egg g_eggopen[OPEN_NUMBER];
int ranOpen;
char policyBmp[13];
Egg g_eggpolicy[POLICY_NUMBER];


int g_x;
int g_y;
int tempY;
int curY;
BOOL isOpening;
BOOL isClosing;
BOOL isUpping;
BOOL isDowning;

enum timer { OPENING, CLOSING, UPPING, DOWNING };
