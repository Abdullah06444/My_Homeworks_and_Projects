#include <iostream>
#include <string>

using namespace std;

class X
{
	
	string name;
	public:
		X(string s = "")
		{
			
			name = s;
			cout << "constructor of " << name << "\n";
		}
		~X()
		{
			
			cout << "destructor of " << name << "\n";
		}
};

void f()
{
	
	X fa("fa");
}

int main()
{
	
	X a("a");
	{
		
		X c("c");
		X d("d");
	}
	f();
	X c("c");
}
