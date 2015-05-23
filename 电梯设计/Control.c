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

void control_3(void)
{
	int tempFloor = 0;
	int aimTempFloor_up = 0, aimTempFloor_down = 0;//临时目标楼层
	int finalFloor_up =curFloor, finalFloor_down = curFloor;
	int upTime = 0, downTime = 0;//当前开始时上行总时间，下行总时间
	int tempFlag = 0;
	
	    if (state == VACANT)
		{
			//接收到一个楼层指令后，立马作为目标楼层
			for (tempFloor = 1; tempFloor <= MAXFLOOR; tempFloor++)
			{
				if (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE || upCmd[tempFloor - 1] == TRUE)
				{
					aimFloor = tempFloor;
					return;
				}
			}
			aimFloor = 0;//Maybe it's wrong.!!!!!!!!!!!!
			return;
		}

		/*假设先上行到最高楼层，再向下运行*/
		if (curFloor < MAXFLOOR)
		{
			for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
			{
				if (tempFlag == 0 && (upCmd[tempFloor] == TRUE || innerCmd[tempFloor] == TRUE))
				{
					upTime += 3;//停靠一层时间加3
					aimTempFloor_up = tempFloor+1;
					tempFlag = 1;//标识此判断只进行一次
					finalFloor_up = tempFloor;
				}
				if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
				{
					upTime += 3;//停靠一层时间加3
					finalFloor_up = tempFloor;
				}
			}
			if (finalFloor_up == 0)
			{
				upTime = 0;
				finalFloor_up = curFloor;
			}
			else
		        upTime+= finalFloor_up - curFloor;//得出上行时间
		}
		else{
			finalFloor_up = MAXFLOOR;
		}

		/*电梯向下运行*/
		tempFlag = 0;
		if (finalFloor_up > 1)
		{
		for (tempFloor = finalFloor_up-1; tempFloor >= 1; tempFloor--)
		{
			if (tempFlag == 0 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
				finalFloor_down = tempFloor;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
				finalFloor_down = tempFloor;
			}
		}
		upTime += finalFloor_up - finalFloor_down;//得到当前上行的总时间
		}
		




	  /*假设先下行到最低楼层，再向上运行*/
		tempFlag = 0;
		for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
		{
			if (tempFlag==0&&(downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
				finalFloor_down = tempFloor;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
				finalFloor_down = tempFloor;
			}
		}
		downTime += curFloor - finalFloor_down;

		/*然后电梯上行*/
		tempFlag = 0;
		for (tempFloor = finalFloor_down; tempFloor <= MAXFLOOR; tempFloor++)
		{
			if (tempFlag == 0 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
				aimTempFloor_up = tempFloor;
				tempFlag = 1;//标识此判断只进行一次
				finalFloor_up = tempFloor;
			}
			if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
				finalFloor_up = tempFloor;
			}
		}
		downTime += finalFloor_up - finalFloor_down;//得出上行时间


		if (aimTempFloor_up == 0 && aimTempFloor_down == 0)
			aimFloor = 0;//无上下行命令
		else if (aimTempFloor_up==0&&aimTempFloor_down!=0)
			aimFloor = aimTempFloor_down;//只有下行命令
		else if (aimTempFloor_up!= 0 && aimTempFloor_down== 0)
			aimFloor = aimTempFloor_up;//只有上行命令

		if (state == UP)
		{
			if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 6 <= upTime * 5)
				aimFloor = aimTempFloor_down;//有上行下行,且符合调头命令
			if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 6 > upTime * 5)
				aimFloor = aimTempFloor_up;//有上行下行,且不符合调头命令
		}
		else if (state == DOWN)
		{
			if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 >= upTime * 6)
				aimFloor = aimTempFloor_up;//有上行下行,且符合调头命令
			if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 < upTime * 6)
				aimFloor = aimTempFloor_down;//有上行下行,且不符合调头命令
		}
		else if (state == PAUSE)
		{
			if (prestate == UP && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 6 <= upTime * 5)
				aimFloor = aimTempFloor_down;//有上行下行,且符合调头命令
			else if (prestate == UP && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 6 > upTime * 5)
				aimFloor = aimTempFloor_up;//有上行下行,且不符合调头命令
			else if (prestate == DOWN && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 >= upTime * 6)
				aimFloor = aimTempFloor_up;//有上行下行,且符合调头命令
			else if (prestate == DOWN && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 < upTime * 6)
				aimFloor = aimTempFloor_down;//有上行下行,且不符合调头命令
		}
}