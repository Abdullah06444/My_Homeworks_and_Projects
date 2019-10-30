#include <iostream>

using namespace std;

int *f(int *a, int *b, int size)
{
	
	int c[6];
	
	for (int i=0; i<size; i++)
		c[i] = a[i] + b[i];
		
	return c;
}
void print(int *a, int size)
{
	
	for (int i=0; i<size; i++)
		cout << a[i] << " ";
	cout << "\n";
}
int main()
{
	
	int *z;
	int x[] = {1, 2, 3, 4, 5, 6};
	int y[] = {2, 4, 6, 8, 10, 12};
	
	z = f(x,y,6);
	
	print(x,6);
	print(y,6);
	print(z,6);
}
