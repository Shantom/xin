#include "elevator.h"

DWORD WINAPI input_1(LPVOID parameter)
{
	while (1){
		char key = getchar();
		fflush(stdin);

		ptr->next = malloc(sizeof(struct cmdList));//在读入一个数之后申请空间
		ptr = ptr->next;

		ptr->next = NULL;
		switch (key)
		{
		case '1':case'Q':
			ptr->floor = 1;
			break;
		case '2':case'W':case'S':
			ptr->floor = 2;
			break;
		case '3':case'E':case'D':
			ptr->floor = 3;
			break;
		case '4':case'R':case'F':
			ptr->floor = 4;
			break;
		case '5':case'T':case'G':
			ptr->floor = 5;
			break;
		case '6':case'Y':case'H':
			ptr->floor = 6;
			break;
		case '7':case'U':case'J':
			ptr->floor = 7;
			break;
		case '8':case'I':case'K':
			ptr->floor = 8;
			break;
		case '9':case'L':
			ptr->floor = 9;
			break;
		default:
			ptr->floor = 10;
		}

	}
	return 0;
}

DWORD WINAPI input_2(LPVOID parameter)
{
	while (1)
	{
		char key = getchar();
		switch (key)
		{
		case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
			innerCmd[key - '0' - 1] = TRUE;
			break;

		case'Q':
			upCmd[0] = TRUE;
			break;
		case'W':
			upCmd[1] = TRUE;
			break;
		case'E':
			upCmd[2] = TRUE;
			break;
		case'R':
			upCmd[3] = TRUE;
			break;
		case'T':
			upCmd[4] = TRUE;
			break;
		case'Y':
			upCmd[5] = TRUE;
			break;
		case'U':
			upCmd[6] = TRUE;
			break;
		case'I':
			upCmd[7] = TRUE;
			break;

		case'S':
			downCmd[1] = TRUE;
			break;
		case'D':
			downCmd[2] = TRUE;
			break;
		case'F':
			downCmd[3] = TRUE;
			break;
		case'G':
			downCmd[4] = TRUE;
			break;
		case'H':
			downCmd[5] = TRUE;
			break;
		case'J':
			downCmd[6] = TRUE;
			break;
		case'K':
			downCmd[7] = TRUE;
			break;
		case'L':
			downCmd[8] = TRUE;
			break;

		}
	}
}
