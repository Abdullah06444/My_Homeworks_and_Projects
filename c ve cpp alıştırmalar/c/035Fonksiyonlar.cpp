#include <stdio.h>

	int factorial(int number)
{
	int sum = 1;
	
		for (; number > 0; number--)
	{	
		sum *= number;
	}

	return sum;
}

int main ()
{
	int number;
	
	printf ("Please, can you enter a number?\n");
	scanf ("%d", &number);	
	printf ("%d", factorial(number));
	
	return 0;
}
