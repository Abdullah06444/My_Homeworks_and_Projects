#include <stdio.h>

float f(int a, int b, int c)
{
	float sum;
	sum = 2*c*c*c + a*a + 5*b - c + 2;
	return sum;
}

int main ()
{
	int x, y, z;
	
	scanf ("%d %d %d", &x, &y, &z);
	
	printf ("%.2f", f(x, y, z));
}
