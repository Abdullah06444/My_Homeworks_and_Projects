// Hacer Hocanýn sorusu

#include <stdio.h>

int main (void)

{
	int monthly_income;
	float monthly_tax;
	
	printf ("The monthly income is ");
	scanf ("%d", & monthly_income); 
	
	if ( monthly_income < 1000 ) {
		monthly_tax = (0.0 * monthly_income);
		printf ("S/He will not pay any tax.\n");
		printf ("%.2f TL.", monthly_tax);

	}
	else if ( monthly_income >= 1000 && monthly_income < 3000 ) {
		monthly_tax = (0.1 * monthly_income);
		printf ("S/He should pay ");
		printf ("%.2f TL.", monthly_tax);
		
	}
	else {
		monthly_tax= (0.15 * monthly_income);
		printf ("S/He should pay ");
		printf ("%.2f TL.", monthly_tax);
		
	}
	
	return 0;
}
