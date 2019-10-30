#include <stdio.h>

int main ()

{	int x = 3;
	float y = 1.5;
	int z = -5;
	
	printf ("%f\n",x/y);
	printf ("%f\n",(int)x);
	printf ("%f\n",(float)x);
	printf ("%d\n",(int)y);
	printf ("%d\n",x%z);
	
	return 0;
}
