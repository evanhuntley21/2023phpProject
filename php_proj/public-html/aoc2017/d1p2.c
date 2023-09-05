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
	
	for(int i = 0; i < numsSize; i++)
	{


		if(currentVal == nextVal)
		{	
			finalSum+=currentVal-48;
		}
		currentVal = nums[i];
		nextVal = nums[(i+(numsSize)/2)%2014];
	}
	


	printf("Here is the final sum: %i\n", finalSum);


}
