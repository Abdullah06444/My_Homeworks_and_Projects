// Karakterlerin boyutlarý.

#include <stdio.h>

int main (void)

{
	printf ("%d byte\n", sizeof (char));
		printf ("%d byte\t", sizeof (int));
			printf ("%d byte\t", sizeof (short int));
				printf ("%d byte\n", sizeof (long int));
					printf ("%d byte\n", sizeof (float));
						printf ("%d byte", sizeof (double));
	
	return 0;
}
