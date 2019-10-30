#include <stdio.h>
#include <string.h>

int main()
{
	
	char username[10], password[10];
	char ch[10]={"Abdullah"};
	char ch2[10]={"14290100"};
	
	do
	{
		
		printf("Please! You enter your user name ");
		scanf("%s", username);
	}
	while (strlen(username)<7);
	
	do
	{
		
		printf("Please! You enter your password ");
		scanf("%s", password);
	}
	while (strlen(password)<7);
	
	if (strcmp(username,ch) == 0) /* Bu fonksiyon bir karakterin baþka bir karakterle kýyaslýyabilir
	ve de alfabetik olarak yerini kýyaslayabilir. */
	{
		
		if (strcmp(password,ch2) == 0)
		{
			
			printf("Well, You entered your username and password correctly.\n");
		}
		else if (strcmp(password,ch2) != 0)
		{
		
			printf("Sorry, You entered your username or password wrongly.\n");
		}
	}
	
	else if (strcmp(username,ch) != 0)
	{
		
		printf("Sorry, You entered your username or password wrongly.\n");
	}
}
