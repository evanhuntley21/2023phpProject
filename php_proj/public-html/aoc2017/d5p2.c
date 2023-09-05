#include <stdio.h>
#include <string.h>




void main()
{
	char nums[20000];
	char *point;
	int loc, temp, steps;
	int index = 0;
	int trueNums[10000];
	

	while(fgets(nums, 1000, stdin) != NULL)
	{
		point = nums;	
		
		trueNums[index] = strtol(point, &point, 10);
		index++;
		
	}

	loc = 0;
	steps = 0;
	while(loc < index)
	{
		temp = loc;
		loc = loc + trueNums[loc];
		if(trueNums[temp] >= 3)
		{
			trueNums[temp]--;
		}
		else
		{
			trueNums[temp]++;
		}
		steps++;
	}
	printf("Number of steps: %d\n",steps);



}
