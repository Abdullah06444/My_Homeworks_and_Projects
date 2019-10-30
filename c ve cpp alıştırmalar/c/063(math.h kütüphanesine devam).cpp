#include <stdio.h>
#include <math.h>

int main()
{
	
	int number, *ptr;
	double result;
	
	scanf ("%d", &number);
	
	ptr = &number;
	result = fabs(*ptr); // mutlak değeri hesaplar.
	
	printf ("%.0lf\n", result);
		
	result = ceil(sqrt(*ptr)); // sayıyı kendisine yakın olan büyük tam sayıya yuvalar.
	
	printf ("%d sayisinin yuvarlanmis hali %.0lf\n", number, result);

	result = floor(sqrt(*ptr)); // sayıyı kendisine yakın olan küçük tam sayıya yuvarlar.

	printf ("%d sayisinin yuvarlanmis hali %.0lf\n", number, result);
	
	int number2;
	
	scanf ("%d", &number2);
	result = fmod(number, number2);
	
	printf ("%.6lf\n", result);
}
