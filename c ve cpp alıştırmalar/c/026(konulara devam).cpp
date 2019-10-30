#include <stdio.h>

int main ()

{
	int b, c, d=1;
	float a;
	scanf ("%f", &a);
	
	while (a < 1 || (int) a != (float) a) {
		scanf ("%f", &a);
		
	}

	for (b=1 ; a >= b ; b++) {
		scanf ("%d", &c);
		d *= c;

	}

	b=1 ;

	while (a >= b) {
		printf ("%d\n", d);
		b++;
	}

}
