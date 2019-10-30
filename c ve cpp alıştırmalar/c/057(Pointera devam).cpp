#include <stdio.h>

int main ()
{
	
	int i, arr[] = {1, 4, 2, 9, 0, 1, 0, 0};
	
	int *ptr;
	ptr = arr;
	printf ("%d - %p\n", *ptr, ptr);
	
	int *ptr2;
	ptr2 = &arr[1];
	printf ("%d - %p\n", arr[1], ptr2);
	
	for (i=0; i<8; i++)
	{
		
		printf ("Arrayin %d. elemani %d olan sayinin hafizadaki yeri %p\n", i+1, *(ptr+i), ptr+i);
	}
	
	char arr2[] = "Turkey";
	
	char *ptr3;
	ptr3 = arr2;
	printf ("%c - %x\n", *ptr3, ptr3);
	
	char *ptr4;
	ptr4 = &arr2[1];
	printf ("%c - %x\n", *ptr4, &arr2[1]);
	
	for (i=0; i<6; i++)
	{
		
		printf ("Arrayin %d. elemani %c olan sayinin hafizadaki yeri %p\n", i+1, *(ptr3+i), &arr2[i]);
	}
	
	char *city = "IStanBUL";
	i=0;
	while (city[i] != '\0')
	{
		
		printf ("%c - %x\n", *(city+i), (city+i));
		i++;
	}
	
	char *city2 = "WasHIngTon";
	while (*city2 != NULL)
	{
		
		printf ("%c - %x\n", *(city2), (city2));
		city2++;
	}
}
