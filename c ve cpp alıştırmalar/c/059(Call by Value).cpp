// Call by Value
#include <stdio.h>

int cube(int); // prototip

int main()
{
	
	int number;
	scanf("%d", &number);
	
	number;
	printf("The initial value of number is %d.\n", number);
	cube(number);
	printf("The terminal value of number is %d.\n", number);
}

int cube(int x)
{
	
	x = x * x * x; // yerel deðiþken x in küpünü al
	printf("The x^3 is %d.\n", x);
}
