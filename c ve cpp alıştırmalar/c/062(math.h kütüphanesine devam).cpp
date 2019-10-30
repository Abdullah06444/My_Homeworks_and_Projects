#include <stdio.h>
#include <math.h>

double func(int x)
{
	
	return log(x); // Eular tabanýndaki deðeri verir.
}

double func2(int x)
{
	
	return log10(x); // Logaritma 10 tabanýndaki deðeri verir.
}

double func3(int x)
{
	
	return exp(x); // Exponential ise eular kuvvetindeki deðeri verir.
}

int main()
{
	
	int number;
	double result;
	
	printf ("Lutfen bir sayi giriniz: ");
	scanf ("%d", &number);
	
	result = func(number);
	
	printf ("Sayinin eular tabanindaki degeri: %.16lf\n", result);
	
	result = func2(number);
	
	printf ("Sayinin logaritma 10 tabanindaki degeri: %.16lf\n", result);
	
	result = func3(number);
	
	printf ("Sayinin eular kuvvetinde degeri: %.16lf\n", result);
}
