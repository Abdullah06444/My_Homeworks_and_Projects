#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{

	while (--argc)	printf("%s \n", strrev(*++argv));
		printf("\n");
		
		return 0;
}

/*
		INPUT
	....exe Ali Ahmet Ayse Hatice Huseyin
	
		OUTPUT
	ilA
	temhA
	esyA
	ecitaH
	niyesuH
*/
