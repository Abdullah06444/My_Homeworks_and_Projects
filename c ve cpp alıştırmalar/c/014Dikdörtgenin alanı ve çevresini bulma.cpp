#include <stdio.h>
int main ()

{	int small_side;
	int big_side;
	int rectangle_area;
	int circumference;
		
	printf ("Could you please enter a value for small side:\n");
	scanf ("%d", &small_side);
	
	printf ("Could you please enter a value for big side:\n");
	scanf ("%d", &big_side);
	
	rectangle_area = small_side * big_side;
	circumference= 2 * small_side + 2 * big_side;
	
	printf ("Rectangle area: %d\n", rectangle_area);
	printf ("Circumference: %d", circumference);
	
	return 0;
}
