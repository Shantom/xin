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
		aimFloor = 0;//Maybe it's wrong.!!!!!!!!!!!!
		return;
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
		aimFloor = 0;//Maybe it's wrong.!!!!!!!!!!!!
		return;
	}
	else if (state == VACANT)
	{
		int tempFloor = 0;
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
	else if (state == PAUSE)
	{
		int tempFloor = 0;
		int flag = 0;
		innerCmd[curFloor - 1] = 0;
		if (prestate == UP)
		{
			if (upCmd[curFloor] == TRUE)
				flag = 1;

			//将当前楼层内部命令和外部上行命令去除
			//innerCmd[curFloor - 1] = 0;
			upCmd[curFloor] = 0;

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
				if (flag != 1)
					downCmd[curFloor] = 0;
			}
			/*检测是否有下行命令*/
			if (curFloor > 1)
			{
				for (tempFloor = curFloor - 1; tempFloor >= 1; tempFloor--)
				{
					if (downCmd[tempFloor-1] == TRUE || innerCmd[tempFloor-1] == TRUE)
					{
						aimFloor = tempFloor;
						return;
					}
				}
			}
			aimFloor = 0;//Maybe it's wrong.!!!!!!!!!!!!
			return;
		}

		else if (prestate == DOWN)
		{
			if (downCmd[curFloor] == TRUE)
				flag = 1;

			//将当前楼层内部命令和外部上行命令去除
			innerCmd[curFloor] = 0;
			downCmd[curFloor] = 0;

			/*检测是否有下行命令*/
			if (curFloor > 1)
			{
				for (tempFloor = curFloor - 1; tempFloor >= 1; tempFloor--)
				{
					if (downCmd[tempFloor-1] == TRUE || innerCmd[tempFloor-1] == TRUE)
					{
						aimFloor = tempFloor;
						return;
					}
				}
			}
			if (flag != 1)
				upCmd[curFloor] = 0;

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
				aimFloor = 0;//Maybe it's wrong.!!!!!!!!!!!!
				return;
			}
		}
	}
}

void control_3(void)
{
	int tempFloor = 0;
	int aimTempFloor_up = 0, aimTempFloor_down = 0;//临时目标楼层
	int upTime = 0, downTime = 0;//当前上下行总时间
	int tempFlag = 0;
	/*状态为上时判断目标楼层*/
	if (state == UP)
	{
		//遍历上部楼层
		for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
		{
			upTime++;//上升一层时间加1
			if (tempFlag==0&&(upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//停靠一层时间加3
				aimTempFloor_up = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//停靠一层时间加3
			}
		}

		//遍历下部楼层
		tempFlag = 0;
		for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
		{
			downTime++;//下降一层时间加1
			if (tempFlag==0&&(downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
			}

		}
		if (aimTempFloor_up == 0 && aimTempFloor_down == 0)
			aimFloor = 0;//无上下行命令
		else if (aimTempFloor_up==0&&aimTempFloor_down!=0)
			aimFloor = aimTempFloor_down;//只有下行命令
		else if (aimTempFloor_up!= 0 && aimTempFloor_down== 0)
			aimFloor = aimTempFloor_up;//只有上行命令
		else if ((aimTempFloor_up != 0 && aimTempFloor_down != 0)&&upTime * 5 >= downTime * 6)
			aimFloor = aimTempFloor_down;//有上行下行,且符合调头命令
		else if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && upTime * 5 < downTime * 6)
			aimFloor = aimTempFloor_up;//有上行下行,且不符合调头命令

		return;
	}
	else if (state == DOWN)
	{
		//遍历上部楼层
		for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
		{
			upTime++;//上升一层时间加1
			if (tempFlag == 0 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//停靠一层时间加3
				aimTempFloor_up = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//停靠一层时间加3
			}
		}

		//遍历下部楼层
		tempFlag = 0;
		for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
		{
			downTime++;//下降一层时间加1
			if (tempFlag == 0 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
			}

		}
		if (aimTempFloor_up == 0 && aimTempFloor_down == 0)
			aimFloor = 0;//无上下行命令
		else if (aimTempFloor_up == 0 && aimTempFloor_down != 0)
			aimFloor = aimTempFloor_down;//只有下行命令
		else if (aimTempFloor_up != 0 && aimTempFloor_down == 0)
			aimFloor = aimTempFloor_up;//只有上行命令
		else if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 >= upTime * 6)
			aimFloor = aimTempFloor_down;//有上行下行,且符合调头命令
		else if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 < upTime * 6)
			aimFloor = aimTempFloor_up;//有上行下行,且不符合调头命令

		return;
	}
	else if (state == VACANT)
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
	else if (state == PAUSE)
	{
		//遍历上部楼层
		for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
		{
			upTime++;//上升一层时间加1
			if (tempFlag == 0 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//停靠一层时间加3
				aimTempFloor_up = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//停靠一层时间加3
			}
		}

		//遍历下部楼层
		tempFlag = 0;
		for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
		{
			downTime++;//下降一层时间加1
			if (tempFlag == 0 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//停靠一层时间加3
			}

		}
		if (aimTempFloor_up == 0 && aimTempFloor_down == 0)
			aimFloor = 0;//无上下行命令
		else if (aimTempFloor_up == 0 && aimTempFloor_down != 0)
			aimFloor = aimTempFloor_down;//只有下行命令
		else if (aimTempFloor_up != 0 && aimTempFloor_down == 0)
			aimFloor = aimTempFloor_up;//只有上行命令

		if (prestate == UP && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 >= upTime * 6)
			;
	}
}