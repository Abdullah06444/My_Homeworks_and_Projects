#include <stdio.h>
#include <string.h>

int main()
{
	
/*	int x = 0;
	int y = 0;
	
	if (++x || ++y)
		y += x++;
	
	printf ("%d %d\n", x, y);
*/

	int n=69;
	
	char str2[20];
	char *str;
	str = "%d";
	str++;
	str++;
	
	strcpy(str2, "%d");
	strcat(str2, str-2);
	printf(str2, n, n);
}

/*
n = 69 , *str = %d\n , str2 = %c;
                       str2 = %c%d;
E59

*/
