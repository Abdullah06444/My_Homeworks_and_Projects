// Program çalışmıyor. Basmıyor.

#include <stdio.h>

int main (void)

{
int age1, age2, age3, score1, score2, score3;
float total;

scanf ("%d %d %d %d %d %d", &age1, &score1, &age2, &score2, &age3, &score3);	

	if (age1 >= 0 && age1 <= 19) {
	age1 = 0.47;
	
		if (age2 >= 0 && age2 <= 19) {
		age2 = 0.47;
	
			if (age3 >= 0 && age3 <= 19) {
			age3 = 0.47;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
	
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
			
			}

			else if (age3 >= 20 && age3 <= 59) {
			age3 = 0.35;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
	
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
	
			}

			else if (age3 >= 60 && age3 <= 100) {
			age3 = 0.18;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
			
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}

			}
	
		}

		else if (age2 >= 20 && age2 <= 59) {
		age2 = 0.35;

			if (age3 >= 0 && age3 <= 19) {
			age3 = 0.47;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
	
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}		

			}

			else if (age3 >= 20 && age3 <= 59) {
			age3 = 0.35;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
	
				if (total < 50) {
				printf ("U");
				}
	
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
			}

			else if (age3 >= 60 && age3 <= 100) {
			age3 = 0.18;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
			
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
				
			}

		}

		else if (age2 >= 60 && age2 <= 100) {
		age2 = 0.18;

			if (age3 >= 0 && age3 <= 19) {
			age3 = 0.47;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
				
				else if (total > 80) {
				printf ("S");
				}
			
			}

			else if (age3 >= 20 && age3 <= 59) {
			age3 = 0.35;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
	
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}

			}

			else if (age3 >= 60 && age3 <= 100) {
			age3 = 0.18;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
			
				else if (total < 80 && total > 50) {
				printf ("P");
				}
				
				else if (total > 80) {
				printf ("S");
				}
	
			}

		}

	}







	
	
	
	else if (age1 >= 20 && age1 <= 59) {
	age1 = 0.35;
	
		if (age2 >= 0 && age2 <= 19) {
		age2 = 0.47;
	
			if (age3 >= 0 && age3 <= 19) {
			age3 = 0.47;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
	
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
			
			}

			else if (age3 >= 20 && age3 <= 59) {
			age3 = 0.35;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
	
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
	
			}

			else if (age3 >= 60 && age3 <= 100) {
			age3 = 0.18;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
			
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}

			}
	
		}

		else if (age2 >= 20 && age2 <= 59) {
		age2 = 0.35;

			if (age3 >= 0 && age3 <= 19) {
			age3 = 0.47;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
	
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}		

			}

			else if (age3 >= 20 && age3 <= 59) {
			age3 = 0.35;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
	
				if (total < 50) {
				printf ("U");
				}
	
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
			}

			else if (age3 >= 60 && age3 <= 100) {
			age3 = 0.18;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
			
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
				
			}

		}

		else if (age2 >= 60 && age2 <= 100) {
		age2 = 0.18;

			if (age3 >= 0 && age3 <= 19) {
			age3 = 0.47;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
				
				else if (total > 80) {
				printf ("S");
				}
			
			}

			else if (age3 >= 20 && age3 <= 59) {
			age3 = 0.35;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
	
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}

			}

			else if (age3 >= 60 && age3 <= 100) {
			age3 = 0.18;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
			
				else if (total < 80 && total > 50) {
				printf ("P");
				}
				
				else if (total > 80) {
				printf ("S");
				}
	
			}

		}

	}





	
	
	
	
	
	else if (age1 >= 60 && age1 <= 100) {
	age1 = 0.18;
	
		if (age2 >= 0 && age2 <= 19) {
		age2 = 0.47;
	
			if (age3 >= 0 && age3 <=19) {
			age3 = 0.47;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
	
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
			
			}

			else if (age3 >= 20 && age3 <= 59) {
			age3 = 0.35;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
	
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
	
			}

			else if (age3 >= 60 && age3 <= 100) {
			age3 = 0.18;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
			
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}

			}
	
		}

		else if (age2 >= 20 && age2 <= 59) {
		age2 = 0.35;

			if (age3 >= 0 && age3 <=19) {
			age3 = 0.47;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
	
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}		

			}

			else if (age3 >= 20 && age3 <= 59) {
			age3 = 0.35;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
	
				if (total < 50) {
				printf ("U");
				}
	
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
			}

			else if (age3 >= 60 && age3 <= 100) {
			age3 = 0.18;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
			
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}
				
			}

		}

		else if (age2 >= 60 && age2 <= 100) {
		age2 = 0.18;

			if (age3 >= 0 && age3 <= 19) {
			age3 = 0.47;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
		
				else if (total < 80 && total > 50) {
				printf ("P");
				}
				
				else if (total > 80) {
				printf ("S")
				}
			
			}

			else if (age3 >= 20 && age3 <= 59) {
			age3 = 0.35;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
	
				else if (total < 80 && total > 50) {
				printf ("P");
				}
		
				else if (total > 80) {
				printf ("S");
				}

			}

			else if (age3 >= 60 && age3 <= 100) {
			age3 = 0.18;
			total = (float) age1 * score1 + age2 * score2 + age3 * score3;
		
				if (total < 50) {
				printf ("U");
				}
			
				else if (total < 80 && total > 50) {
				printf ("P");
				}
				
				else if (total > 80) {
				printf ("S");
				}
	
			}

		}

	}



return 0;
}
