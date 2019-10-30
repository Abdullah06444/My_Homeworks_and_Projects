/*
	Bu kütüphane fonksiyonlarý double olarak tanýmlandýklarýna dikkat edilim.
*/
#include <stdio.h>
#include <math.h>

double power(int x,int y)
{
	
	return pow(x, 2.0) + pow(y, 2.0); // pow(p1, p2) fonksiyonu 1. parametrenin 2. parametre kadar kuvvetini alýr.
}

double squareroot(double x)
{
	
	return sqrt(x); // sqrt(p) fonksiyonu parametrenin kökünü alýr.
}

int main ()
{
	
	int number, number2;
	double result;
	
	printf ("Lutfen ucgenin kenarlarini giriniz: ");
	scanf ("%d", &number);
	scanf ("%d", &number2);
	
	result = power(number, number2);
	
	printf ("%.4lf\n", result);
	
	result = squareroot(result);
	
	printf ("Hipotenus: ");
	printf ("%.4lf\n", result);
}
