#include <iostream>

using namespace std;

void f(int &a, int &b)
{
	
	int x = a;
	a = b;
	b = x;
}
int g(int a, int b)
{
	
	int res = 1;
	for (int i=0; i<b; i++)
		res *= a;
	return res;
}
void h(int *a, int *b)
{
	
	int t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	
	int x = 2;
	int y = 3;
	int z = 4;
	
	f(x,y);
	cout << g(z,x) << "\n";
	cout << g(z,y) << "\n";
	
	h(&z,&x);
	cout << g(y,x) << "\n";
	cout << g(y,z) << "\n";
	
	cout << x << " " << y << " " << z << "\n";
}
