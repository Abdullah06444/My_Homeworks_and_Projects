/* Herhangi bir say� girip, sonra girdi�imiz say� kadar say� girip
bu say�lar�n �arp�m�n� bast�rma. */
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
