// Call by Reference
#include <stdio.h>

void square(int *); // prototip

int main()
{
	
	int number;
	scanf("%d", &number);
	
	number;
	printf("The initial value of number is %d.\n", number);
	square(&number);
	printf("The terminal value of number is %d.\n", number);
}

void square(int *x)
{
	
	*x = *x * *x; // maindeki say�n�n karesi al
	printf("The x^2 is %d.\n", *x);
}
