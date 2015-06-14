#include "elevator.h"
//void control_1(void)
//{
//	if (outPtr->next == NULL)
//	if (state == VACANT){
//		puts("The elevator is vacant.");
//		while (outPtr->next == NULL)
//			;
//	}
//	if (flag_1==1)
//	{
//		if (outPtr->next != NULL)
//		{
//			struct cmdList *temp = outPtr;
//			outPtr = outPtr->next;
//			if (temp!=&head)
//			free(temp);//��ֹ�ڴ�й¶
//			if (outPtr != NULL)
//				aimFloor = outPtr->floor;
//			else
//				aimFloor = 0;
//		}
//		else
//			aimFloor = 0;
//	}
//}

void control_1(void)//yang 
{

	for (i = 0; i <= 100 - 1; i++) {
		if (call[i] != 0)
		{
			aimFloor = call[i];
			if (state == PAUSE && prestate != PAUSE)
			{
				call[i] = 0;//��ʾ33�еĽ�����һ������
				innerCmd[aimFloor - 1] = FALSE;
				upCmd[aimFloor - 1] = FALSE;
				downCmd[aimFloor - 1] = FALSE;
				if (call[i + 1] != 0)
					aimFloor = call[i + 1];
				else
					aimFloor = 0;

			}
			return;
		}
	}
	aimFloor = 0;
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
			outToFile(file);

			downCmd[curFloor - 1] = FALSE;
			innerCmd[curFloor - 1] = FALSE;
			upCmd[curFloor - 1] = FALSE;
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
		call[i] = 0;
		++i;
		innerCmd[curFloor - 1] = FALSE;
		if (prestate == UP)
		{
			if (upCmd[curFloor-1] == TRUE)
				flag = 1;//��¼��ָʾ���Ƿ�����

			//����ǰ¥���ڲ�������ⲿ��������ȥ��
			//innerCmd[curFloor - 1] = 0;
			upCmd[curFloor - 1] = FALSE;

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
			downCmd[curFloor - 1] = FALSE;

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
			upCmd[curFloor - 1] = FALSE;
			downCmd[curFloor - 1] = FALSE;
			aimFloor = 0;
		}
	}
}

void control_3(void)
{
	int tempFloor = 0;
	int aimTempFloor_up = 0, aimTempFloor_down = 0;//��ʱĿ��¥��
	int upTime = 0, downTime = 0;//��ǰ��������ʱ��
	int tempFlag = 0;
	/*״̬Ϊ��ʱ�ж�Ŀ��¥��*/
	if (state == UP)
	{
		//�����ϲ�¥��
		for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
		{
			upTime++;//����һ��ʱ���1
			if (tempFlag==0&&(upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//ͣ��һ��ʱ���3
				aimTempFloor_up = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//ͣ��һ��ʱ���3
			}
		}

		//�����²�¥��
		tempFlag = 0;
		for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
		{
			downTime++;//�½�һ��ʱ���1
			if (tempFlag==0&&(downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
			}

		}
		if (aimTempFloor_up == 0 && aimTempFloor_down == 0)
			aimFloor = 0;//������������
		else if (aimTempFloor_up==0&&aimTempFloor_down!=0)
			aimFloor = aimTempFloor_down;//ֻ����������
		else if (aimTempFloor_up!= 0 && aimTempFloor_down== 0)
			aimFloor = aimTempFloor_up;//ֻ����������
		else if ((aimTempFloor_up != 0 && aimTempFloor_down != 0)&&upTime * 5 >= downTime * 6)
			aimFloor = aimTempFloor_down;//����������,�ҷ��ϵ�ͷ����
		else if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && upTime * 5 < downTime * 6)
			aimFloor = aimTempFloor_up;//����������,�Ҳ����ϵ�ͷ����

		return;
	}
	else if (state == DOWN)
	{
		//�����ϲ�¥��
		for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
		{
			upTime++;//����һ��ʱ���1
			if (tempFlag == 0 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//ͣ��һ��ʱ���3
				aimTempFloor_up = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//ͣ��һ��ʱ���3
			}
		}

		//�����²�¥��
		tempFlag = 0;
		for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
		{
			downTime++;//�½�һ��ʱ���1
			if (tempFlag == 0 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
			}

		}
		if (aimTempFloor_up == 0 && aimTempFloor_down == 0)
			aimFloor = 0;//������������
		else if (aimTempFloor_up == 0 && aimTempFloor_down != 0)
			aimFloor = aimTempFloor_down;//ֻ����������
		else if (aimTempFloor_up != 0 && aimTempFloor_down == 0)
			aimFloor = aimTempFloor_up;//ֻ����������
		else if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 >= upTime * 6)
			aimFloor = aimTempFloor_down;//����������,�ҷ��ϵ�ͷ����
		else if ((aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 < upTime * 6)
			aimFloor = aimTempFloor_up;//����������,�Ҳ����ϵ�ͷ����

		return;
	}
	else if (state == VACANT)
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
	else if (state == PAUSE)
	{
		//�����ϲ�¥��
		for (tempFloor = curFloor; tempFloor <= MAXFLOOR; tempFloor++)
		{
			upTime++;//����һ��ʱ���1
			if (tempFlag == 0 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//ͣ��һ��ʱ���3
				aimTempFloor_up = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag = 1 && (upCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				upTime += 3;//ͣ��һ��ʱ���3
			}
		}

		//�����²�¥��
		tempFlag = 0;
		for (tempFloor = curFloor; tempFloor >= 1; tempFloor--)
		{
			downTime++;//�½�һ��ʱ���1
			if (tempFlag == 0 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
				aimTempFloor_down = tempFloor;
				tempFlag = 1;
			}
			if (tempFlag == 1 && (downCmd[tempFloor - 1] == TRUE || innerCmd[tempFloor - 1] == TRUE))
			{
				downTime += 3;//ͣ��һ��ʱ���3
			}

		}
		if (aimTempFloor_up == 0 && aimTempFloor_down == 0)
			aimFloor = 0;//������������
		else if (aimTempFloor_up == 0 && aimTempFloor_down != 0)
			aimFloor = aimTempFloor_down;//ֻ����������
		else if (aimTempFloor_up != 0 && aimTempFloor_down == 0)
			aimFloor = aimTempFloor_up;//ֻ����������

		if (prestate == UP && (aimTempFloor_up != 0 && aimTempFloor_down != 0) && downTime * 5 >= upTime * 6)

			;
	}
}