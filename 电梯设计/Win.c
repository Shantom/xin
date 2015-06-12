#include "elevator.h"

char singleButton[12];
Egg g_eggLight[9];
Egg g_eggUpLight[8];
Egg g_eggDownLight[8];
Egg g_egglight;

DWORD WINAPI win(LPVOID parameter)
{
	if (!HiWindow("1513-A elevator", 1016, 630)){
		return 0;
	}


	getchar();

}

void f1()  // ���ڳ�ʼ���¼�
{
	g_eggBG = EggFromBmpEx(0, 0, 1920, 1080, 0, 0, 0, 0, "BG.bmp", GetColor(255, 255, 255));
	g_eggTitle = EggFromBmpEx(0, 0, 470, 53, 0, 0, 0, 0, "title.bmp", GetColor(255, 255, 255));
	g_eggDoorL = EggFromBmpEx(0, 0, 200, 424, 0, 0, 0, 0, "door.bmp", GetColor(255, 255, 255));
	g_eggDoorR = EggFromBmpEx(0, 0, 200, 424, 0, 0, 0, 0, "door.bmp", GetColor(255, 255, 255));
	g_eggButtonN = EggFromBmpEx(0, 0, 50, 424, 0, 0, 0, 0, "1-9.bmp", GetColor(255, 255, 255));
	g_eggButtonUD = EggFromBmpEx(0, 0, 37, 424, 0, 0, 0, 0, "U&D.bmp", GetColor(255, 255, 255));
	g_eggWell = EggFromBmpEx(0, 0, 37, 424, 0, 0, 0, 0, "well.bmp", GetColor(255, 255, 255));
	g_eggminiEle = EggFromBmpEx(0, 0, 37, 47, 0, 0, 0, 0, "miniEle.bmp", 0);
	g_egglight = EggFromBmpEx(0, 0, 67, 424, 0, 0, 0, 0, "light.bmp", GetColor(255, 255, 255));
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



}

void f2()  // ���������¼�
{
	;
	//// ֹͣ���Ϊ1�ļ�ʱ��
	//FreeTimer(1);

	//// �ͷ�ȫ��Egg��Դ
	//EggFree(g_eggDoorL);
	//EggFree(g_eggDoorR);

	//// ֪ͨ���߳��˳���Win32 API��
	//SetEvent(g_hExit);
}

void f3()  // ���ڻ�ͼ�¼�
{
	;
	Paper paper;
	// �����µĻ�ֽ
	paper = NewPaper();

	EggPaint(paper, g_eggBG);
	EggPaint(paper, g_eggTitle);
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


	// ��ӡ��ֽ
	PrintPaper(paper);

	// �ͷŻ�ֽ�Ա�����Դй©
	FreePaper(paper);
}

void f4(int x, int y)  // ���ڴ�С�����¼�
{
	;
	// ���洰����Ч�����С
	g_x = x;
	g_y = y;

	// ���ݴ��ڴ�С���·���Egg
	EggPlace(g_eggTitle, x / 2 - 235, 35);
	EggPlace(g_eggDoorL, x / 2 - 200, 120);
	EggPlace(g_eggDoorR, x / 2, 120);
	EggPlace(g_eggButtonN, x / 2 + 396, 120);
	EggPlace(g_eggButtonUD, x / 2 + 359, 120);
	EggPlace(g_eggWell, x / 2 - 410, 120);
	EggPlace(g_eggminiEle, x / 2 - 410, 120 + 47 * 8);
	EggPlace(g_egglight, x / 2 - 360, 120);

	int i;
	for (i = 0; i < 9; ++i)
	{
		EggPlace(g_eggLight[i], x / 2 + 396, 120 + 47 *(8 - i));
	}
	for (i = 0; i < 8; ++i)
	{
		EggPlace(g_eggUpLight[i], x / 2 + 359, 120 + 47 * (8 - i));
	}
	for (i = 0; i < 8; ++i)
	{
		EggPlace(g_eggDownLight[i], x / 2 + 359, 120 + 47 * (8 - i) + 24);
	}
}

