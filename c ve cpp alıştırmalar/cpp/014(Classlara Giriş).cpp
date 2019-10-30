#include <iostream>

using namespace std;

class example{
	
	public:
		int i;
		void f()
		{
			
			cout << "i = " << i << endl;
		}
};

int main()
{
	
	example value;
	
	value.i = 5;
	value.f();
}
