#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Number
{
	int x;
	int y;
	int sum;
};


bool isAdjacent(struct Number a, struct Number b)
{

	if((a.x > 0 && b.x < 0) ||( a.y < 0 && b.y > 0)	|| (a.y > 0 && b.y < 0) ||(a.x < 0 && b.x > 0))
	{
		return 0;
	}
	return (abs(abs(a.x) - abs(b.x)) <= 1 &&  abs(abs(a.y) - abs(b.y)) <= 1);
}

int main()
{
	#define VALUE 100
	struct Number nums[100];
	long limit, xCoord, yCoord, distance, count, i;
	limit = 1;
	xCoord = 0;
	yCoord = 0;
	distance = 0;
	count = 0;
	nums[count].x = xCoord;
	nums[count].y = yCoord;
	while(count  < VALUE)
	{
		for(i = xCoord; i < limit; i++)
		{
			if(count < VALUE)
			{
				nums[count].x = xCoord;
				nums[count].y = yCoord;
				nums[count].sum = 0;
				xCoord++;
				count++;
			}
		}
	
		for(i = yCoord; i < limit; i++)
		{
			if(count < VALUE)
			{
				nums[count].x = xCoord;
				nums[count].y = yCoord;
				nums[count].sum = 0;
				yCoord++;
				count++;

			}
		}
		for(i = xCoord; i > limit*(-1); i--)
		{
			if(count < VALUE)
			{
				nums[count].x = xCoord;
				nums[count].y = yCoord;
				nums[count].sum = 0;
				xCoord--;
				count++;

			}
		}
		for(i = yCoord; i > limit*(-1);i--)
		{
			if(count < VALUE)
			{
				nums[count].x = xCoord;
				nums[count].y = yCoord;
				nums[count].sum = 0;
				yCoord--;
				count++;

			}
		}
		limit++;
	}

	nums[0].sum = 1;
	count = 1;
	while(nums[count-1].sum  < 289326)
	{
		for(i = 0; i < count; i++)
		{
			if(isAdjacent(nums[count],nums[i]))
			{
			//	printf("Value being added %i\n", nums[i].sum);
				nums[count].sum += nums[i].sum;
			}
		}
		printf("Sum = : %i\n", nums[count].sum );
		count++;
	}
/*	printf("Coords: %d %d \n", nums[11].x,nums[11].y);
	printf("Coords: %d %d \n", nums[10].x,nums[10].y);
*/	printf("Adjacent? %i\n", isAdjacent(nums[12],nums[10]));

}
