#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main()
{
	double xCoord, yCoord;
	char directions[30000];
	char *point;
	char d[2];
	xCoord = 0.0;
	yCoord = 0.0;
	int dist = 0;
	fgets(directions, 30000, stdin);
	
	
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

		point = strtok(NULL, ",");
	}
	if(xCoord < 0)
	{
		xCoord *= -1;
	}
	if(yCoord < 0)
	{
		yCoord *= -1;
	}
	while(xCoord > 0 && yCoord > 0)
	{
		xCoord--;
		yCoord-=.5;
		dist++;
	}
	dist+=xCoord;
	dist+=yCoord;
	printf("\nX: %f Y: %f, Steps: %d\n", xCoord, yCoord, dist);

}
