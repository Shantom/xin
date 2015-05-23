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
		printf("***** Heading for %d *****\n", curFloor);
		Sleep(2000);

		if (curFloor == aimFloor)
		{
			state = PAUSE;
			prestate = UP;
			flag_1 = 1;
		}
		break;
	case DOWN:
		curFloor--;
		printf("***** Heading for %d *****\n", curFloor);
		Sleep(2000);
		if (curFloor == aimFloor)
		{
			state = PAUSE;
			prestate = DOWN;
			flag_1 = 1;
		}

		break;
	case PAUSE:
		printf("***** Arrived %d *****\n",curFloor);
		Sleep(5000);
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