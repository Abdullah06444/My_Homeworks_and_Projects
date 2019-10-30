/* Herhangi bir sayý girip, sonra girdiðimiz sayý kadar sayý girip
bu sayýlarýn çarpýmýný bastýrma. */
#include <stdio.h>

int main ()

{
	int m, n, k;
	scanf ("%d", &n);
	k = 1;
	
	while (n < 1) {
		scanf ("%d", &n);
	}
	
	while (n >= 1) {
		scanf ("%d", &m);
		n--;
		k *= m;
	}

	printf ("%d\n", k);

}
