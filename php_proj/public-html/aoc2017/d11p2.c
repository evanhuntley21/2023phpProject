#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main()
{	
	int max = 0;
	double xCoord, yCoord,tempX,tempY;
	char directions[50000];
	char *point;
	char d[2];
	xCoord = 0.0;
	yCoord = 0.0;
	int dist = 0;
	fgets(directions, 50000, stdin);
	
	directions[49999] ='\0';
	
	point = strtok(directions, ",");
	while(point != NULL)
	{
		if(strcmp(point, "n") == 0)
		{
			yCoord++;
		}
		else if(strcmp(point, "ne") == 0)
		{
			xCoord++;
			yCoord+=0.5;
		}
		else if(strcmp(point, "se") == 0)
		{
			xCoord++;
			yCoord-=0.5;
		}
		else if(strcmp(point, "s") == 0)
		{
			yCoord-=1;
		}
		else if(strcmp(point, "sw") == 0)
		{
			xCoord--;
			yCoord-=0.5;
		}
		else if(strcmp(point, "nw") == 0)
		{
			xCoord--;
			yCoord+=0.5;
		}
		if(xCoord < 0)
		{
			tempX = xCoord * -1;
		}
		else
		{
			tempX = xCoord;
		}
		if(yCoord < 0)
		{
			tempY = yCoord * -1;
		}
		else
		{
			tempY = yCoord;
		}
		while(tempX > 0 && tempY > 0)
		{
			tempX--;
			tempY-=.5;
			dist++;
		}
		dist+=tempX;
		dist+=tempY;
		if(dist > max)
		{
			max = dist;
		}
		dist = 0;
		point = strtok(NULL, ",");
	}
	printf("Max dist %d \n", max);
}
