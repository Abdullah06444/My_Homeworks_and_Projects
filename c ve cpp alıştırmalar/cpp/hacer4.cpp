#include <iostream>

using namespace std;

class X
{
	
	static int count;
	public:
		X()
		{	count++;	}
		~X()
		{	count--;	}
		static void printCount()
		{
			
			cout << count << "\n";
		}
};

int  X::count = 0;

void f()
{
	
	X fa[10];
	for (int i=0; i<10; i++)
		fa[i] = X();
	X::printCount();
}

void g()
{
	
	X a;
	{
		
		X c;
		X d;
		X::printCount();
	}
	X::printCount();
	
	f();
	X c;
	X::printCount();
}

int main()
{
	g();
	X::printCount();
}
