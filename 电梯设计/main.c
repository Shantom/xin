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
*			佛祖保佑       永无BUG
*/

#include "elevator.h"
main()
{
	curFloor = 1;
	state = VACANT;
	ptr = &head;
	outPtr =&head;
	prestate = VACANT;

	system("color 3f");
	puts("\t\t\tWelcome to 1513-A elevator");
	puts("Please select the policy you want to use:");
	puts("1:First call first use;\n2:No extra effort;\n3:Fastest response;");

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
			control_1(); /*根据控制策略确定下一目标楼层，这在state_trans()中要用到 */
		else if (policy == '2')
			control_2();
		else if (policy == '3')
			control_3();
	//	else if (policy == '4')
	//		control_4();

		state_trans(); //根据自动机模型决定此刻电梯的状态 

	}
}