#include <stdio.h>

int main ()
{
	int number;
	
	while ((scanf ("%d", &number))!= EOF)
	{

		if (number >= 0)
		{
			
			printf ("Diamond size: %d\n", number);
			
			int variable = 2 * number;
			while (variable>0)
			{
				
				printf ("-");
				variable--;
			}
			printf ("-\n");
			
			int counter, counter2;
			for (counter=0; counter<number; counter++)
			{

				printf ("|");

				for (counter2=1; counter2<number-counter; counter2++)
				{

					printf (" ");
				}

				for (counter2=0; counter2<2 * counter + 1; counter2++)
				{

					printf ("*");
				}

				for (counter2=1; counter2<number-counter; counter2++)
				{

					printf (" ");
				}

				printf ("|\n");
			}

			for (counter=0; counter<number; counter++)
			{

				printf ("|");

				for (counter2=number; counter2>number-counter; counter2--)
				{

					printf (" ");
				}

				for (counter2=0; counter2<2 * (number - counter) - 1; counter2++)
				{

					printf ("*");
				}

				for (counter2=number; counter2>number-counter; counter2--)
				{

					printf (" ");
				}

				printf ("|\n");
			}
			
			variable = 2 * number;
			while (variable>0)
			{
				
				printf ("-");
				variable--;
			}
			printf ("-\n");					
		}
			
		else
		{
			
			printf ("Diamond size: %d\n", number);
			printf ("Done!\n");
			break;
		}
	
	}
	
	return 0;
}
