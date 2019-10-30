#include <stdio.h>
#include <string.h>

void opposite(char array[])
{
	
	int counter, size, variable;
	size = strlen(array);
	
	for (counter = 0; counter < (size / 2); counter++)
	{
		
		variable = array [counter];
		array[counter] = array[size - 1 - counter];
		array[size - 1 - counter] = variable;
	}
}

int main ()
{
	
	char reverse[300];
	scanf ("%s", reverse);
	opposite(reverse);
	printf ("%s", reverse);
}
