#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char input[30000];
int i = 0;
int depth = 0;
int sum = 0;
int ilen;
void garbanzo()
{
	while(input[i] != '>')
	{
		if(input[i] == '!')
		{
			i+=2;
		}
		else
		{
			i++;
		}
	}
}
void getDepth(int index)
{
	i = index;
	while(i < ilen)
	{
		if(input[i] != '<')
		{
			if(input[i] == '{')
			{
				depth++;
				getDepth(i+1);
			}
			else if(input[i] == '}')
			{
				sum+=depth;
				depth--;
				i++;
				return;
			}
			else
			{
				i++;
			}
		}
		else
		{
			garbanzo();
			i++;
		}
	}
}



void main()
{
	fgets(input, 30000, stdin);
	ilen = strlen(input) - 1;
	input[ilen] = '\0';
	getDepth(0);
	printf("Sum: %d\n", sum);
}
