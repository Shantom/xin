#include "elevator.h"
void control_1(void)
{
	if (outPtr->next == NULL)
	if (state == VACANT){
		puts("The elevator is vacant.");
		while (outPtr->next == NULL)
			;
	}
	if (flag_1==1)
	{
		if (outPtr->next != NULL)
		{
			outPtr = outPtr->next;
			if (outPtr != NULL)
				aimFloor = outPtr->floor;
			else
				aimFloor = 0;
		}
		else
			aimFloor = 0;
	}
}

void control_2(void)
{
	/*状态为上时判断目标楼层*/
	if (state == UP)
	{
		int tempFloor = 0;
		for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
		{
			if (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE)
			{
				aimFloor = tempFloor;
				return;
			}
		}
	}
	else if (state == DOWN)
	{
		int tempFloor = 0;
		for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
		{
			if (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE)
			{
				aimFloor = tempFloor;
				return;
			}
		}
	}
	else if (state == VACANT)
	{
		if (flag_2 == 0)
		{
			puts("The elevator is vacant.");
			flag_2 = 1;
		}
		int tempFloor = 0;
		for (tempFloor = 1; tempFloor <= MAXFLOOR; tempFloor++)
		{
			if (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE || upCmd[tempFloor - 1] == TRUE)
			{
				aimFloor = tempFloor;
				flag_2 = 0;
				return;
			}
		}
		aimFloor = 0;
		return;
	}
	else if (state == PAUSE)
	{
		int tempFloor = 0;
		int flag = 0;
		innerCmd[curFloor - 1] = 0;
		if (prestate == UP)
		{
			if (upCmd[curFloor-1] == TRUE)
				flag = 1;//记录上指示灯是否亮着

			//将当前楼层内部命令和外部上行命令去除
			//innerCmd[curFloor - 1] = 0;
			upCmd[curFloor-1] = 0;

			/*检测是否有上行命令*/
			if (curFloor < MAXFLOOR)//判断不是处于最高层
			{
				for (tempFloor = curFloor + 1; tempFloor <= MAXFLOOR; tempFloor++)
				{
					if (innerCmd[tempFloor-1] == TRUE || upCmd[tempFloor-1] == TRUE)
					{
						aimFloor = tempFloor;
						return;
					}
				}
			}
			/*检测是否有下行命令*/
			if (curFloor > 1)
			{
				for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
				{
					if (downCmd[tempFloor-1] == TRUE || innerCmd[tempFloor-1] == TRUE)
					{
						aimFloor = tempFloor;
						return;
					}
				}
			}
			aimFloor = 0;
			return;
		}

		else if (prestate == DOWN)
		{
			if (downCmd[curFloor-1] == TRUE)
				flag = 1;

			//将当前楼层内部命令和外部上行命令去除
			//innerCmd[curFloor] = 0;
			downCmd[curFloor-1] = 0;

			/*检测是否有下行命令*/
			if (curFloor > 1)
			{
				for (tempFloor = curFloor - 1; tempFloor >= 1; tempFloor--)
				{
					if (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE)
					{
						aimFloor = tempFloor;
						return;
					}
				}
			}

			/*检测是否有上行命令*/
			if (curFloor < MAXFLOOR)//判断不是处于最高层
			{
				for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
				{
					if (innerCmd[tempFloor - 1] == TRUE || upCmd[tempFloor - 1] == TRUE)
					{
						aimFloor = tempFloor;
						return;
					}
				}
				aimFloor = 0;
				return;
			}
		}
		else if (prestate == PAUSE)
		{
			upCmd[curFloor - 1] = 0;
			downCmd[curFloor - 1] = 0;
		}
	}
}