#include "elevator.h"

Egg g_eggBG;
Egg g_eggTitle;
Egg g_eggDoorL;
Egg g_eggDoorR;
Egg g_eggButtonN;
Egg g_eggButtonUD;
Egg g_eggWell;
Egg g_eggminiEle;

int g_x;
int g_y;

DWORD WINAPI win(LPVOID parameter)
{
	if (!HiWindow("1513-A elevator", 800, 630)){
		return 0;
	}
	getchar();

}

void f1()  // 窗口初始化事件
{	
	g_eggBG = EggFromBmpEx(0, 0, 800, 630, 0, 0, 0, 0, "BG.bmp", GetColor(255, 255, 255));
	g_eggTitle = EggFromBmpEx(0, 0, 470, 53, 0, 0, 0, 0, "title.bmp", GetColor(255, 255, 255));
	g_eggDoorL = EggFromBmpEx(0, 0, 200, 424, 0, 0, 0, 0, "door.bmp", GetColor(255, 255, 255));
	g_eggDoorR = EggFromBmpEx(0, 0, 200, 424, 0, 0, 0, 0, "door.bmp", GetColor(255, 255, 255));
	g_eggButtonN = EggFromBmpEx(0, 0, 50, 424, 0, 0, 0, 0, "1-9.bmp", GetColor(255, 255, 255));
	g_eggButtonUD = EggFromBmpEx(0, 0, 37, 424, 0, 0, 0, 0, "U&D.bmp", GetColor(255, 255, 255));
	g_eggWell = EggFromBmpEx(0, 0, 37, 424, 0, 0, 0, 0, "well.bmp", GetColor(255, 255, 255));
	g_eggminiEle = EggFromBmpEx(0, 0, 37, 47, 0, 0, 0, 0, "miniEle.bmp", 0/*GetColor(255, 255, 255)*/);

//	// 新建两个Egg，并画门。。
//	g_eggDoorL = EggNew(0, 0, 50, 100);
//	g_eggDoorR = EggNew(0, 0, 50, 100);
//
//	ESetBrush(g_eggDoorL, GetColor(55, 230, 223), 0);
//	ESetBrush(g_eggDoorR, GetColor(55, 230, 223), 0);
//
//	EDrawRect(g_eggDoorL, 0, 0, 50, 100);
//	EDrawRect(g_eggDoorR, 0, 0, 50, 100);
//
//	// 由于未知窗口具体尺寸，两个Egg暂时放在(0, 0)
//
//	// 初始化计时器（编号为1，每1000/30秒调用一次f7）
//	NewTimer(1, 1000 / 30, f7);
//
}

void f2()  // 窗口销毁事件
{
	;
	//// 停止编号为1的计时器
	//FreeTimer(1);

	//// 释放全局Egg资源
	//EggFree(g_eggDoorL);
	//EggFree(g_eggDoorR);

	//// 通知主线程退出（Win32 API）
	//SetEvent(g_hExit);
}

void f3()  // 窗口绘图事件
{
	;
	Paper paper;
	// 产生新的画纸
	paper = NewPaper();

	//// 绘制文字
	//PDrawTxt(paper, 10, g_y / 2 + 10, "Click on the Screen or Press Space to Prevent Door Closing");

	//if (g_fRequest)
	//	PDrawTxt(paper, 10, g_y / 2 - 10, "Hey, Open the Door!");
	//else
	//	PDrawTxt(paper, 10, g_y / 2 - 10, "Close the Door!");

	//// 把Egg画到纸上
	EggPaint(paper, g_eggBG);
	EggPaint(paper, g_eggTitle);
	EggPaint(paper, g_eggDoorL);
	EggPaint(paper, g_eggDoorR);
	EggPaint(paper, g_eggButtonN);
	EggPaint(paper, g_eggButtonUD);
	EggPaint(paper, g_eggWell);
	EggPaint(paper, g_eggminiEle);

	//// 打印画纸
	PrintPaper(paper);

	//// 释放画纸以避免资源泄漏
	//FreePaper(paper);
}

void f4(int x, int y)  // 窗口大小更新事件
{
	;
	// 保存窗口有效区域大小
	g_x = x;
	g_y = y;

	// 根据窗口大小重新放在Egg
	EggPlace(g_eggTitle, x / 2 - 235, 35);
	EggPlace(g_eggDoorL, x / 2 - 200, 120);
	EggPlace(g_eggDoorR, x / 2, 120);
	EggPlace(g_eggButtonN, x / 2 + 296, 120);
	EggPlace(g_eggButtonUD, x / 2 + 259, 120);
	EggPlace(g_eggWell, x / 2 - 310, 120);
	EggPlace(g_eggminiEle, x / 2 - 310, 120+8*47-20);

}

void f5(int x, int y)  // 鼠标点击
{
	;
	//g_fRequest = 1;				// 请求开门
}

void f6(char ch)  // 键盘敲击
{
	;
	//if (ch == ' ')				// 空格键请求开门
	//	g_fRequest = 1;
}

void f7()  // 计时器
{
	;
	//int fL = 0, fR = 0;			// 开门是否到尽头判断
	//static int fOpening;		// 开门延时标记

	//if (fOpening) return;		// 开门1秒中

	//if (!g_fRequest)			// 没有请求
	//{
	//	// 关门
	//	if (EggGetX(g_eggDoorL) < g_x / 2 - 50)
	//		EggMove(g_eggDoorL, 1, 0);
	//	if (EggGetX(g_eggDoorR) > g_x / 2)
	//		EggMove(g_eggDoorR, -1, 0);
	//}
	//else						// 有请求
	//{
	//	// 开门
	//	if (EggGetX(g_eggDoorL) > g_x / 2 - 100)
	//		EggMove(g_eggDoorL, -1, 0);
	//	else fL = 1;			// 左门开到尽头了
	//	if (EggGetX(g_eggDoorR) < g_x / 2 + 50)
	//		EggMove(g_eggDoorR, 1, 0);
	//	else fR = 1;			// 右门开到尽头了

	//	if (fL && fR)			// 两个门都开到尽头了
	//	{
	//		fOpening = 1;		// 锁定延时
	//		Sleep(1000);		// 延时1s（Win32 API）
	//		fOpening = 0;		// 延时解锁
	//		g_fRequest = 0;		// 取消请求标记
	//	}
	//}

	//f3();						// 调用f3，把更新后的画面绘制出来
}
