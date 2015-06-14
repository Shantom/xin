#include "elevator.h"


DWORD WINAPI win(LPVOID parameter)
{
	if (!HiWindow("1513-A elevator", 1016, 630)){
		return 0;
	}


	getchar();

}

void f1()  // 窗口初始化事件
{
	g_eggBG = EggFromBmpEx(0, 0, 1920, 1080, 0, 0, 0, 0, "BG.bmp", GetColor(255, 255, 255));
	g_eggTitle = EggFromBmpEx(0, 0, 470, 53, 0, 0, 0, 0, "title.bmp", GetColor(255, 255, 255));
	g_eggDoorL = EggFromBmpEx(0, 0, 200, 424, 0, 0, 0, 0, "door.bmp", GetColor(255, 255, 255));
	g_eggDoorR = EggFromBmpEx(0, 0, 200, 424, 0, 0, 0, 0, "door.bmp", GetColor(255, 255, 255));
	g_eggButtonN = EggFromBmpEx(0, 0, 50, 424, 0, 0, 0, 0, "1-9.bmp", GetColor(255, 255, 255));
	g_eggButtonUD = EggFromBmpEx(0, 0, 37, 424, 0, 0, 0, 0, "U&D.bmp", GetColor(255, 255, 255));
	g_eggWell = EggFromBmpEx(0, 0, 37, 424, 0, 0, 0, 0, "well.bmp", GetColor(255, 255, 255));
	g_eggminiEle = EggFromBmpEx(0, 0, 37, 47, 0, 0, 0, 0, "miniEle.bmp", 0);
	g_egglight = EggFromBmpEx(0, 0, 30, 424, 0, 0, 0, 0, "light.bmp", GetColor(255, 255, 255));
	int i;
	strcpy(singleButton, "light-1.bmp");
	for (i = 0; i < 9; ++i)
	{
		singleButton[6] = i + 1 + '0';
		g_eggLight[i] = EggFromBmpEx(0, 0, 50, 48, 0, 0, 0, 0, singleButton, 0);
	}
	for (i = 0; i < 8; ++i)
	{
		g_eggUpLight[i] = EggFromBmpEx(0, 0, 37, 24, 0, 0, 0, 0, "Up-light.bmp", 0);
	}
	for (i = 0; i < 8; ++i)
	{
		g_eggDownLight[i] = EggFromBmpEx(0, 0, 37, 24, 0, 0, 0, 0, "Down-light.bmp", 0);
	}
	strcpy(openBmp, "open_1.bmp");
	for (i = 0; i < OPEN_NUMBER; ++i)
	{
		openBmp[5] = i + 1 + '0';
		g_eggopen[i] = EggFromBmpEx(0, 0, 300, 424, 0, 0, 0, 0, openBmp, GetColor(255, 255, 255));
	}
	strcpy(policyBmp, "change_1.bmp");

	for (i = 0; i < POLICY_NUMBER; ++i)
	{
		policyBmp[7] = i + 1 + '0';
		g_eggpolicy[i] = EggFromBmpEx(0, 0, 168, 108, 0, 0, 0, 0, policyBmp, GetColor(255, 255, 255));
	}


}

void f2()  // 窗口销毁事件
{
	;
	//// 停止编号为1的计时器
	//FreeTimer(1);

	// 释放全局Egg资源
	EggFree(g_eggBG);
	EggFree(g_eggTitle);
	EggFree(g_eggDoorL);
	EggFree(g_eggDoorR);
	EggFree(g_eggButtonN);
	EggFree(g_eggButtonUD);
	EggFree(g_eggWell);
	EggFree(g_eggminiEle);
	int i;
	for (i = 0; i < 9; ++i)
		EggFree(g_eggLight[i]);
	for (i = 0; i < 8; ++i)
		EggFree(g_eggUpLight[i]);
	for (i = 0; i < 8; ++i)
		EggFree(g_eggDownLight[i]);
	EggFree(g_egglight);

	//// 通知主线程退出（Win32 API）
	//SetEvent(g_hExit);
}

