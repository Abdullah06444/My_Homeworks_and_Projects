#include <stdio.h>

int main()

{
	int number, digits, sum;
	digits = sum = 0;
	scanf ("%d", &number);
	
	do
	{
		sum += number % 10;
		number /= 10;
		digits++;
		
	}
	while (number > 0);
	
	printf ("number of digits = %d sum = %d\n", digits, sum);
	
}

/*
#include <stdio.h>

int main ()

{	int ch, count;

	count = 0;
	ch = getchar ();
	
	while (ch != EOF) {
		putchar (ch);
		count++;
		ch = getchar ();
		
	}
	
	printf ("total characters echoed = %d\n", count);	
}

#include <stdio.h>

int main (void)

{
	int c, vowel, vowelcnt, charcnt;
	
	vowelcnt = charcnt = 0;
	
	while ((c = getchar ()) !=EOF)
	{
		c = (c >= 'A' && c <= 'Z')?
		(c - 'A' + 'a') : c;
		
		if (vowel) vowelcnt++;
		charcnt++;
	}
	
	printf ("vowels = %f\n", (float) vowelcnt/charcnt);
	
	return 0;
}
*/
