#include <stdio.h>
#include <string.h>

int main()
{
	
	int grade[100], i=0, j=0, k;
	char student[100][15], ch[100][15], trm[] = "end";
	
	do
	{
		
		scanf("%s", student[i]);
		scanf("%d", grade[i]);
		i++;
	}
	while (student[i] != trm);
	
	do
	{
	
		scanf("%s", ch[j]);
		
		for (k=0 ; k<i; k++)
		{
			
			if (strcmp(student[k],ch[j]) == 0)
			{
				
				printf ("%s %d\n", student[k],ch[j]);
			}
		}
		printf ("%s NONE\n", student[k]);
		
		j++;
	}
	while (ch[j] != trm);
	
}
