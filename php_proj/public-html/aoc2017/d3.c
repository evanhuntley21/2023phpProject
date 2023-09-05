#include <stdio.h>
#include <stdlib.h>


int main()
{
	#define VALUE1 12345678999
	#define VALUE 289326

	long limit, xCoord, yCoord, distance, count, i;
	limit = 1;
	xCoord = 0;
	yCoord = 0;
	distance = 0;
	count = 1;
	while(count < VALUE)
	{
		for(i = xCoord; i < limit; i++)
		{
			if(count < VALUE)
			{
				xCoord++;
				count++;
			}
		}
	
		for(i = yCoord; i < limit; i++)
		{
			if(count < VALUE)
			{
				yCoord++;
				count++;
			}
		}
		for(i = xCoord; i > limit*(-1); i--)
		{
			if(count < VALUE)
			{
				xCoord--;
				count++;
			}
		}
		for(i = yCoord; i > limit*(-1);i--)
		{
			if(count < VALUE)
			{
				yCoord--;
				count++;
			}
		}
		limit++;
	}
	printf("X coordinate: %ld\n", xCoord);
	printf("Y coordinate: %ld\n", yCoord);
	distance = abs(xCoord) + abs(yCoord);

	printf("Distance = %ld\n", distance);
}
