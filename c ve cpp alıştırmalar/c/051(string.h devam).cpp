#include <stdio.h>
#include <string.h>

int main()
{
	
	char name[50];
	scanf("%s", name);
	
	printf("%s\n", strrev(name)); // Bu fonksiyonda bir karakterin tersini yazd�r�r.
	
	printf("%s\n", strlwr(name)); // Bu foksiyonda bir karakterde b�y�k harfle yaz�lan harfleri k���k harfe �evirir.
	
	printf("%s\n", strupr(name)); // Bu fonksiyonda bir karakterde k���k harfle yaz�lan harfleri b�y�k harfe �evirir.
	
	char name2[]="Malatya, Turkey, World", name3[50];
	strcpy(name3 , name2); // Karakteri ba�ka bir karaktere kopyalar.
	printf ("%s\n", name3);
}
