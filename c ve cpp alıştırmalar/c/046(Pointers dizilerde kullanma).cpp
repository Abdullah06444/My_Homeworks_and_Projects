#include <stdio.h>

int main ()
{
	
	int c, d, e=1, dizi[3][3]= {{45 , 74 , 83},{71 , 29 , 99},{37 , 26 , 44}};
	int *ptr;
	
	for (c=0; c<3; c++)
	{
		
		for (d=0; d<3; d++)
		{
			
			printf ("%d inci sayi olan %d nin hafizadaki yeri %x\n", e, dizi[c][d], ptr+e);
			e++;
		}
	}
}
