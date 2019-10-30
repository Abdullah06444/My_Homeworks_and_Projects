#include <stdio.h>

int main()
{
	
	int sayi= 5;					// integer bir sayý deðerimiz.
	int *p1;						// pointerýmýz sayýnýn hafýzadaki yerini tutar.
	char cd= 'A', *p2;				// karakter pointerýýmýzý da bu þekilde tanýmlarýz.
	float value= 88.51, *p3;		// float bir deðerin hafýzadaki yerini p3 pointerý tutuyor.
	
	printf ("%d\n", sayi);
	printf ("%x\n", &sayi);
	p1 = &sayi;
	p1++;	
	printf ("%x\n", p1);
	printf ("%c\n", cd);
	printf ("%x\n", &cd);
	p2 = &cd;
	p2--;
	printf ("%x\n", p2);
	printf ("%.4f\n", value);
	p3 = &value;
	printf ("%x\n", p3);
	p3--;
	printf ("%x\n", p3);
	
}
