/* Sabit bir veri i�in sabit olmayan g�sterici kullanarak de�eri de�i�tirmeye �al��mak */
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