void f3()  // 窗口绘图事件
{
	;
	Paper paper;
	// 产生新的画纸
	paper = NewPaper();


	EggPaint(paper, g_eggBG);
	EggPaint(paper, g_eggTitle);
	if (ranOpen != 0)
		EggPaint(paper, g_eggopen[ranOpen - 1]);

	EggPaint(paper, g_eggDoorL);
	EggPaint(paper, g_eggDoorR);
	EggPaint(paper, g_eggButtonN);
	EggPaint(paper, g_eggButtonUD);
	EggPaint(paper, g_eggWell);
	EggPaint(paper, g_eggminiEle);
	EggPaint(paper, g_egglight);

	int i;
	for (i = 0; i < 9; ++i)
	{
		if (innerCmd[i])
			EggPaint(paper, g_eggLight[i]);
	}
	for (i = 0; i < 8; ++i)
	{
		if (upCmd[i])
			EggPaint(paper, g_eggUpLight[i]);
	}
	for (i = 0; i < 8; ++i)
	{
		if (downCmd[i])
			EggPaint(paper, g_eggDownLight[i]);
	}
	//for (i = 0; i < POLICY_NUMBER; ++i)
	EggPaint(paper, g_eggpolicy[policy - '0' - 1]);


	// 打印画纸
	PrintPaper(paper);

	// 释放画纸以避免资源泄漏
	FreePaper(paper);
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
	EggPlace(g_eggButtonN, x / 2 + 396, 120);
	EggPlace(g_eggButtonUD, x / 2 + 359, 120);
	EggPlace(g_eggWell, x / 2 - 410, 120);
	EggPlace(g_eggminiEle, x / 2 - 410, 120 + 47 * 8);
	EggPlace(g_egglight, x / 2 - 373, 120);

	int i;
	for (i = 0; i < 9; ++i)
	{
		EggPlace(g_eggLight[i], x / 2 + 396, 120 + 47 * (8 - i));
	}
	for (i = 0; i < 8; ++i)
	{
		EggPlace(g_eggUpLight[i], x / 2 + 359, 120 + 47 * (8 - i));
	}
	for (i = 0; i < 8; ++i)
	{
		EggPlace(g_eggDownLight[i], x / 2 + 359, 120 + 47 * (8 - i) + 24);
	}
	for (i = 0; i < OPEN_NUMBER; ++i)
	{
		EggPlace(g_eggopen[i], x / 2 - 150, 120);
	}
	for (i = 0; i < POLICY_NUMBER; ++i)
	{
		EggPlace(g_eggpolicy[i], x / 2 + 300, 5);
	}
}

void f5(int x, int y)  // 鼠标点击
{
	if (x >= g_x / 2 + 300 && x <= g_x / 2 + 468 && y <= 113)
	{
		policy = !(policy - '1') + '1';
		f3();
	}

	else if (x >= g_x / 2 + 396 && x <= g_x / 2 + 396 + 50)//点到数字
	{
		int j = 0;
		for (j = 0; j <= 8; j++)
		{
			if (y >= 120 + 47 * j&&y <= 120 + 47 * (j + 1))
			{
				innerCmd[8 - j] = TRUE;
				call[callNum] = 8 - j + 1;
				++callNum;
				break;
			}
		}
	}
	else if (x >= g_x / 2 + 359 && x <= g_x / 2 + 359 + 37)
	{
		int k = 0;
		for (k = 0; k <= 8; k++)//上按钮
		{
			if (y >= 120 + 47 * k && y <= 120 + 24 + 47 * k)
			{
				upCmd[8 - k] = TRUE;
				call[callNum] = 8 - k + 1;
				++callNum;
				break;
			}
		}

		int m = 0;
		for (m = 0; m <= 8; m++)//下按钮
		{
			if (y >= 120 + 24 + 47 * m && y <= 120 + 47 * (m + 1))
			{
				downCmd[8 - m] = TRUE;
				call[callNum] = 8 - m + 1;
				++callNum;
				break;
			}
		}

	}

}
void f6(char ch)  // 键盘敲击
{
	;
	//if (ch == ' ')				// 空格键请求开门
	//	g_fRequest = 1;
}

void f7()  // 计时器
{
	if (isOpening)
	{
		dOpen();
		if (EggGetX(g_eggDoorR) >= g_x / 2 + 150)
		{
			isOpening = 0;
			Sleep(INTERVAL_TIME);
			isClosing = 1;
		}
	}
	else if (isClosing)
	{
		dClose();
		if (EggGetX(g_eggDoorR) <= g_x / 2)
			isClosing = 0;
	}

	if (isUpping)
	{
		eUp();
		if (EggGetY(g_eggminiEle) <= tempY - 47)
			isUpping = 0;
	}
	else if (isDowning)
	{
		eDown();
		if (EggGetY(g_eggminiEle) >= tempY + 47)
			isDowning = 0;
	}

	f3();
}

void dOpen(void)
{
	EggMove(g_eggDoorL, -5, 0);
	EggMove(g_eggDoorR, +5, 0);
	ranOpen = rand() % OPEN_NUMBER + 1;
}

void dClose(void)
{
	EggMove(g_eggDoorL, +5, 0);
	EggMove(g_eggDoorR, -5, 0);
}

void eUp(void)
{
	EggMove(g_eggminiEle, 0, -1);
}
void eDown(void)
{
	EggMove(g_eggminiEle, 0, +1);
}