#include <stdio.h>

int main()
{
	
	int sayi= 5;					// integer bir say� de�erimiz.
	int *p1;						// pointer�m�z say�n�n haf�zadaki yerini tutar.
	char cd= 'A', *p2;				// karakter pointer��m�z� da bu �ekilde tan�mlar�z.
	float value= 88.51, *p3;		// float bir de�erin haf�zadaki yerini p3 pointer� tutuyor.
	
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
