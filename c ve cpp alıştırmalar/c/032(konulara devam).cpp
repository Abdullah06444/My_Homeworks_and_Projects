#include <stdio.h>
int main ()

{
	int student, counter;
	int a, b, c, d;
	float e, f = 0;
	
	scanf ("%d", &student);
	
	for (counter = 1; counter <= student ; counter++)
	{
		scanf ("%d %d %d %d", &a, &b, &c, &d);
	
		e = (a + b + c + d)/4.0;
		printf ("The note average of %d. student is %.2f\n", counter, e);
		f += (float) e;

	}
	
	printf ("\nThe note average of class is %.2f\n", (float) f/(student));
	
	return 0;
}
