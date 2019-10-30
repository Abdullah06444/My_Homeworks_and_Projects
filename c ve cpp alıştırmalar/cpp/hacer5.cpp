#include <iostream>

using namespace std;

class A
{
	
	string name;
	public:
		A(string s= " ")
		{
			
			name = s;
			cout << "constructor of " << name << "\n";
		}
		A(const A& a)
		{
			
			name = a.name;
			cout << "copy constructor of A\n";
		}
		A& operator=(const A& a)
		{
			
			name = a.name;
			cout << "copy assignment of A\n";
			return *this;
		}
};

int main()
{
	
	A x("x");
	A y("y");
	A z=x;
	y=z;
	x=y;
}
