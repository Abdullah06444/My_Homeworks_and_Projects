#include <stdio.h>

struct final_exam
{
	
	char lesson_name[20];
	char class_number[15];
};

struct exam_date
{
	
	int day;
	int month;
	int year;
};

void function(struct final_exam x, struct exam_date y)
{
	int i=0;
	for (; i < 4; i++)
	printf ("%s sinifinin %s dersinin final tarihi %d.%d.%ddir.\n", x.class_number, x.lesson_name, y.day, y.month, y.year);	
}

int main ()
{
	
	struct final_exam f = {
		
		{"C programming language", "first class"},
		{"Calculus", "first class"},
		{"Algorithm", "second class"},
		{"Java", "third class"}
	};
	
	struct exam_date g = {
		
		{26, 12, 2016},
		{03, 01, 2017},
		{30, 12, 2016},
		{07, 02, 2017}
	};
	
	function(f , g);
}
