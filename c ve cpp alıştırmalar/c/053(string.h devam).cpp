#include <stdio.h>
#include <string.h>

// strnc..(parameter2, parameter, size_t n); Format bu þekilde.

int main()
{
	
	char city[20], input[20], input2[20];
	scanf ("%s", city);
	scanf ("%s", input);
	
	strncat(city, input, 5); // Bu fonksiyon input dizisinin n=5 karakterini city dizisine ekler.
	printf ("%s\n", city);
	
	strncpy(input2, input, 4); // Bu fonksiyon input dizisinin n=4 karakterini input2 dizisine kopyalar.
	printf ("%s\n", input2);
	
	if (strncmp(city, input, 3) == 0) // Bu fonksiyon input dizisinin ilk n=3 karakterini city dizisiyle karþýlaþtýrýr.
		printf ("Correct\n");
	else
		printf ("Wrong\n");
}
