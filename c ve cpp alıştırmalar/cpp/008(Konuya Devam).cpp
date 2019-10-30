#include <iostream>

using namespace std;

int calculate(int a, int b, int c);
double calculate(double a, double b, double c);

int main ()
{
	
	cout << "Uc degerin toplami : " << calculate(2,3,5) << endl;
	cout << "Uc degerin toplami : " << calculate(2.4,4.7,5.9) << endl;
}

int calculate(int a, int b, int c)
{
	
	return (a+b+c);
}

double calculate(double a, double b, double c)
{
	
	return (a+b+c);
}
