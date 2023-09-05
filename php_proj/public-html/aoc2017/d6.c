#include <stdio.h>
#include <string.h>

#define numItems 16
#define LIMIT 10000
int main()
{
	char nums[LIMIT];
	char *point;
	int trueNums[LIMIT][numItems];
	int row, col, i, j, k, repeatCount, largestValue, largestIndex, add;
	long val = 0;
	repeatCount = 0;
	largestValue = 0;



	fgets(nums, 100, stdin);

	
	row = 0;
	col = 0;

	point = nums;
	
	for(col = 0; col < numItems; col++)
	{
	
		val = strtol(point, &point, 10);
	
		trueNums[row][col] = val;
		

	}



	while(repeatCount < 1 && row < LIMIT)
		{
			for(col = 0; col < numItems; col++)
			{
				if(trueNums[row][col] > largestValue)
				{
					largestValue = trueNums[row][col];
					largestIndex = col;
				}
			
			}


			row++;

			for(i = 0; i < numItems; i++)
			{
				trueNums[row][(i)%numItems] =	trueNums[row-1][(i)%numItems];
			}
			i = largestIndex+1;
			j = 0;
			trueNums[row][largestIndex] = 0;
			while(j < largestValue)
			{
					trueNums[row][(i)%numItems]++;
					i++;
					j++;
			}

			largestValue = 0;
			largestIndex = 0;
			
			for(i = 0; i < row; i++)
			{
				for(j = i+1; j <= row; j++)
				{
						if(memcmp(trueNums[i], trueNums[j],100) == 0)
						{
							repeatCount++;
						}
				}
			}




		}

	printf("Num of cycles %d\n", row - 1);

}
