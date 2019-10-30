#include <stdio.h>

int main ()
{
	
	int number=5, *ptr, **ptr2, ***ptr3;
	
	ptr = &number;
	ptr2 = &ptr;
	ptr3 = &ptr2;
	
	printf ("%d\n", number);
	
	printf ("%d %x %x\n", *ptr, ptr, &ptr);
	
	printf ("%d %x %x\n", **ptr2, ptr2, &ptr2);
	
	printf ("%d %x %x\n", ***ptr3, ptr3, &ptr3);
}
