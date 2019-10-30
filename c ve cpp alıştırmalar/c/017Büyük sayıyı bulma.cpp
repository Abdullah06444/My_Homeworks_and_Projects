// Büyük sayýyý bulma

#include <stdio.h>

int main (void)

{	int a, b, c, d;
	
	scanf ("%d", & a );
	scanf ("%d", & b );
	scanf ("%d", & c );
	scanf ("%d", & d );
	
	if ( a > b ) {
		if ( a > c ) {
			if ( a > d ) {
				printf ("largest number is %d", a);
			
			}
			else {
				printf ("largest number is %d", d);
			
			}
		}
		else if ( c > d ) {
			printf ("largest number is %d", c);
			
		}
		else {
			printf ("largest number is %d", d);
		
		}
	}	
	else if ( b > c ) {
		if ( b > d ) {
		printf ("largest number is %d", b);
			
		}
		else {
		printf ("largest number is %d", d);
		
		}
	}
	else if ( c > d ) {
		printf ("largest number is %d", c);
		
	}
	else {
		printf ("largest number is %d", d);
		
	}
	
	return 0;
}
