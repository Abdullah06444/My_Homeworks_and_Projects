// Bir ders için not hesaplama

#include <stdio.h>

int  main (void)

{ 	int exam1, exam2, exam3, make_up;
	
	float average, average2;
	
	printf ("First exam point is ");
	scanf ("%d", &exam1);
	
	printf ("Second exam point is ");
	scanf ("%d", &exam2);
	
	printf ("Final exam point is ");
	scanf ("%d", &exam3);
	
	average = ( 1/7.0 * exam1 + 2/7.0 * exam2 + 4/7.0 * exam3 );
	
if (average >= 60) {
	
	if (average > 90 && average <= 100)	{
		
		printf ("The lesson of note 4.00 and your letter grade AA.\n");
		printf ("You will be a genius to this lesson. :-)))\n");
	}
	
	else if (average > 85 && average <= 90)	{
		
		printf ("The lesson of note 3.50 and your letter grade AB.\n");
		printf ("You will be a professor to this lesson. :-))\n");
	}
	
	else if (average > 80 && average <= 85)	{
	
		printf ("The lesson of note 3.00 and your letter grade BB.\n");
		printf ("If you study this lesson, you can make better to your note. :-)\n");
	}
	
	else if (average > 75 && average <= 80)	{
		
		printf ("The lesson of note 2.50 and your letter grade BC.\n");
		printf ("If you don't study this lesson, you will be failed to this. :-!\n");
	}
	
	else if (average > 70 && average <= 75)	{
	
		printf ("The lesson of note 2.00 and your letter grade CC.\n");
		printf ("You make a mistake to this lesson. :-!!\n");
	}
	
	else if (average > 65 && average <= 70)	{
		
		printf ("The lesson of note 1.50 and your letter grade CD.\n");
		printf ("Don't you like to this lesson? :-!!!\n");
	}
	
	else if (average > 60 && average <= 65)	{
		
		printf ("The lesson of note 1.00 and your letter grade DD.\n");
		printf ("You mind I am asking what you are doing. :-(\n");
	}

	printf ("The lesson note average is %.2f.\n", average );
	printf ("You passed to this lesson.");

}

else if (average > 50 && average <= 60)	{
		
		printf ("The lesson of note 0.50 and your letter grade DF.\n");
		printf ("I think you should give to this work up. :-((\n");
		
	printf ("The lesson note average is %.2f.\n", average );
	printf ("If you want to pass to this lesson, you have to study the make up that will be final exam.\n");
	scanf ("%d", & make_up);
	
	average2 = ( 1/7.0 * exam1 + 2/7.0 * exam2 + 4/7.0 * make_up );
	
	if (average2 > 60)	{
		
		printf ("You passed to this lesson.\n");
		printf ("The lesson note average is %.2f.", average2 );
	}
	
	else {
		
		printf ("You failed to this lesson. You have to take again to this lesson next year.\n");
		printf ("The lesson note average is %.2f.", average2 );
	}
	
}

else if (average >= 0 && average <= 50)	{
		
		printf ("The lesson of note 0.00 and your letter grade FF.\n");
		printf ("I think you should be a crazy. :-(((\n");
		printf ("You failed to this lesson. You have to take again to this lesson next year.\n");
		printf ("The lesson note average is %.2f.", average );
}
		
	return 0;
}
