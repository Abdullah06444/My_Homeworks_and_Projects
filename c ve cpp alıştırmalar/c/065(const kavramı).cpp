/* Sabit bir veri için sabit olmayan gösterici kullanarak bir stringin karakterlerini sýrayla yazdýrmak */
#include <stdio.h>

void karakterleriYazdir(const char *);

int main ()
{
	
	char string [] = "string karakterlerini yaz";
	
	printf ("String:\n");
	karakterleriYazdir(string);
	printf ("\n");
	
	return 0;
}

void karakterleriYazdir(const char *sPtr)
{
	
	for (; *sPtr != '\0'; sPtr++)
		printf ("%c", *sPtr);
}
