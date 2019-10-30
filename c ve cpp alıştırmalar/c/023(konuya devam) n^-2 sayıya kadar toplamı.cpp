#include <stdio.h>

int main ()

{
	int x, y;
	double sum;
	x = 1;
	sum = 0;
	
	scanf ("%d", &y);
	
	while (x <= y) {
	
	sum += (float) 1/(x*x);
	x++;
	}
	printf ("%.16f", sum);
}
