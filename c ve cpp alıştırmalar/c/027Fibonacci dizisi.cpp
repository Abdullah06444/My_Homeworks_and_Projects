// Fibonacci Dizisi
#include <stdio.h>

int main ()

{
	int number1 = 1;
	int number2 = 1;
	int number3, value, x;
	
	scanf ("%d", &value);
	
	while (value <= 3)	{
		scanf ("%d", &value);	
		
	}

	printf ("%d\n%d\n", number1, number2);

	for (x = 2 ; x < value ; x++) {
		number3 = number2;
		number2 += number1;
		number1 = number3;
		
		printf ("%d\n", number2);
		
	}

}

/*

01,01,02,03,05,08,13,21,34,55,89,144,233,377, ... forever

1) Bir say� girece�iz.
2) Girdi�iniz say� kadar fib. dizisindeki say�y� bast�raca��z.
Dizideki bir say� kendinden �nceki iki say�n�n toplam� olaca�ndan.
3) Herhangi bir de�i�ken belirleriz ki say�lar bir ilerideki say�ya kayabilsin. �rene�in;
number3 = number2;
number2 += number1;
number1 = number3;

*/
