#include <iostream>
#include <cstdlib>
#include <cstring>
#define size 100

using namespace std;

int function(char* x, char *y)
{
	
	int i, j;
	for (i = 0; i < strlen(x); i++)
		for (j = 0; j < strlen(y); j++)
			if (x[i] == y[j])
				return 1;
	return 0;
}

int main()
{

	int query, i, result;
	cin >> query;

	if (query > 0 && query < 101)
	{

		for (i = 0; i < query; i++)
		{

			char* s, * t;
			s = new char[size];
			t = new char[size];
			cin >> s >> t;

			result = 0;
			if(strlen(s) == strlen(t))
				result = function(s, t);

			if (result == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;

			delete s;
			delete t;
		}
	}
}
