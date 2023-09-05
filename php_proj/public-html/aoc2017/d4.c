#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char a[50])
{
	int count = 0;
	char *str;
	char *b;
	char mat[50][50];
	duplicateCurrentArray(a, mat[0], strlen(a));
	

	
	while(mat[count] != NULL)
	{
		
		printf("Length of row %ld\n Row output %s\n", strlen(mat[count]), mat[count]);
		printf("Before strtok ");
		str = strtok(mat[count], " ");
		count++;
		while(str != NULL)
		{


			printf("Current str: %s\n", str);
			printf("Right before crash?\n ");
			str = strtok(NULL , " ");
			printf("After current str\n ");
		}
		printf("A "	);	
		a = strchr(a, ' ');
		printf("B ");
		*a = a[1];
		puts(a);
		if(a != NULL)
		{

			duplicateCurrentArray(a, mat[count], strlen(a));
		}

	

	}
	return false;

}

void duplicateCurrentArray(char template[50], char b[50], int len)
{
	int i;
	printf("template array%s\n", template);
	printf("String len: %d\n", len);
	for(i = 0; i < len; i++)
	{
		b[i] = template[i];
		printf("i = %c\n", b[i]);
	}
	printf("Made it through loop ");
}



void main()
{
	char string[50];
	fgets(string, 50, stdin);
	string[strcspn(string, "\n")] = 0;
	isValid(string);
	fgets(string, 50, stdin);
	string[strcspn(string, "\n")] = 0;
	isValid(string);
}
