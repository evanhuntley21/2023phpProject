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
		
				printf("%d\t", repeats[j]);
				printf("%d\n",index );
			
				isRepeat = true;
			}
		}
		if(!isRepeat)
		{
			repeats[repeatsIndex] = nums[index] -> val;
			repeatsIndex++;
			sum++;
			printf("new branch%d\n", nums[index] -> val);
			getZeros(nums[index] -> val);
		}
		nums[index] = nums[index] -> next;
		isRepeat = false;
	}
	return;





/*
	for(j = 0; j < SIZE; j++)
	{
		if(index  == repeats[j])
		{
		
			printf("%d\t", repeats[j]);
			printf("%d\n",index );
			
			isRepeat = true;
			j = SIZE +1;
		}
	}
	if(!isRepeat)
	{
		nums[index] = nums[index] -> next;
		printf("adding to repeats: %d\n", index);
		repeats[repeatsIndex] = index;
		repeatsIndex++;
		
		while(nums[index] != NULL)
		{
			printf("new branch%d\n", nums[index] -> val);
			getZeros(nums[index] -> val);

			nums[index] = nums[index] -> next;
		}
	}
*/
/*	while(nums[index] != NULL)
	{
		printf("%d ", nums[index] -> val);
		nums[index] = nums[index] -> next;
	}
*/


}
void main()
{	
	repeatsIndex = 0;
	i = 0;
	point = NULL;
	while(fgets(input, 100, stdin) != NULL)
	{
	//	puts(input);
		sum = 1;
		point = strtok(input, " ");
		temp = strtol(point, &point, 10);
		nums[i] = malloc(sizeof(struct numStruct));
		nums[i] -> val = temp;
		printf("%d <->", nums[i] -> val);
		nextNum = nums[i];
		nums[i] -> next = malloc(sizeof(struct numStruct));
		nums[i] = nums[i] -> next;
		strtok(NULL, " ");

		point = strtok(NULL, ", ");
		while(point != NULL)
		{
			temp = strtol(point, &point, 10);
			nums[i] -> val = temp;
			printf("%d ", nums[i] -> val);
			point = strtok(NULL, ", ");
			if(point != NULL)
			{
				nums[i] -> next = malloc(sizeof(struct numStruct));
				nums[i] = nums[i] -> next;
			}
		}
		printf("\n");
		nums[i] = nextNum;
		i++;
	}
	/*
	for(i = 0; i < SIZE; i++)
	{
		repeats[i] = -1;
	}
	*/
	repeats[0] = 0;
	
	getZeros(0);
	printf("Sum: %d\n", sum);
	printf("Repeat array: \n");
	for(i = 0; i < SIZE; i++)
	{
		printf("%d\t", repeats[i]);
	}


}
