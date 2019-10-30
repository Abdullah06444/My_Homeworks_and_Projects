#include <stdio.h>

void change(int *ip)
{
	
	++(*ip);
	ip = NULL;
}

int main (void)
{
	
	int i= 0, *ip, *pi;
	ip = pi = &i;
	
	change(ip);
	printf ("new value of i = %d\n", i);
	
	if (ip = pi) printf("no change in ip %d\n", *ip);
}
