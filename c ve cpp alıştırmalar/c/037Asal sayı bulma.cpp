#include <stdio.h>

int prime_number (int number)
{
	int counter;
	
	if (number < 2)
	{
	return 0;
	}
		
	for (counter = 2; counter < number; counter++)
	
	if (number % counter == 0.0)
	{
	return 0;
	}
	
	return 1;
}

int main ()
{
	float f;
	scanf ("%f", &f);
	printf ("%d", prime_number (f));
	
}
