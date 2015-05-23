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

void control_3(void)
{
	int tempFloor = 0;
	int aimTempFloor_up = 0, aimTempFloor_down = 0;//��ʱĿ��¥��
	int finalFloor_up =curFloor, finalFloor_down = curFloor;
	int upTime = 0, downTime = 0;//��ǰ��ʼʱ������ʱ�䣬������ʱ��
	int tempFlag = 0;
	
	    if (state == VACANT)
		{
			//���յ�һ��¥��ָ���������ΪĿ��¥��
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

		/*���������е����¥�㣬����������*/
		if (curFloor < MAXFLOOR)
		{
			for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
			{
				if (tempFlag == 0 && (upCmd[tempFloor] == TRUE || innerCmd[tempFloor] == TRUE))
				{
					upTime += 3;//ͣ��һ��ʱ���3
					aimTempFloor_up = tempFloor+1;
					tempFlag = 1;//��ʶ���ж�ֻ����һ��
					finalFloor_up = tempFloor;
				}
				if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
				{
					upTime += 3;//ͣ��һ��ʱ���3
					finalFloor_up = tempFloor;
				}
			}
			if (finalFloor_up == 0)
			{
				upTime = 0;
				finalFloor_up = curFloor;
			}
			else
		        upTime+= finalFloor_up - curFloor;//�ó�����ʱ��
		}
		else{
			finalFloor_up = MAXFLOOR;
		}

		/*������������*/
		tempFlag = 0;
		if (finalFloor_up > 1)
		{
		for (tempFloor = finalFloor_up-1; tempFloor >= 1; tempFloor--)
		{
			if (tempFlag == 0 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
				finalFloor_down = tempFloor;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
				finalFloor_down = tempFloor;
			}
		}
		upTime += finalFloor_up - finalFloor_down;//�õ���ǰ���е���ʱ��
		}
		




	  /*���������е����¥�㣬����������*/
		tempFlag = 0;
		for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
		{
			if (tempFlag==0&&(downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
				finalFloor_down = tempFloor;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
				finalFloor_down = tempFloor;
			}
		}
		downTime += curFloor - finalFloor_down;

		/*Ȼ���������*/
		tempFlag = 0;
		for (tempFloor = finalFloor_down; tempFloor <= MAXFLOOR; tempFloor++)
		{
			if (tempFlag == 0 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
				aimTempFloor_up = tempFloor;
				tempFlag = 1;//��ʶ���ж�ֻ����һ��
				finalFloor_up = tempFloor;
			}
			if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
				finalFloor_up = tempFloor;
			}
		}
		downTime += finalFloor_up - finalFloor_down;//�ó�����ʱ��


		if (aimTempFloor_up == 0 && aimTempFloor_down == 0)
			aimFloor = 0;//������������
		else if (aimTempFloor_up==0&&aimTempFloor_down!=0)
			aimFloor = aimTempFloor_down;//ֻ����������
		else if (aimTempFloor_up!= 0 && aimTempFloor_down== 0)
			aimFloor = aimTempFloor_up;//ֻ����������

		if (state == UP)
		{
			if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 6 <= upTime * 5)
				aimFloor = aimTempFloor_down;//����������,�ҷ��ϵ�ͷ����
			if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 6 > upTime * 5)
				aimFloor = aimTempFloor_up;//����������,�Ҳ����ϵ�ͷ����
		}
		else if (state == DOWN)
		{
			if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 >= upTime * 6)
				aimFloor = aimTempFloor_up;//����������,�ҷ��ϵ�ͷ����
			if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 < upTime * 6)
				aimFloor = aimTempFloor_down;//����������,�Ҳ����ϵ�ͷ����
		}
		else if (state == PAUSE)
		{
			if (prestate == UP && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 6 <= upTime * 5)
				aimFloor = aimTempFloor_down;//����������,�ҷ��ϵ�ͷ����
			else if (prestate == UP && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 6 > upTime * 5)
				aimFloor = aimTempFloor_up;//����������,�Ҳ����ϵ�ͷ����
			else if (prestate == DOWN && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 >= upTime * 6)
				aimFloor = aimTempFloor_up;//����������,�ҷ��ϵ�ͷ����
			else if (prestate == DOWN && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 < upTime * 6)
				aimFloor = aimTempFloor_down;//����������,�Ҳ����ϵ�ͷ����
		}
}