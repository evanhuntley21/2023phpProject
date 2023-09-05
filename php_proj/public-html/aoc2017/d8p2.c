#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define SIZE 1000
struct registers
{
	char name[10];
	int currVal;
	struct registers* next;
};

void main()
{	
	int largest = 0;
	struct registers* nextRegister = NULL;
	struct registers* regPoint = NULL;
	char nameToChange[10];
	char temp[30];
	char tempPoint[10];
	char comparison[3];
	char *point;
	char *ptr;
	char input[SIZE][30];
	int index = 0;
	struct registers start;
	bool isRepeat = false;
	bool isIncrease = false;
	bool meetsCondition = false;
	int i;
	int changeVal, cmpVal;

	while(fgets(input[index], 30, stdin) != NULL)
	{
		index++;
	}
	index = 0;
	strcpy(temp, input[index]);
	point = strtok(temp, " ");
	strcpy(start.name, temp);
	start.currVal = 0;
	nextRegister = malloc(sizeof(struct registers));
	start.next = nextRegister;

	for(index = 1; index < SIZE; index++)
	{
		strcpy(temp, input[index]);
		point = strtok(temp, " ");
		regPoint = start.next;
		while(regPoint != NULL)
		{
			if(strcmp(regPoint -> name, point) == 0)
			{
				isRepeat = true;
			}
			regPoint = regPoint -> next;
		}

		if(!isRepeat && strcmp(start.name, point) != 0)
		{
			strcpy(nextRegister -> name, point);
			nextRegister -> currVal = 0;
			nextRegister -> next = malloc(sizeof(struct registers));
			nextRegister = nextRegister -> next;
		}
		isRepeat = false;
	}


	for(index = 0; index < SIZE; index++)
	{
		strcpy(temp, input[index]);
		point = strtok(temp, " ");
		strcpy(nameToChange, point);
		point = strtok(NULL, " ");
		isIncrease = (strcmp(point,"inc") == 0);
		point = strtok(NULL, " ");
		changeVal = strtol(point, &point, 10);
		strtok(NULL, " ");
		point = strtok(NULL, " ");
		regPoint = start.next;
		strcpy(tempPoint, point);
		if(!isIncrease)
		{
			changeVal *= (-1);
		}
		while(regPoint != NULL)
		{

			if(strcmp(regPoint -> name, point) == 0)
			{
				point = strtok(NULL, " ");
				strcpy(comparison, point);	
				if(strcmp(comparison, "!=") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &point, 10);
				 	meetsCondition	= (regPoint -> currVal != cmpVal);
				}
				else if(strcmp(comparison, "==") == 0)
				{	
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &point, 10);
					meetsCondition	= (regPoint -> currVal == cmpVal);
				}
				else if(strcmp(comparison, "<=") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &point, 10);
					meetsCondition	= (regPoint -> currVal <= cmpVal);
				}
				else if(strcmp(comparison, "<") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &point, 10);
					meetsCondition	= (regPoint -> currVal < cmpVal);

				}
				else if(strcmp(comparison, ">=") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &point, 10);
					meetsCondition	= (regPoint -> currVal >= cmpVal);
				}
				else if(strcmp(comparison, ">") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &point, 10);
					meetsCondition	= (regPoint -> currVal > cmpVal);
				}
				break;
			}
			else if(strcmp(start.name, point) == 0)
			{
				point = strtok(NULL, " ");
				strcpy(comparison, point);	
				if(strcmp(comparison, "!=") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &ptr, 10);
				 	meetsCondition	= (start.currVal != cmpVal);
				}
				else if(strcmp(comparison, "==") == 0)
				{	
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &ptr, 10);
				 	meetsCondition	= (start.currVal == cmpVal);
				}
				else if(strcmp(comparison, "<=") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &ptr, 10);
				 	meetsCondition	= (start.currVal <= cmpVal);
				}
				else if(strcmp(comparison, "<") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &ptr, 10);
				 	meetsCondition	= (start.currVal < cmpVal);

				}
				else if(strcmp(comparison, ">=") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &ptr, 10);
				 	meetsCondition	= (start.currVal >= cmpVal);
				}
				else if(strcmp(comparison, ">") == 0)
				{
					point = strtok(NULL, " ");
					cmpVal = strtol(point, &ptr, 10);
				 	meetsCondition	= (start.currVal > cmpVal);
				}
				break;
			}
			regPoint = regPoint -> next;
		}

	if(strcmp(nameToChange, start.name) == 0 && meetsCondition)
	{
		start.currVal += changeVal;
	}
	else if(meetsCondition)
	{
		regPoint = start.next;
		while(regPoint != NULL)
		{
			if(strcmp(nameToChange, regPoint -> name) == 0)
			{
				regPoint -> currVal += changeVal;
			}
			if(regPoint -> currVal > largest)
			{
				largest = regPoint -> currVal;
			}
			regPoint = regPoint -> next;
		}
	}

	}

	regPoint = start.next;
			regPoint = start.next;
		while(regPoint != NULL)
		{
			regPoint = regPoint -> next;
		}
printf("Largest ever: %d\n",largest);

}
