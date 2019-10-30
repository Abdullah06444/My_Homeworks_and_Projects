#include <iostream>

using namespace std;

int a=6, b=10, c=12;

void func(int a, int& b, int c=8)
{
	
	b*=2;
	a+=3;
	c+=5;
	
	cout << "4,6 " << a << " " << b << " " << c << endl;
}

void func(int& a)
{
	
	a *= 2;
	c += ::a;
	
	cout << "2 " << a << " " << b << " " << c << endl;
}

int main()
{
	
	cout << "1 " << a << " " << b << " " << c << endl;
	func(b);
	cout << "3 " << a << " " << b << " " << c << endl;
	func(b,a);
	cout << "5 " << a << " " << b << " " << c << endl;
	func(b,c,a);
	cout << "7 " << a << " " << b << " " << c << endl;

	return 0;
}
