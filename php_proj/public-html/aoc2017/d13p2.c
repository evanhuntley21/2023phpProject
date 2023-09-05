#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 97

struct firewall
{
	int depth;
	int scanner;
	int direction;
};
void main()
{
	int loc,i,j, severity, delay, found;
	char *point;
	struct firewall layers[SIZE];
	char temp[20];
	temp[19] = '\0';
	severity = 0;
	delay = 0;
	found = 0;
	j = 0;
	int k = 0;
	for(i = 0; i < SIZE; i++)
	{
		layers[i].depth = 0;
		layers[i].scanner = 0;
		layers[i].direction = -1;
	}
	while(fgets(temp, 20, stdin) != NULL)
	{
		point = strtok(temp, ": ");
		loc = strtol(point, &point, 10);
		point = strtok(NULL, ": ");
		layers[loc].depth = strtol(point, &point, 10);
	}
	while(found == 0)
	{
		severity = 0;
		for(i = 0;i < SIZE; i++)
		{
		layers[i].scanner = 0;
		layers[i].direction = -1;
			if(delay != 0 &&	layers[i].depth != 0)
			{
				j = delay % (2*layers[i].depth - 2);
				for(k = 0; k < j; k++)
				{
					if(layers[i].scanner == 0 || layers[i].scanner == layers[i].depth - 1)
					{
						layers[i].direction *= (-1);
					}
					layers[i].scanner += layers[i].direction;
				}
			}

		}
		i = 0;
		severity = 0;
		while(severity == 0 && i < SIZE)
		{
			if(layers[i].depth != 0 && layers[i].scanner == 0)
			{
				severity++;
			}
			for(j = 0;j < SIZE; j++)
			{
	
				if(layers[j].depth != 0)
				{
					if(layers[j].scanner == 0 || layers[j].scanner == layers[j].depth-1)
					{
						layers[j].direction *= (-1);
					}
					layers[j].scanner += layers[j].direction;
				}
			}
			i++;
		}

		if(severity == 0)
		{
			found = 1;
		}
		delay++;
	}
		printf("Total severity %d\n", delay - 1);
}
