/* Bir stringi, sabit olmayan bir de�er i�in sabit olmayan bir g�sterici kullanarak b�y�k harfe �evirme */
#include <stdio.h>
#include <ctype.h>

void buyukHarfeCevir(char *);

int main()
{
	
	char string[ ]= "karakterler ve $32.98";
	printf ("Cevrilmeden onceki string: %s", string);
	buyukHarfeCevir(string);
	printf("\nCevrildekten sonraki string: %s\n", string);
	
	return 0;
}

void buyukHarfeCevir(char *sPtr)
{
	
	while (*sPtr != '\0')
	{
		
		if (islower (*sPtr))
			*sPtr = toupper(*sPtr); // b�y�k harfe �evir
			
		++sPtr; // *sPtr ile di�er karaktere ge�
	}
}
