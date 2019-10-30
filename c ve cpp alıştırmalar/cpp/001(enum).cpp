#include <iostream>

using namespace std;

enum months{January, February, March, April=6, May, June, July, August, September, October, November=17, December};

int main ()
{
	
	int i=0;
	months damn = January;
	while (i<20){
		
		if (damn == July)
			cout << "It doesn't exist this value." << endl;
		cout << "damn month is " << damn << endl;
		i++;
	}
}

