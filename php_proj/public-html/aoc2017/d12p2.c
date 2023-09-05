#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 2000


struct numStruct
{
	int val;
	struct numStruct *next;
};
int i;
int repeats[10000];
char input[200];
char *point;
struct numStruct *nextNum = NULL;
int temp,sum;
struct numStruct *nums[SIZE];
int repeatsIndex;
void getZeros( int index)
{
	nextNum = nums[index];
	int j;
	bool isRepeat = false;
	nums[index] = nums[index] -> next;
	while(nums[index] != NULL)
	{
		for(j = 0; j < SIZE; j++)
		{
			if(nums[index] -> val  == repeats[j])
			{
		
			
				isRepeat = true;
			}
		}
		if(!isRepeat)
		{
			repeats[repeatsIndex] = nums[index] -> val;
			repeatsIndex++;
			sum++;
			getZeros(nums[index] -> val);
		}
		nums[index] = nums[index] -> next;
		isRepeat = false;
	}
	nums[index] = nextNum;
	return;




}
void main()
{	
	bool isRepeatNum;
	int numGroups = 0;
	repeatsIndex = 0;
	i = 0;
	int j;
	point = NULL;
	while(fgets(input, 200, stdin) != NULL)
	{
	//	puts(input);
		sum = 1;
		point = strtok(input, " ");
		temp = strtol(point, &point, 10);
		nums[i] = malloc(sizeof(struct numStruct));
		nums[i] -> val = temp;
		nextNum = nums[i];
		nums[i] -> next = malloc(sizeof(struct numStruct));
		nums[i] = nums[i] -> next;
		strtok(NULL, " ");

		point = strtok(NULL, ", ");
		while(point != NULL)
		{
			temp = strtol(point, &point, 10);
			nums[i] -> val = temp;
			point = strtok(NULL, ", ");
			if(point != NULL)
			{
				nums[i] -> next = malloc(sizeof(struct numStruct));
				nums[i] = nums[i] -> next;
			}
		}
		nums[i] = nextNum;
		i++;
	}


	for(i = 0; i < SIZE-1; i++)
	{
		sum = 0;
		getZeros(i);
		if(sum > 0)
		{
			numGroups++;
		}
	}
	printf("Num groups %d\n", numGroups);

}
