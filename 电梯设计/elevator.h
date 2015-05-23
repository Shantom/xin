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

/*顺便服务策略的指示灯*/
BOOL upCmd[8];
BOOL downCmd[8];
BOOL innerCmd[9];


struct cmdList head;
struct cmdList *ptr;
struct cmdList *outPtr;

STATE state;
STATE prestate;
int8_t curFloor;//当前楼层
int8_t aimFloor;//目标楼层
int8_t isPrtVct;
int8_t flag_1;

DWORD WINAPI input_1(LPVOID parameter);
DWORD WINAPI input_2(LPVOID parameter);


//状态转换函数
void state_trans(void);

//输出函数
void print_message(void);

//判断目标楼层的控制函数
void control_1(void); //第一策略

void control_2(void);//第二策略

void control_3(void);//第三策略

//void control_4(void);
