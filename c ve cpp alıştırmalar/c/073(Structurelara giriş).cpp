#include <stdio.h>
#include <string.h>

struct city
{
	
	char city_name[15];
	char university[50];
	char department_name[50];
	float osym_grade;
	int population;
}city1, city2, city3 = {"Gumushane","Gumushane University","Machine Engineering",297.152,65};

int main ()
{
	
	strcpy(city1.city_name, "Ankara");
	strcpy(city1.university, "Gazi University");
	strcpy(city1.department_name, "Constructional Engineering");
	city1.osym_grade = 380.745;
	city1.population = 150;
	
	printf ("%s\n", city1.city_name);
	printf ("%s\n", city1.university);
	printf ("%s\n", city1.department_name);
	printf ("%.3f\n", city1.osym_grade);
	printf ("%d\n", city1.population);
	
	printf ("\n");
	
	strcpy(city2.city_name, "Malatya");
	strcpy(city2.university, "Inonu University");
	strcpy(city2.department_name, "Computer Engineering");
	city2.osym_grade = 330.943;
	city2.population = 105;
	printf ("%s\n%s\n%s\n%.3f\n%d\n", city2.city_name, city2.university, city2.department_name, city2.osym_grade, city2.population);
	
	printf  ("\n");
	
	printf ("%s\n%s\n%s\n%.3f\n%d\n", city3.city_name, city3.university, city3.department_name, city3.osym_grade, city3.population);
}
