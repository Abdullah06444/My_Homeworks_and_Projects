#include <stdio.h>
#include <string.h>

void chr(char name[])
{

	char input='q';
	
	if (strchr(name, input) != NULL) // Bu fonksiyon input karakterinin name dizisinin içerisinde olup olmadýðýný kontrol ediyor.
		printf("%c\n", input);
	else
		printf("It is not exist this character.\n");
}

void str(char name[])
{

	char input[] = "end";
	
	if (strstr(name, input)) // Bu fonksiyon input dizisinin name dizisinin içerisinde olup olmadýðýný kontrol ediyor.
		printf("%s\n", input);
	else
		printf("It is not exist this string.\n");
}

int main()
{

	char name[10];
	scanf("%s", name);
	
	chr(name);
	
	str(name);
}
