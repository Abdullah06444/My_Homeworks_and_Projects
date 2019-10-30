#include <stdio.h>

int infinite_function(int value)
{
	int sum = 0;
	
	if (value < 0)
	{
		
	}
	
	else
	do
	{
		int remainder = value % 10;
		value /= 10;
		sum +=remainder;
	}
	while (value > 0);
	
	return sum;
}

int main ()
{
	float number;
	scanf ("%f", &number);
	printf ("%d", infinite_function(number));
}
