#include <stdio.h>

int main ()

{
	
	int x;
	double y;
	y = 1;
	
	scanf ("%d", &x);

	while (x < 0) {
	
		scanf ("%d", &x);
			
	}
	
	while (x != 0) {
	
		y = x * y;
		
		x--;
	}
	
	printf ("%.0f", y);

}
