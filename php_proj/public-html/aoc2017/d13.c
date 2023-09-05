#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 96

struct firewall
{
	int depth;
	int scanner;
	int direction;
};
void main()
{
	int loc,i,j, severity;
	char *point;
	struct firewall layers[SIZE];
	char temp[20];
	temp[19] = '\0';
	severity = 0;
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
	for(i = 0; i < SIZE; i++)
	{
		if(layers[i].depth != 0 && layers[i].scanner == 0)
		{
			severity += i * layers[i].depth;
		}
		for(j = 0; j < SIZE; j++)
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
	}
	printf("Total severity %d\n", severity);
}
