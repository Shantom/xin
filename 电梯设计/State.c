#include "elevator.h"

void state_trans(void)
{
	switch (state)
	{
	case VACANT:
		if (aimFloor == 0)
		{
			flag_1 = 1;
		}
		
		else if (aimFloor != 0)
		{
			flag_1 = 0;
			if (aimFloor > curFloor)
			{
				state = UP;
				prestate = VACANT;
			}
			else if (aimFloor < curFloor)
			{
				state = DOWN;
				prestate = VACANT;
			}
		}
		break;
	case UP:
		curFloor++;
		isUpping = 1;
		tempY = EggGetY(g_eggminiEle);
		NewTimer(UPPING, 42, f7);
		printf("***** Heading for %d *****\n", curFloor);
		Sleep(INTERVAL_TIME);
		FreeTimer(UPPING);
		if (curFloor == aimFloor)
		{
			state = PAUSE;
			prestate = UP;
			flag_1 = 1;
		}
		break;
	case DOWN:
		curFloor--;
		isDowning = 1;
		tempY = EggGetY(g_eggminiEle);
		NewTimer(DOWNING, 42, f7);
		printf("***** Heading for %d *****\n", curFloor);
		Sleep(INTERVAL_TIME);
		FreeTimer(DOWNING);
		if (curFloor == aimFloor)
		{
			state = PAUSE;
			prestate = DOWN;
			flag_1 = 1;
		}

		break;
	case PAUSE:
		printf("***** Arrived %d *****\n",curFloor);

		isOpening = 1;
		NewTimer(OPENING, 30, f7);
		Sleep(PAUSE_TIME);
		FreeTimer(OPENING);
		if (aimFloor == 0)
		{
			state = VACANT;
			prestate = PAUSE;
		}
		else{
			flag_1 = 0;
			if (aimFloor > curFloor)
			{
				state = UP;
				prestate = PAUSE;
			}
			else if (aimFloor < curFloor)
			{
				state = DOWN;
				prestate = PAUSE;
			}
			else if (aimFloor == curFloor)
			{
				prestate = PAUSE;
			}
		}


		break;
	}
}