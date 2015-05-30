#include "elevator.h"
void outToFile(FILE *file)
{
	//char TM[100] = { 0 };
	//strncpy(TM, ctime(&curTime), strlen(ctime(&curTime)));
	//TM[24] = 0;

	fprintf(file,"%8.1lf\t", difftime(curTime,startTime));//��ǰʱ��

	char sste[7];
	if (state == VACANT)
		strcpy(sste,"VACANT");
	else if (state == UP)
		strcpy(sste, "UP");
	else if (state == DOWN)
		strcpy(sste, "DOWN");
	else if (state == PAUSE)
		strcpy(sste, "PAUSE");
	fprintf(file, "%8s\t", sste);//����״̬
	fprintf(file, "%8d\t", curFloor);//����¥��
	fprintf(file, "%8d\t", aimFloor);//Ŀ��¥��
	char dir[5];
	if (state == VACANT)
		strcpy(dir, "STOP");
	else if (state == UP)
		strcpy(dir, "UP");
	else if (state == DOWN)
		strcpy(dir, "DOWN");
	else if (state == PAUSE)
		strcpy(dir, "STOP");

	fprintf(file, "%8s\t", dir);//���з���
	fprintf(file, "%8d\t", 0);//ͣ��ʱ����ʱûд

	int i;
	for (i = 0; i <= MAXFLOOR-1; ++i){
		if (upCmd[i]==TRUE)
			fprintf(file, "%-2d", i+1);//δ��Ӧ��������������
	}
	fprintf(file, "\t\t\t");

	for (i = 0; i <= MAXFLOOR-1; ++i){
		if (downCmd[i] == TRUE)
			fprintf(file, "%-2d", i+1);//δ��Ӧ��������������
	}
	fprintf(file, "\t\t\t");

	for (i = 0; i <= MAXFLOOR-1; ++i){
		if (innerCmd[i] == TRUE)
			fprintf(file, "%-2d", i+1);//δ��Ӧ����������
	}
	fprintf(file, "\n");


	fflush(file);
}