#include <stdio.h>

int main ()
{
	
	int integer = 5, *p_int;
	char character = 'f', *p_chr;
	float value = 4.875 , *p_flt;
	double value2 = 9.945 , *p_dbl;
	
	p_int = &integer;
	p_chr = &character;
	p_flt = &value;
	p_dbl = &value2;
	
	printf ("%d sayisinin hafizadaki yeri %p\n", integer, p_int);				// p de�i�ken belirleyicisi hexadecimal notation yerini g�sterir.
	printf ("%c karakterinin hafizadaki yeri %u\n", character, p_chr);			// u de�i�ken belirleyicisi normal onluk sistemdeki yerini s�yler.
	printf ("%.1f degerinin hafizadaki yeri %x\n", value, p_flt);				// x de�i�ken belirleyicisi ise hexadecimal sistemdeki halini...
	printf ("%.2lf degerinin hafizadaki yeri %u %x\n", value2, p_dbl, p_dbl);	// ...ba�taki s�f�rlar� hesaba katmadan g�sterir.
}
