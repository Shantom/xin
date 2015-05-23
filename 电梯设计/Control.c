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
	/*״̬Ϊ��ʱ�ж�Ŀ��¥��*/
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
				flag = 1;//��¼��ָʾ���Ƿ�����

			//����ǰ¥���ڲ�������ⲿ��������ȥ��
			//innerCmd[curFloor - 1] = 0;
			upCmd[curFloor-1] = 0;

			/*����Ƿ�����������*/
			if (curFloor < MAXFLOOR)//�жϲ��Ǵ�����߲�
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
			/*����Ƿ�����������*/
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

			//����ǰ¥���ڲ�������ⲿ��������ȥ��
			//innerCmd[curFloor] = 0;
			downCmd[curFloor-1] = 0;

			/*����Ƿ�����������*/
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

			/*����Ƿ�����������*/
			if (curFloor < MAXFLOOR)//�жϲ��Ǵ�����߲�
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