// Kürenin hacmini bulma.
#include <stdio.h>
#define PI 3.14

int main ()
{	int radius;
	float volume;
	float surface_area;
	
	printf ("Could you please enter a value for radius of sphere:\t");
	scanf ("%d", &radius);
	
	volume = ((4.0/3 /*4/3.0 bölme deðerini float vermesi için en az birini float deðer yapmalýyýz. */)*PI*radius*radius*radius);
	printf ("The sphere volume: %.2f\n", volume);
	
	surface_area = (4*PI*radius*radius);
	printf ("The sphere surface area: %.2f", surface_area);
	
	return 0;
	
}
