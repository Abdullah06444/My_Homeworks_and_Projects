#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void national_lottery(long int value)
{
	
	int i, j, k1, k2, k3, variable, variable2, ran[value][5], win[5];
	srand(time(NULL));
	k1 = k2 = k3 = 0;
	for (j=0; j<5; j++)
	{
		
		variable2 = 0+rand()%9;
		win[j] = variable2;
	}
	for (i=0; i<value; i++)
	{
		if (i==0)
			printf ("The lottery of 1st person is\t\t-----> ");
		else if (i==1)
			printf ("The lottery of 2nd person is\t\t-----> ");
		else if (i==2)
			printf ("The lottery of 3rd person is\t\t-----> ");
		else
			printf ("The lottery of %dth person is\t\t-----> ", i+1);
		
		for (j=0; j<5; j++)
		{
		
			variable = 0+rand()%9;
			printf ("%d ", variable);
			ran[i][j] = variable;
		}
		printf ("\n");
	}
	
	printf ("%d %d %d %d %d ", win[0], win[1], win[2], win[3], win[4]);
	printf ("<----- These lucky numbers for the winner.\n$$$ NATIONAL LOTTERY $$$\n");
	for (i=0; i<value; i++)
	{
		
		j=0;
		while (j<5)
		{
			
			if (ran[i][j] == win[j])
			{
				
				if (j==4 && k1 == 0)
				{
					
					printf ("CONGRATULATIONS! $$$ You win a national lottery. $$$\n");
					printf ("Your lottery is\t\t-----> %d %d %d %d %d\n", ran[i][0], ran[i][1], ran[i][2], ran[i][3], ran[i][4]);
					printf ("The %dth person , you have a richer person anymore in the world.\n", i+1);
					printf ("You have won fifty million dollars among %d person.\n", value);
					printf ("----------$$$----------\n");
					break;
					k1++;
				}
				else if (j==4 && k1 != 0)
				{
					
					printf ("Sorry man/woman! Because, you are not first winnner. The %dth person.\n", i+1);
					printf ("Your lottery is\t\t-----> %d %d %d %d %d\n", ran[i][0], ran[i][1], ran[i][2], ran[i][3], ran[i][4]);
				}
				else if (j==3 && k2 == 0)
				{
					
					printf ("CONGRATULATIONS! $$$ You win a national lottery. $$$\n");
					printf ("Your lottery is\t\t-----> %d %d %d %d %d\n", ran[i][0], ran[i][1], ran[i][2], ran[i][3], ran[i][4]);
					printf ("The %dth person , you have a richer person anymore in the world.\n", i+1);
					printf ("You have won ten million dollars among %d person.\n", value);
					printf ("----------$$$----------\n");
					k2++;
				}
				else if (j==3 && k2 != 0)
				{
					
					printf ("Sorry man/woman! Because, you are not first winnner. The %dth person.\n", i+1);
					printf ("Your lottery is\t\t-----> %d %d %d %d %d\n", ran[i][0], ran[i][1], ran[i][2], ran[i][3], ran[i][4]);
				}
				else if (j==2 && k3 == 0)
				{
					
					printf ("CONGRATULATIONS! $$$ You win a national lottery. $$$\n");
					printf ("Your lottery is\t\t-----> %d %d %d %d %d\n", ran[i][0], ran[i][1], ran[i][2], ran[i][3], ran[i][4]);
					printf ("The %dth person ,You have won ten thousand dollars among %d person.\n", i+1, value);
					printf ("----------$$$----------\n");
					k3++;
				}
				else if (j==2 && k3 != 0)
				{
					
					printf ("Sorry man/woman! Because, you are not first winnner. The %dth person.\n", i+1);
					printf ("Your lottery is\t\t-----> %d %d %d %d %d\n", ran[i][0], ran[i][1], ran[i][2], ran[i][3], ran[i][4]);
				}
				j++;
			}
			else
			{
				
				j=5;
			}
		}
	}
}

int main ()
{
	
	long int i;
	while (scanf ("%d", &i))
	{

		national_lottery(i);
		if (i == 0)
			break;
	}
}
