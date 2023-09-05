#include <stdio.h>
#include <string.h>



void main()
{
	int i, j, k,a,b,l,  copy, count;
	char *point;
	char strings[100][100];
	char string[100];
	char temp;

	while(fgets(string, 100, stdin)!=0)
	{
		string[strcspn(string, "\n")] = 0;
		i = 0;	
		point = strtok(string, " ");
		strcpy(strings[i], point);
		l = strlen(strings[i]);
  			for(a=1;a<l;a++) {
    				for(b=0;b<l-a;b++) {
					if(strings[i][b]>strings[i][b+1]) {
	  					temp=strings[i][b];
	  					strings[i][b] = strings[i][b+1];
	  					strings[i][b+1]=temp;
					}
				}
			}
		while(point != NULL)
		{
			point = strtok(NULL, " ");
			i++;
			if(point != NULL)
			{
				strcpy(strings[i], point);
				l = strlen(strings[i]);
  					for(a=1;a<l;a++) {
    						for(b=0;b<l-a;b++) {
								if(strings[i][b]>strings[i][b+1]) {
	  							temp=strings[i][b];
	  							strings[i][b] = strings[i][b+1];
	  							strings[i][b+1]=temp;
					}
				}
			}

			}
		}
	
		copy = 0;
		for(j = 0; j < i; j++)
		{
			for(k = j + 1; k<=i; k++)
			{
				if(strcmp(strings[j], strings[k]) == 0)
				{
					copy = 1;
					
				}

			}
			puts(strings[j]);
		}
		if(copy != 1)
		{
			printf("ADDING to Count %i\n", count);
			count++;
		}
	}
	printf("Num Valids : %i\n", count);
}
