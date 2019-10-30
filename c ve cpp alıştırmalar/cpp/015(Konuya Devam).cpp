#include <iostream>

using namespace std;

class example{
	
	public:				// Genel olarak tanimlanan ifadeler ise int main() fonksiyonumuzun icerisinde rahatlikla cagrilabilir.
		int i;
		void f();
	private:			// Ozel olarak tanimlanan ifadeler yalniz classin icerisinde cagrilabilir.
		float j;
		double k;
};

void example::f()
{
	j = 7.4;
	k = 9.487487487487;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "k = " << k << endl;
}

int main()
{
	
	example value;
	
	value.i = 5;
	value.f();
}
