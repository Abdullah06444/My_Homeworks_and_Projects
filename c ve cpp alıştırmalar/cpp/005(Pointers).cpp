#include <iostream>

using namespace std;

void sum(int a, int b);
int main ()
{
	
	int *a;
	
	char d[] = "C++";
	{
		
		int b = 25;
		a = &b;
		
		sum(12,15);
	}
	
	short c[] = {12, 55};
	*a = 123;
}

void sum(int a, int b)
{
	
	short c[] = {12, 55};
	char d[] = "C++";
	
	cout << a + b;
}
