#include <stdio.h>

int main ()

{	float celcius;
	float fahrenheit;
	
	printf ("Could you please enter a degree: ");
	scanf ("%f", &celcius);
	
	fahrenheit = ((1.8 * celcius) + 32);
	
	printf ("Fahrenheit degree is %.2f.", fahrenheit);
	
	return 0;
	
}
