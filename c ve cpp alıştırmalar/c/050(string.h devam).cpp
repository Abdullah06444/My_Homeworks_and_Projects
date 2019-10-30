#include <stdio.h>
#include <string.h>

int main ()
{
	
	char name[20], surname[20], message[]="Hello ";
	
	printf ("Please, you can give your name here : ");
	scanf ("%s", &name);
	
	printf ("and your surname here : ");
	scanf ("%s", &surname);
	
	strcat(name, surname); // Bu fonksiyon bir karakteri baþka bir karaktere ekler.
	int size = strlen(name);
	strcat(message, name);
	printf ("%s, the your name's size is %d.\n", message, size);
}
