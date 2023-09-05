#include <stdio.h>
#include <string.h>


int main()
{
	char nums[1112];
	char *point;
	long i = 0;
	int indexOuter = 0;
	int indexInner = 0;
	int maxValue = 0;
	int minValue = 10000000;
	int allValues[16][16];
	int sum = 0;

	while(fgets(nums, 1000, stdin) != NULL)
	{
		point = nums;
		while(i=strtol(point, &point, 10))
		{		
				allValues[indexOuter][indexInner] = i;
				indexInner = (indexInner + 1)%16;
				if(i > maxValue)
				{
					maxValue = i;
				}
				if(i < minValue)
				{
					minValue = i;
				}
		}
		sum+= (maxValue - minValue);
		maxValue = 0;
		minValue = 1000000;
		indexOuter++;
	}
 	printf("Final sum: %d\n", sum); 

}
