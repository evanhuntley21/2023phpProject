#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMLINES 1089
struct pgms
{
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
				printf("\nNew base! %s\n", arr[k].name);
				getBase(arr, arr[k].name);

			}
			currPgm = currPgm -> next;
		}
	}
}


void main()
{
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
		point = strtok(currentLine, " ");
		strcpy(programs[i].name, point);

	//	printf("Current line: %s\n", programs[i].name);
		
		strtok(NULL, " ");
		
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
		//	printf(" %s\n",nextPgm->name);
			nextPgm = nextPgm -> next;
		}

	}

	 getBase(programs, programs[0].name);



}
