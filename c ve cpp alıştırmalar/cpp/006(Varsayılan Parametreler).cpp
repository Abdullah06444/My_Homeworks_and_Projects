#include <iostream>

using namespace std;

int func(int x = 5, int y = 15)
{
	
	cout << "x = " << x << " y = " << y << endl;
}

int main ()
{
	
	func(3,4);
	func(3);
	func();
}
