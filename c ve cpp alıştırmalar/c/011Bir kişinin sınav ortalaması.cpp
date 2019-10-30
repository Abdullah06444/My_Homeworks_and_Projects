#include <stdio.h>
int main (void)

{	int x;
	int y;
	int z;
	float a;
	
	printf ("First exam point\n");
	scanf ("%d",&x);
	printf ("Second exam point\n");
	scanf ("%d",&y);
	printf ("Last exam point\n");
	scanf ("%d",&z);
	
	a = (x+y+z)/3.0;
	
	printf ("The General Exam Average %.2f", a);
	
	return 0;
}
