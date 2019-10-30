#include <stdio.h>
#include <string.h>

int main()
{
	
	char name[50];
	scanf("%s", name);
	
	printf("%s\n", strrev(name)); // Bu fonksiyonda bir karakterin tersini yazdýrýr.
	
	printf("%s\n", strlwr(name)); // Bu foksiyonda bir karakterde büyük harfle yazýlan harfleri küçük harfe çevirir.
	
	printf("%s\n", strupr(name)); // Bu fonksiyonda bir karakterde küçük harfle yazýlan harfleri büyük harfe çevirir.
	
	char name2[]="Malatya, Turkey, World", name3[50];
	strcpy(name3 , name2); // Karakteri baþka bir karaktere kopyalar.
	printf ("%s\n", name3);
}
