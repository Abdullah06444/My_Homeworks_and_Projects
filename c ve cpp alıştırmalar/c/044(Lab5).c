#include <stdio.h>
#define BUFFER_SIZE 100

int main()
{

	int counter, counter2, c, r;
	char ch;
	char array[BUFFER_SIZE][BUFFER_SIZE];
	scanf ("%d", &c);
	scanf ("%d", &r);

	for (counter = 0;counter < c;counter++)
	{

		counter2 = 0;
		while (counter2 < r)
		{

			scanf ("%c", &ch);
			if (ch == ' ' || ch == '\n' || ch == '\t')
			{

			}
			else
			{
			
			array[counter][counter2] = ch;
			counter2++;
			}
		}
	}
	
	for (counter = 0;counter < c;counter++)
	{

		for (counter2 = 0;counter2 < r;counter2++)
		{

			printf ("%c ", array[counter][counter2]);
		}
		printf ("\n");
	}

	while (scanf ("%c", &ch)!=EOF)
	{

		char ch1, ch2;
		if (ch == 'r')
		{

				do
				{

					scanf ("%c", &ch1);
				}
				while (ch1 == ' ' || ch1 == '\n' || ch1 == '\t');
				do
				{

					scanf ("%c", &ch2);
				}
				while (ch2 == ' ' || ch2 == '\n' || ch2 == '\t');
			printf ("\nreplacing %c with %c:\n", ch1, ch2);
			
			for (counter = 0;counter < c;counter++)
			{

				for (counter2 = 0;counter2 < r;counter2++)
				{

					if (ch1 == array[counter][counter2])
					{

						array[counter][counter2] = ch2;
					}
					printf ("%c ", array[counter][counter2]);
				}
			printf ("\n");
			}
		}
	}
}

/*

1) satır ve sütun sayısı max 100 olan bir iki boyutlu dizi tanımla.
2) bu satır ve sütunların her biri için bir karakter gir ve hafızada tut.
3) daha sonra yeni karakterler girmeye başla.
	3.1) eğer karakter r ise şu komutları yaptır. Tabii önce iki tane karakter girmeli.
		3.1.1) boşluk, \n ve \t ifadelerini görmezden gel.
		3.1.2) ayrıca karakter dizinin satır ve sütunundan farklı ise;
			3.1.2.1) input taki dizinin aynısını bastır (veya bir önceki dizinin aynısını).
		3.1.3) ayrıca karakter dizinin satır ve sütunundan farklı değil ise;
			3.1.3.1) o karakterin yerine ikinci yazdığın karakteri yapıştır.
	3.2) değilse bir daha karakter gir.
4) end of file ile bitir kodunu. terminal the program.

*/
