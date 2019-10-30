#include <stdio.h>
#include <string.h>

int main()
{
	
	char cd[20]="MehmetAkifErsoy";
	int size = strlen(cd);	// Girilen karakterin uzunluðunu verir.
	printf ("%d\n", size);
	printf ("%d\n", strlen("ANKARA"));
	for(int i=strlen(cd)-1 ; i>=0; i--)
	{
		
		printf ("%c\n", cd[i]);
	}
}
