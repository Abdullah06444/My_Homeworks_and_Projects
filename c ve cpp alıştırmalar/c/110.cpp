#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char* argv[])
{

	int i = 1, j=0, k=0, sum = 0;
	float x, y, average;
	char **aray[argc][50];
	
	for (; i < argc; i++)
	{
		
		if (isalpha(*argv[i]) != 0)
		{
			
			aray[i][j] = &argv[i];

			while (aray[i][j] != '\0')
				j++;
			printf("%c", toupper(**aray[i][j-1])); 
			printf("%c ", toupper(**aray[i][0]));
		}
		
		else if(isdigit(*argv[i]) != 0)
		{
		
			sum += atoi(argv[i]);
			k++;
		}
	}
	
	average = (float) sum / k;
	
	x = average - floor(average);
	y = ceil(average) - average;
	
	if (x >= y)
		printf ("%.0f ", ceil(average));
		
	else if (x < y)
		printf ("%.0f ", floor(average));
}
