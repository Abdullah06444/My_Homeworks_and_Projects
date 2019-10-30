#include <iostream>

using namespace std;

enum days{sun=1, mon, tue, wed, thu, fri, sat};

days operator++(days& x)
{
	
	return x = (tue == x) ? fri : days(x+2);
}

int main()
{
	
	days birthday = tue;
	++birthday;
	cout << birthday << endl;
}
