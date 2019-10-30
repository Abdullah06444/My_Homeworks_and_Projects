#include <stdio.h>

int main ()

{	float celsius = 0;
	while (celsius < 1.0)
{
	printf ("Celcius : %.2f Fahrenheit : %.2f\n", celsius, 1.8 * celsius + 32);
	celsius +=0.005;
}
	
}
