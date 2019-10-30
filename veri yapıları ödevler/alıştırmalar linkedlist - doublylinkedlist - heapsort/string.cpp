#include <stdio.h>
#include <string>

int main()
{
int br_el[6],i;
std::string qr_naziv[6];

    qr_naziv[0]="Bath tub";

    qr_naziv[1]="Sink";

    qr_naziv[2]="Washing machine";

    qr_naziv[3]="Toilet";

    qr_naziv[4]="Kitchen sink";

    qr_naziv[5]="Dish washer";


for(i=0;i<6;i++)
    {

        printf("Input the number for %s\n", &qr_naziv[2]);//here lies the problem

	//	scanf("%d",&br_el[i]);
	}
}

/*This program is much longer, so I shortened it.. 
The thing is, I will enter numbers for array br_el[6], 
and I want it to show me for what object I am entering 
the number! So when I try to compile it gives me the 
error:"[Error] cannot pass objects of non-trivially-copyable 
type 'std::string {aka class std::basic_string}' through '...'" 
I tried to declare string qr_naziv[6]; but the string didn't even 
bold so it didn't work, so I googled and found out another way (std::string qr_naziv[6];).*/

