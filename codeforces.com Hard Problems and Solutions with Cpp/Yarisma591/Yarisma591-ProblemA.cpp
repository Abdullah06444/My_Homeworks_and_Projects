#include <iostream>

using namespace std;

int main()
{

	// You determine how many queries will be
	int query, i, n;
	cin >> query;

	// a + b = c
	if (query > 0 && query < 101)
	{

		// a,b,c = 0;	// It has to be at least one match
		for (i = 0; i < query; i++)
		{

			// You have n matches. n is equal to
			cin >> n;

			// The minimum number of matches which you have to buy
			n -= 4;
			while (n > 0)
				n -= 2;
			cout << -n << endl;
		}
	}
}
