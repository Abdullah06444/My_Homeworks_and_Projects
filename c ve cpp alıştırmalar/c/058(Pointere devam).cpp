#include <stdio.h>

double factorial(int *value)
{
	
	int i;
	double result=1;
	if (*value < 0)
		return -1;
	else
	{
		for (i=1; i<=*value; i++)
		{
			
			result *= i;
		}
		return result;
	}
}

void reverse(int *value, int *value2)
{
	
	int variable = *value;
	*value = *value2;
	*value2 = variable;
}

int main()
{
	
	int x;
	printf ("Please, You enter the a value : \n");
	scanf("%d", &x);
	printf ("The result is %.0lf\n", factorial(&x));
	
	int y, z;
	printf ("Please, You enter the two values : \n");
	scanf("%d%d", &y, &z);
	reverse (&y, &z);
	printf ("The first value is %d and second value is %d after the values reverse.\n", y, z);
}
