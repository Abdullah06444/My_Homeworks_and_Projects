#include <stdio.h>

struct class_friends
{
	
	char name[15];
	char city[10];
	int age;
	int school_number;
	float average_note;	
}dad[5];

int main ()
{
	
	int i;
	
	for (i=0 ; i<5 ; i++)
	{
		
		printf ("Lutfen ogrencinin adini giriniz :");
		scanf ("%s", &dad[i].name);
		printf ("Ogrencinin dogum yeri :");
		scanf ("%s", &dad[i].city);
		printf ("Yasi :");
		scanf ("%d", &dad[i].age);
		printf ("Okul numarasi :");
		scanf ("%d", &dad[i].school_number);
		printf ("Not ortalaman :");
		scanf ("%f", &dad[i].average_note);
	}
	
	for (i=0 ; i<5 ; i++)
	{
		
		printf ("[%d] numarali ogrencinin adi %s, yasi %d,", dad[i].school_number, dad[i].name, dad[i].age);
		printf ("dogum sehri %s ve not ortalamasi %.2f\n", dad[i].city, dad[i].average_note);
	}
}
