#include <stdio.h>




int main()
{
	int finalSum = 0;
	char nums[2014];
	char currentVal = 'c';
	char nextVal = 'a';
	fgets(nums, 2020, stdin);
	int numsSize = 0;
	int numsToAddSize = 0;


	numsSize = sizeof(nums)/sizeof(nums[0]);
	
	for(int i = 0; i < numsSize-1; i++)
	{
		currentVal = nums[i];
		nextVal = nums[i+1];

		if(currentVal == nextVal)
		{	
			finalSum+=currentVal-48;
		}
	}
	

	if(nums[0] == nums[numsSize-1])
	{
		finalSum+=nums[0]-48;
	}

	printf("Here is the final sum: %i\n", finalSum);


}
