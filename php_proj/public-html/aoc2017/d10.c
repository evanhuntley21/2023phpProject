#include <stdio.h>
#include <stdlib.h>

#define SIZE 256


void main()
{
	int i, j, skip, loc, loc2,count;
	int elements[SIZE];
	int copy[SIZE];
	int lengths[16] = {14,58,0,116,179,16,1,104,2,254,167,86,255,55,122,244};
	skip = 0;
	loc = 0;
	for(i = 0; i < SIZE; i++)
	{
		elements[i] = i;
		copy[i] = i;
	}

	for(i = 0; i < 16; i++)
	{
		loc2 = loc;
		j = (loc + lengths[i] - 1) % SIZE;
		count = 0;
		copy[j] = elements[loc2];
		while(loc2 != (loc + lengths[i]) % SIZE)
		{

			loc2++;
			j--;
			count++;
			if(loc2 > SIZE - 1)
			{
				loc2 = 0;
			}
			if(j < 0)
			{
				j = SIZE - 1;
			}
			copy[j] = elements[loc2];
		}
		for(j = 0; j < SIZE; j++)
		{
			elements[j] = copy[j];
		}
		loc += lengths[i];
		loc += skip;
		if(loc > SIZE - 1)
		{
			loc%= (SIZE);
		}
		skip++;
	}
	printf("NUM: %d\n", elements[0] * elements[1]);
}
