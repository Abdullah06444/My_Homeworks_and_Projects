#include <stdio.h>
int main ()

{
	int number, counter = 1, sum = 0;
	scanf ("%d", &number);
	
	while (counter < number) {
		if (number % counter == 0)
		{
		sum += counter;
		counter++;
		}
		else {
		counter++;
		}
	}
	
	if (sum < number) {
		printf ("%d is deficient", sum);
	}
	else if (sum == number) {
		printf ("%d is perfect", sum);
	}
	else {
		printf ("%d is abundant", sum);
	}
	
}
