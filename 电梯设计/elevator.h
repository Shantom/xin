#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define STATE int8_t
#define VACANT 1
#define UP 2
#define DOWN 3
#define PAUSE 4
#define MAXFLOOR 9


struct cmdList{
	int floor;
	struct cmdList *next;
};

/*˳�������Ե�ָʾ��*/
BOOL upCmd[8];
BOOL downCmd[8];
BOOL innerCmd[9];


struct cmdList head;
struct cmdList *ptr;
struct cmdList *outPtr;

STATE state;
STATE prestate;
int8_t curFloor;//��ǰ¥��
int8_t aimFloor;//Ŀ��¥��
int8_t isPrtVct;
int8_t flag_1;

DWORD WINAPI input_1(LPVOID parameter);
DWORD WINAPI input_2(LPVOID parameter);


//״̬ת������
void state_trans(void);

//�������
void print_message(void);

//�ж�Ŀ��¥��Ŀ��ƺ���
void control_1(void); //��һ����

void control_2(void);//�ڶ�����

void control_3(void);//��������

//void control_4(void);
