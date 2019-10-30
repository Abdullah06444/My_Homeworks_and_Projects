#include <stdio.h>
#include <math.h>
#define PI 22.0/7.0

int main()
{
	
	int value;
	double angle, value2;
	
	scanf ("%d", &value);
	angle = value*PI/180.0;
	
	printf ("Bu acinin sinus degeri : %.6lf\n", sin(angle));
	printf ("Bu acinin cosinus degeri : %.6lf\n", cos(angle));
	printf ("Bu acinin tangent degeri : %.6lf\n", tan(angle));
}
