#include <stdio.h>

int main ()

{
	int x, y;
	float sum;
	x = 1;
	sum = 0;
	scanf ("%d", &y);
	
	while (y < 0) {
		
		scanf ("%d", &y);
		
	}
	
	while (x!= y+1) {
		
		sum += (float) 1/x;
	
		x++;
	}
	
	printf ("%.2f", sum);
	
}
