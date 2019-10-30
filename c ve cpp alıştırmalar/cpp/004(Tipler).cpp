#include <iostream>

using namespace std;

int c; //deger atamazsan eger global oldugu icin 0 degerini alır.
const int d = 5;
int main()
{
	
	cout << c << endl;
	cout << d << endl;
	int a=2147483647;
	
	cout << a << endl;
	if(1)
	{
		
		cout << a << endl;
		float a=7.48;
		cout << a << endl;
		if (1)
		{
			
			cout << a << endl;
			double a=4.49875987987;
			cout << a << endl;
			if (1)
			{
				
				unsigned int a = 4294967295;
				cout << a << endl;
				unsigned int b = 4294967296; // Takim araligini astigi için basa dondu.
				cout << b << endl;
			}
		}
		cout << a << endl;
	}
	cout << a << endl;
}
