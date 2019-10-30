#include <iostream>
#include <cstring>

using namespace std;

int main()
{

	int i=0, j, k, m, counter[1000][1], counter2[1000][1];
	char array[1000][1000], variable[1000];
	
	
	while (cin >> array[i])
	{
		
		for (m=0; m<1000; m++)
			if (array[i][m] >= 65 && array[i][m] <= 90)
				array[i][m] += 32;
		
		counter[i][0] = 49;
		
		for (j=0; j<i; j++)
		{
			
			if (strcmp (array[i], array[j]) == 0)
			{
				
				counter[j][0]++;
				i--;
			}
		}
		
		i++;
	}
	
	cout << "Vocabulary Size = " << i << endl;
	
	for (j=0; j<i; j++)
	{

		for (k=j+1; k<i; k++)
		{
		
			if (strcmp (array[k], array[j]) < 0)
			{
								
				for (m=0; m<1000; m++)
				{
					
					variable[m] = array[k][m];
					array[k][m] = array[j][m];
					array[j][m] = variable[m];
				}
				counter2[k][0] = counter[k][0];
				counter[k][0] = counter[j][0];
				counter[j][0] = counter2[k][0];
			}
		}
		cout << array[j] << " ";
		cout << counter[j][0]-48 << endl;
	}
}
