/* Sabit bir veri i�in sabit olmayan g�sterici kullanarak bir stringin karakterlerini s�rayla yazd�rmak */
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