void f5(int x, int y)  // �����
{
	if (x >= g_x / 2 + 396 && x <= g_x / 2 + 396 + 50)//�㵽����
	{
		if (y >= 120 + 47 * 0 && y <= 120 + 47 * 1)
			innerCmd[9 - 1] = TRUE;
		else if (y >= 120 + 47 * 1 && y <= 120 + 47 * 2)
			innerCmd[8 - 1] = TRUE;
		else if (y >= 120 + 47 * 2 && y <= 120 + 47 * 3)
			innerCmd[7 - 1] = TRUE;
		else if (y >= 120 + 47 * 3 && y <= 120 + 47 * 4)
			innerCmd[6 - 1] = TRUE;
		else if (y >= 120 + 47 * 4 && y <= 120 + 47 * 5)
			innerCmd[5 - 1] = TRUE;
		else if (y >= 120 + 47 * 5 && y <= 120 + 47 * 6)
			innerCmd[4 - 1] = TRUE;
		else if (y >= 120 + 47 * 6 && y <= 120 + 47 * 7)
			innerCmd[3 - 1] = TRUE;
		else if (y >= 120 + 47 * 7 && y <= 120 + 47 * 8)
			innerCmd[2 - 1] = TRUE;
		else if (y >= 120 + 47 * 8 && y <= 120 + 47 * 9)
			innerCmd[1 - 1] = TRUE;
	}
	else if (x >= g_x / 2 + 359 && x <= g_x / 2 + 359 + 37)//�ϰ�ť
	{
		if (y >= 120 + 47 * 0 && y <= 120 + 24 +47 * 0)
			/*upCmd[9 - 1] = TRUE*/;
		else if (y >= 120 + 47 * 1 && y <= 120 + 24 +47 * 1)
			upCmd[8 - 1] = TRUE;
		else if (y >= 120 + 47 * 2 && y <= 120 + 24 +47 * 2)
			upCmd[7 - 1] = TRUE;
		else if (y >= 120 + 47 * 3 && y <= 120 + 24 +47 * 3)
			upCmd[6 - 1] = TRUE;
		else if (y >= 120 + 47 * 4 && y <= 120 + 24 +47 * 4)
			upCmd[5 - 1] = TRUE;
		else if (y >= 120 + 47 * 5 && y <= 120 + 24 +47 * 5)
			upCmd[4 - 1] = TRUE;
		else if (y >= 120 + 47 * 6 && y <= 120 + 24 +47 * 6)
			upCmd[3 - 1] = TRUE;
		else if (y >= 120 + 47 * 7 && y <= 120 + 24 +47 * 7)
			upCmd[2 - 1] = TRUE;
		else if (y >= 120 + 47 * 8 && y <= 120 + 24 +47 * 8)
			upCmd[1 - 1] = TRUE;

		else if (y >= 120 + 24 + 47  * 0 && y <= 120 + 47 + 47 * 0)
			downCmd[9 - 1] = TRUE;
		else if (y >= 120 + 24 + 47  * 1 && y <= 120 + 47 + 47 * 1)
			downCmd[8 - 1] = TRUE;
		else if (y >= 120 + 24 + 47  * 2 && y <= 120 + 47 + 47 * 2)
			downCmd[7 - 1] = TRUE;
		else if (y >= 120 + 24 + 47  * 3 && y <= 120 + 47 + 47 * 3)
			downCmd[6 - 1] = TRUE;
		else if (y >= 120 + 24 + 47  * 4 && y <= 120 + 47 + 47 * 4)
			downCmd[5 - 1] = TRUE;
		else if (y >= 120 + 24 + 47  * 5 && y <= 120 + 47 + 47 * 5)
			downCmd[4 - 1] = TRUE;
		else if (y >= 120 + 24 + 47  * 6 && y <= 120 + 47 + 47 * 6)
			downCmd[3 - 1] = TRUE;
		else if (y >= 120 + 24 + 47  * 7 && y <= 120 + 47 + 47 * 7)
			downCmd[2 - 1] = TRUE;
		else if (y >= 120 + 24 + 47  * 8 && y <= 120 + 47 + 47 * 8)
			/*downCmd[1 - 1] = TRUE*/;

	}


}

void f6(char ch)  // �����û�
{
	;
	//if (ch == ' ')				// �ո��������
	//	g_fRequest = 1;
}

void f7()  // ��ʱ��
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