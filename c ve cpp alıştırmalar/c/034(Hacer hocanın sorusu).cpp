#include <stdio.h>
int main ()

{
	int count, counter, number, result, digit;
	
	counter = 0;
	count=2;
	result = 0;
	digit = 0;
	
	while((scanf("%d",&number))!=EOF)
	{
	
		if (number % 10 != 0.0)
		{
			while (count < (number/2.0))
			{
				if (number % count != 0.0)
				{
					continue;
				}
				else
				{
					result += (number * number);
					digit++;
				}
			count++;
			}
		}
		
		else
		{
			continue;
		}
		
			counter++;
	}

	printf("%d %d\n", digit, result);
	
	return 0;
}
