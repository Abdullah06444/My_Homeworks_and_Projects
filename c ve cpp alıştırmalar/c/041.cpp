#include <stdio.h>

int main ()

{
	int i;
	void incr(void);
	
	for (i=0 ; i<3 ; i++)
	incr ();
	
	return 0;
}

void incr(void)
{
	int auto_i = 0;
	static int static_i = 0;
	
	printf ("auto = %d static = %d\n", auto_i++, static_i++);
}
