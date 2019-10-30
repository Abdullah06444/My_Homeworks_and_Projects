#include <stdio.h>

int main()
{
	
	int c;
	char array[] = "Abdullah";
	char *ptr;
	ptr = array;
	
	for (c = 0; c < 8; c++ )
	{
		
		printf("%d inci karakter %c ve hafizadaki yeri %x\n", c+1, *(ptr+c), (ptr+c));
		printf("%d inci karakter %c ve hafizadaki yeri %x\n", c+1, array[c], &array);
	}
}
