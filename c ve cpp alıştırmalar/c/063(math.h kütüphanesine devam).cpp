#include <stdio.h>
#include <math.h>

int main()
{
	
	int number, *ptr;
	double result;
	
	scanf ("%d", &number);
	
	ptr = &number;
	result = fabs(*ptr); // mutlak de�eri hesaplar.
	
	printf ("%.0lf\n", result);
		
	result = ceil(sqrt(*ptr)); // say�y� kendisine yak�n olan b�y�k tam say�ya yuvalar.
	
	printf ("%d sayisinin yuvarlanmis hali %.0lf\n", number, result);

	result = floor(sqrt(*ptr)); // say�y� kendisine yak�n olan k���k tam say�ya yuvarlar.

	printf ("%d sayisinin yuvarlanmis hali %.0lf\n", number, result);
	
	int number2;
	
	scanf ("%d", &number2);
	result = fmod(number, number2);
	
	printf ("%.6lf\n", result);
}
