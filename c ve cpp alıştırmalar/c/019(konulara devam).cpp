#include <stdio.h>

int main ()

{
	int number1, number2, number3;
	char operation;
	
	scanf ("%d %d %d %c", &number1, &number2, &number3, &operation);
	
	if (operation == 'x') {
		
		if (number1 > number2) {
			
			if (number1 > number3) {
				printf ("%d", number1);
			}
			
			else {
				printf ("%d", number3);
			}
			
		}
		
		else if (number2 > number3) {
			printf ("%d", number2);	
		}
		
		else {
			printf ("%d", number3);
		}
		
	}
	
	else if (operation == 'm') {
		
		if (number1 < number2) {
			
			if (number1 < number3) {
				printf ("%d", number1);
			}
			
			else {
				printf ("%d", number3);
			}
			
		}
		
		else if (number2 < number3) {
			printf ("%d", number2);	
		}
		
		else {
			printf ("%d", number3);
		}
		
	}
	
	else if (operation == 's') {
		printf ("%d", (number1 + number2 + number3));
	}
	
	else if (operation == 'a') {
		printf ("%.2f", (float) 1/3 * (number1 + number2 + number3));
	}
	
	return 0;
}
