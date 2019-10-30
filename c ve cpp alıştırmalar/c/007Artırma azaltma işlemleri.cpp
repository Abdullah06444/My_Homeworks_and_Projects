// Artýrma Azaltma iþlemleri
#include <stdio.h>

int main(void)

{
	int x = 2;
		int y = 3;
			int z = -4;
	
	x = y + 2;
		z = x - 3;
	
	// x = 5 , y = 3 , z = 2 ;
	
	printf ("x ---> %d\ty ---> %d\tz ---> %d\n",x,y,z);
	
	z -= x - 5;
		y += z - 7;
	
	// x = 5 , y = -2 , z = 2 ;
	
	printf ("x ---> %d\ty ---> %d\tz ---> %d\n",x,y,z);
	
	x = ++x;
		y = y--;
			z = z++;
	
	// x = 6 , y = -2 , z = 2 ;
	
	printf ("x ---> %d\ty ---> %d\tz ---> %d\n",x,y,z);
	
	x = x++;
		y = --y;
			z = ++z;
	
	// x = 6 , y = -3 , z = 3 ;
	
	printf ("x ---> %d\ty ---> %d\tz ---> %d\n",x,y,z);
	
	return 0;
}
