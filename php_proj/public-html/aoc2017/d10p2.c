#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256


void main()
{
	//int numTest[16] = {65,27,9,1,4,3,40,50,91,7,6,0,2,5,68,22};
	int lessElements[16];
	int sortTest = 0;
	int addArr[5] =  {17, 31, 73, 47, 23};
	char input[100];
	int i, j,k, skip, loc, loc2,count;
	int elements[SIZE];
	int copy[SIZE];
	int numLoops;
	skip = 0;
	loc = 0;
	
	fgets(input, 100, stdin);

	int ilen = strlen(input) - 1;
	input[ilen] = '\0';
	int lengths[ilen + 5];
	
	for(i = 0; i < ilen; i++)
	{
		lengths[i] = input[i];
	}
	for(i = ilen; i < ilen + 5; i++)
	{
		lengths[i] = addArr[i - ilen];
	}





		for(i = 0; i < SIZE; i++)
		{
			elements[i] = i;
			copy[i] = i;
		}


		for(numLoops = 0; numLoops < 64; numLoops++)
		{
		for(i = 0; i < ilen + 5 ; i++)
		{
			loc2 = loc;
			j = (loc + lengths[i] - 1) % SIZE;
			for(k = 0; k < lengths[i]; k++)
			{
				copy[j] = elements[loc2];
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
	
				}
				for(j = 0; j < SIZE; j++)
				{
					elements[j] = copy[j];
				}
				loc += lengths[i];
				loc += skip;
				while(loc > SIZE - 1)
				{
					loc%= (SIZE);
				}
				skip++;
			}
		}
		for(i = 0; i < 16; i++)
		{
			lessElements[i] = elements[0 + 16 * i] ^ elements[1 + 16 * i];
			for(j = 1; j < 15; j++)
			{
				lessElements[i] ^= elements[j+1 + 16 * i];
			}
		}
		for(i = 0; i < 16; i++)
		{
			printf("%02X", lessElements[i]);
		}
	}


