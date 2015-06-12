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

void f1()  // ���ڳ�ʼ���¼�
{	
	g_eggBG = EggFromBmpEx(0, 0, 800, 630, 0, 0, 0, 0, "BG.bmp", GetColor(255, 255, 255));
	g_eggTitle = EggFromBmpEx(0, 0, 470, 53, 0, 0, 0, 0, "title.bmp", GetColor(255, 255, 255));
	g_eggDoorL = EggFromBmpEx(0, 0, 200, 424, 0, 0, 0, 0, "door.bmp", GetColor(255, 255, 255));
	g_eggDoorR = EggFromBmpEx(0, 0, 200, 424, 0, 0, 0, 0, "door.bmp", GetColor(255, 255, 255));
	g_eggButtonN = EggFromBmpEx(0, 0, 50, 424, 0, 0, 0, 0, "1-9.bmp", GetColor(255, 255, 255));
	g_eggButtonUD = EggFromBmpEx(0, 0, 37, 424, 0, 0, 0, 0, "U&D.bmp", GetColor(255, 255, 255));
	g_eggWell = EggFromBmpEx(0, 0, 37, 424, 0, 0, 0, 0, "well.bmp", GetColor(255, 255, 255));
	g_eggminiEle = EggFromBmpEx(0, 0, 37, 47, 0, 0, 0, 0, "miniEle.bmp", 0/*GetColor(255, 255, 255)*/);

//	// �½�����Egg�������š���
//	g_eggDoorL = EggNew(0, 0, 50, 100);
//	g_eggDoorR = EggNew(0, 0, 50, 100);
//
//	ESetBrush(g_eggDoorL, GetColor(55, 230, 223), 0);
//	ESetBrush(g_eggDoorR, GetColor(55, 230, 223), 0);
//
//	EDrawRect(g_eggDoorL, 0, 0, 50, 100);
//	EDrawRect(g_eggDoorR, 0, 0, 50, 100);
//
//	// ����δ֪���ھ���ߴ磬����Egg��ʱ����(0, 0)
//
//	// ��ʼ����ʱ�������Ϊ1��ÿ1000/30�����һ��f7��
//	NewTimer(1, 1000 / 30, f7);
//
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

	//// ��������
	//PDrawTxt(paper, 10, g_y / 2 + 10, "Click on the Screen or Press Space to Prevent Door Closing");

	//if (g_fRequest)
	//	PDrawTxt(paper, 10, g_y / 2 - 10, "Hey, Open the Door!");
	//else
	//	PDrawTxt(paper, 10, g_y / 2 - 10, "Close the Door!");

	//// ��Egg����ֽ��
	EggPaint(paper, g_eggBG);
	EggPaint(paper, g_eggTitle);
	EggPaint(paper, g_eggDoorL);
	EggPaint(paper, g_eggDoorR);
	EggPaint(paper, g_eggButtonN);
	EggPaint(paper, g_eggButtonUD);
	EggPaint(paper, g_eggWell);
	EggPaint(paper, g_eggminiEle);

	//// ��ӡ��ֽ
	PrintPaper(paper);

	//// �ͷŻ�ֽ�Ա�����Դй©
	//FreePaper(paper);
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
	EggPlace(g_eggButtonN, x / 2 + 296, 120);
	EggPlace(g_eggButtonUD, x / 2 + 259, 120);
	EggPlace(g_eggWell, x / 2 - 310, 120);
	EggPlace(g_eggminiEle, x / 2 - 310, 120+8*47-20);

}

void f5(int x, int y)  // �����
{
	;
	//g_fRequest = 1;				// ������
}

void f6(char ch)  // �����û�
{
	;
	//if (ch == ' ')				// �ո��������
	//	g_fRequest = 1;
}

void f7()  // ��ʱ��
{
	;
	//int fL = 0, fR = 0;			// �����Ƿ񵽾�ͷ�ж�
	//static int fOpening;		// ������ʱ���

	//if (fOpening) return;		// ����1����

	//if (!g_fRequest)			// û������
	//{
	//	// ����
	//	if (EggGetX(g_eggDoorL) < g_x / 2 - 50)
	//		EggMove(g_eggDoorL, 1, 0);
	//	if (EggGetX(g_eggDoorR) > g_x / 2)
	//		EggMove(g_eggDoorR, -1, 0);
	//}
	//else						// ������
	//{
	//	// ����
	//	if (EggGetX(g_eggDoorL) > g_x / 2 - 100)
	//		EggMove(g_eggDoorL, -1, 0);
	//	else fL = 1;			// ���ſ�����ͷ��
	//	if (EggGetX(g_eggDoorR) < g_x / 2 + 50)
	//		EggMove(g_eggDoorR, 1, 0);
	//	else fR = 1;			// ���ſ�����ͷ��

	//	if (fL && fR)			// �����Ŷ�������ͷ��
	//	{
	//		fOpening = 1;		// ������ʱ
	//		Sleep(1000);		// ��ʱ1s��Win32 API��
	//		fOpening = 0;		// ��ʱ����
	//		g_fRequest = 0;		// ȡ��������
	//	}
	//}

	//f3();						// ����f3���Ѹ��º�Ļ�����Ƴ���
}
