#include <stdio.h>

int prm(int *x)
{	

	return *x;
}

void swap(int *x, int *y)
{
	
	int z = *x;
	*x = *y;
	*y = z;

}

int main()
{
	
	int v1, v2, result=1;
	
	do
	{

	scanf ("%d", &v1);
	scanf ("%d", &v2);
	}
	while (v1<=0 || v2<0 || v2>v1);
	
	swap(&v1,&v2);
	printf ("%d %d\n", v1, v2);
	
	while (v1!=0)
	{
	
	result*= prm(&v2);
	v1--;
	v2--;
	}
	
	printf ("%d\n", result);
	
}
