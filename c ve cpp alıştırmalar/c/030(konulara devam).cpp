//curvenland nüfusu kaç yýl sonra flatland nüfusunu geçer.
#include <stdio.h>
int main ()

{	float population_of_curvenland = 817;
	float population_of_flatland = 1088;
	int year =0;
	
	while (population_of_curvenland < population_of_flatland)
{	
	population_of_curvenland += .013*population_of_curvenland;
	population_of_flatland += .021*population_of_flatland;
	year++;
}
	printf ("%d", year);
	
	return 0;
}
