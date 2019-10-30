#include <stdio.h>

int main ()
{
	int i = 1, j = 2;
	void exchange (int, int);
	
	printf ("main: i = %d j = %d\n", i, j);
	exchange (i,j);
	printf ("main: i = %d j = %d\n", i, j);
	return 0;
}

void exchange (int i, int j)
{
	int t;
	
	t = i, i = j, j = t;
	printf ("exchange: i = %d j = %d\n", i, j);
}
