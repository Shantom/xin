/*
*                   _ooOoo_
*                  o8888888o
*                  88" . "88
*                  (| -_- |)
*                  O\  =  /O
*               ____/`---'\____
*             .'  \\|     |//  `.
*            /  \\|||  :  |||//  \
*           /  _||||| -:- |||||_  \
*           |   | \\\  -  /// |   |
*           | \_|  ``\---/''  |_/ |
*           \  .-\__  `-'  ___/-. /
*         ___`. .'  /--.--\  `. .'___
*      ."" `<  `.___\_<|>_/___.'  >' "".
*     | | :  `- \`.;`\ _ /';.'/ - ' : | |
*     \  \ `-.   \_ __\ /__ _/   .-' /  /
*======`-.____`-.___\_____/___.-'____.-'======
*                   `=---='
*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*        ���汣��       ����BUG
*/

#include "elevator.h"
main()
{
	curFloor = 1;
	state = VACANT;
	ptr = &head;
	outPtr =&head;
	prestate = VACANT;
	file = fopen("output.txt", "w");
	if (file == NULL)
	{
		perror("file");
		exit(1);
	}

	fputs("��ǰʱ��\t����״̬\t����¥��\tĿ��¥��\t���з���\tδ��Ӧ��������������\tδ��Ӧ��������������\tδ��Ӧ����������\n", file);

	system("color 3f");
	puts("\t\t\tWelcome to 1513-A elevator");
	puts("\t\tPlease select the policy you want to use:");
	puts("\t\t1:First call first use;\n\t\t2:No extra effort;\n");

	int policy=getchar();
	fflush(stdin);

	puts("Number 1-9 mean inner commands. \nLetter Q-I mean up commands (1-8),\n S-L mean down commands (2-9)\n");
	puts("The elevator is in the use.\n");

	if (policy == '1')
	{
		CreateThread(0, 0, input_1, NULL, 0, NULL);
	}
	else if (policy == '2')
	{
		CreateThread(0, 0, input_2, NULL, 0, NULL);
	}

	startTime = time(NULL);
	curTime = time(NULL);

	while (1){

		if (policy == '1')
			control_1(); /*���ݿ��Ʋ���ȷ����һĿ��¥�㣬����state_trans()��Ҫ�õ� */
		else if (policy == '2')
			control_2();
		else if (policy == '3')
			control_3();
	//	else if (policy == '4')
	//		control_4();

		state_trans(); //�����Զ���ģ�;����˿̵��ݵ�״̬ 
		curTime = time(NULL);
		if (policy != '2' || state != VACANT)
			outToFile(file);
	}
}