#include "elevator.h"
void outToFile(FILE *file)
{
	char TM[100] = { 0 };
	strncpy(TM, ctime(&curTime), strlen(ctime(&curTime)));
	TM[24] = 0;

	fprintf(file,"%s\t", TM);

	char sste[7];
	if (state == VACANT)
		strcpy(sste,"VACANT");
	else if (state == UP)
		strcpy(sste, "UP");
	else if (state == DOWN)
		strcpy(sste, "DOWN");
	else if (state == PAUSE)
		strcpy(sste, "PAUSE");
	fprintf(file, "%8s\t", sste);
	fprintf(file, "%8d\t", curFloor);
	fprintf(file, "%8d\t", aimFloor);
	char dir[5];
	if (state == VACANT)
		strcpy(dir, "STOP");
	else if (state == UP)
		strcpy(dir, "UP");
	else if (state == DOWN)
		strcpy(dir, "DOWN");
	else if (state == PAUSE)
		strcpy(dir, "STOP");

	fprintf(file, "%8s\t", dir);
	fprintf(file, "%8d\t\n", 0);//停靠时间暂时没写

	fflush(file);
}