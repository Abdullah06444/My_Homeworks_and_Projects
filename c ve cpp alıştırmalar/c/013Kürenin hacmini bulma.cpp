// K�renin hacmini bulma.
#include <stdio.h>
#define PI 3.14

int main ()
{	int radius;
	float volume;
	float surface_area;
	
	printf ("Could you please enter a value for radius of sphere:\t");
	scanf ("%d", &radius);
	
	volume = ((4.0/3 /*4/3.0 b�lme de�erini float vermesi i�in en az birini float de�er yapmal�y�z. */)*PI*radius*radius*radius);
	printf ("The sphere volume: %.2f\n", volume);
	
	surface_area = (4*PI*radius*radius);
	printf ("The sphere surface area: %.2f", surface_area);
	
	return 0;
	
}
