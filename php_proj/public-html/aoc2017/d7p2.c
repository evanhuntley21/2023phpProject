#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMLINES 1089
int sum;
struct pgms
{	
	int weight;
	char name[10];
	struct pgms* next;
};

void getBase(struct pgms arr[NUMLINES], char startBase[10])
{
	int j;
	int k;
	struct pgms* currPgm = NULL;
	for(k = 0; k < NUMLINES; k++)
	{
		currPgm = arr[k].next;
//		printf("\nCurrent Line: %s  ", arr[k].name);	
		while(currPgm != NULL)
		{
	//		printf(" %s ", currPgm -> name);
			if(strcmp(currPgm -> name, startBase) == 0)
			{
				printf("\nNew base! %s  %d\n", arr[k].name,k);
				getBase(arr, arr[k].name);

			}
			currPgm = currPgm -> next;
		}
	}
}


void sumBase(struct pgms arr[NUMLINES], char currBase[10])
{
	int a;
	struct pgms* currPgm = NULL;
	for( a = 0; a < NUMLINES; a++)
	{
		if(strcmp(arr[a].name, currBase) == 0)
		{
			printf("\n adding to sum: %s: %d", arr[a].name, arr[a].weight);
			sum+= arr[a].weight;
			currPgm = arr[a].next;
			while(currPgm != NULL)
			{

				sumBase(arr, currPgm -> name);
				currPgm = currPgm -> next;
			}

		}
	}


	
}

void main()
{
	int j;
	char *ptr;
	int amount;
	char temp[10];
	struct pgms* nextPgm = NULL;
	int i;
	char currentLine[100];
	struct pgms programs[NUMLINES];
	char *point;
	for(i = 0; i < NUMLINES; i++)
	{
		programs[i].next = NULL;
		fgets(currentLine, 100, stdin);
		currentLine[ strcspn(currentLine, "\n") ] = '\0'; 
		point = strtok(currentLine, " ");
		strcpy(programs[i].name, point);

		printf("Current line: %s\n", programs[i].name);
	 	point =	strtok(NULL, " ");
		strcpy(temp, point);
		programs[i].weight = strtol(temp + 1, &ptr, 10);
		
		printf("weight:%d\n", programs[i].weight);

		point = strtok(NULL, " ");
		
		if(point != NULL)
		{
			point = strtok(NULL, ", ");
			nextPgm = (struct pgms*)malloc(sizeof(struct pgms));
		
			programs[i].next = nextPgm;
			strcpy(nextPgm -> name, point);
		}
		

		
		point = strtok(NULL, ", ");
		
		while(point != NULL)
		{
			nextPgm -> next = malloc(sizeof(struct pgms));
			nextPgm = nextPgm -> next;
			strcpy(nextPgm -> name, point);
			point = strtok(NULL, ", ");
		}

		nextPgm = programs[i].next;

		while(nextPgm != NULL)
		{
			printf(" %s\n",nextPgm->name);
			nextPgm = nextPgm -> next;
		}

	}	
	
	for( i = 0; i < NUMLINES; i++)
	{
		if(strcmp(programs[i].name, "marnqj") == 0)
		{
 			nextPgm = programs[i].next;
			getBase(programs, programs[119].name);

			while(nextPgm != NULL)
			{
				sum = 0;
				sumBase(programs, nextPgm -> name);
				printf("\nsum: %d", sum);
				nextPgm = nextPgm -> next;
			}
		}
	}



}
