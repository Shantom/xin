/*
*					_ooOoo_
*				   o8888888o
*				   88" . "88
*				   (| -_- |)
*				   O\  =  /O
*				____/`---'\____
*			  .'  \\|     |//  `.
*			 /  \\|||  :  |||//  \
*			/  _||||| -:- |||||-  \
*			|   | \\\  -  /// |   |
*			| \_|  ''\---/''  |_/ |
*			\  .-\__  `-'  ___/-. /
*		  ___`. .'  /--.--\  `. .'___
*      ."" '<  `.___\_<|>_/___.'  >' "".
* 	  | | :  `- \`.;`\ _ /`;.`/ - ' : | |
*	  \  \ `-.   \_ __\ /__ _/   .-' /  /
*======`-.____`-.___\_____/___.-'____.-'======
*					`=---='
*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*			���汣��       ����BUG
*/

#include "elevator.h"
main()
{
	curFloor = 1;
	state = VACANT;
	ptr = &head;
	outPtr =&head;
	prestate = VACANT;


	puts("\t\t\tWelcome to 1513-A elevator");
	puts("Please select the policy you want to use:");
	puts("1:First call first use;\t2:No extra effort;");

	int policy=getchar();
	fflush(stdin);

	if (policy == '1')
	{
		CreateThread(0, 0, input_1, NULL, 0, NULL);
	}
	else if (policy == '2')
	{
		CreateThread(0, 0, input_2, NULL, 0, NULL);
	}

	while (1){

		if (policy == '1')
			control_1(); /*���ݿ��Ʋ���ȷ����һĿ��¥�㣬����state_trans()��Ҫ�õ� */
		else if (policy == '2')
			control_2();

		state_trans(); //�����Զ���ģ�;����˿̵��ݵ�״̬ 

	}
}