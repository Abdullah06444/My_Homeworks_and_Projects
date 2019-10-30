#include <iostream>

using namespace std;

void f();
int i;

int main()
{
	
	i = 3;
	cout << i << endl;
	f();
	cout << i << endl;
	return 0;
}

void f()
{
	
	char i;
	i = 'B';
	::i = 6;
	
	cout << "Yerel i " << i << endl;
	cout << "Genel i " << ::i << endl;
}
