/* Sabit bir veri için sabit olmayan gösterici kullanarak deðeri deðiþtirmeye çalýþmak */
#include <stdio.h>

void f(const int *);

int main()
{
	
	int y;
	
	f(&y);
	
	return 0;
}

void f(const int *xPtr)
{
	
	*xPtr = 100;
}
