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
int repeats[SIZE];
char input[100];
char *point;
struct numStruct *nextNum = NULL;
int temp,sum;
struct numStruct *nums[SIZE];
int repeatsIndex;
void getZeros( int index)
{

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
	return;





}
void main()
{	
	repeatsIndex = 0;
	i = 0;
	point = NULL;
	while(fgets(input, 100, stdin) != NULL)
	{
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
	repeats[0] = 0;
	
	getZeros(0);
	printf("Sum: %d\n", sum);



}
