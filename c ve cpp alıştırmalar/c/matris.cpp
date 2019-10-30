#include <stdio.h>

int main ()
{
	
	int i, j, c=0;
	int mat[4][3] = { {1} , {1 , 0} , {1 , 0 , 1}};
	int mat2[4][3] = { 1 , 1 , 0 , 0 , 0 , 1 , 0 , 1 , 1 , 0 , 1 , 0};
	
	for (i= 0; i< 4 ; i++)
		for (j= 0; j< 3; j++)
			if (mat[4][3] && mat2[4][3])	c++;
	printf ("%d\n", c);

}
/*
	int n=69;
	char str2[20];
	char *str;
	str = "%d\n";
	str++;
	str++;
	
	strcpy(str2, "%c");
	strcat(str2, str-2);
	printf(str2, n, n);
*/

