#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int *p, i, j;
	p = (int*)malloc(12*sizeof(int));
	
	for (i=0 ; i<3; i++)
	{
		
		for (j=0 ; j<4; j++)
		{
			
			p[i * 4 + j] = i;
		}
	}
	
	for (j=0 ; j<4; j++)
	{
		
		for (i=0 ; i<3; i++)
		{
			
			printf("%d ", p[i*4+j]);
		}
		printf ("\n");
	}
}
