#include <stdio.h>
#include <stdlib.h>

void main()
{
	struct pgm
	{
		int num;
		struct  pgm* next;
	};
	int i;

	struct pgm start;
	struct pgm* nextPgm = NULL;


	start.num = 1;
	nextPgm = (struct pgm*)malloc(sizeof(struct pgm));
	start.next = nextPgm;

	nextPgm -> next = malloc(sizeof(struct pgm));
	nextPgm -> num = 2;
	nextPgm = nextPgm -> next;

	nextPgm -> num = 3;

	nextPgm = start.next;
	while(nextPgm != NULL)
	{
		printf("\nnum: %d\n", nextPgm -> num);
		nextPgm =  nextPgm -> next;
	}

	
	


}
