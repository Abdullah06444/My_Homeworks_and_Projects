#include <iostream>
#include <iomanip>
#include <cmath>
#define SIZE 10000

using namespace std;

int function(int a, int b) {

	double x, y;

	//x - y + a = -x - y + b;
	x = (b - a) / 2.0;
	y = (b - x) / 1.0;

	//cout << "x:" << setprecision(10) << x << " y:" << setprecision(10) << y << endl;
	if (std::fmod(x, 1) == 0 && std::fmod(y, 1) == 0)
		return 1;
	return 0;
}

int main()
{

	int query, i, j, k, n, m, a[SIZE], b[SIZE], counter;
	cin >> query;	// You determine how many queries will be

	if (query > 0 && query < 1001)
	{

		for (k = 0; k < query; k++)
		{

			counter = 0;
			cin >> n;
			for (i = 0; i < n; i++)
				cin >> a[i];

			cin >> m;
			for (i = 0; i < m; i++)
				cin >> b[i];
			
			for (i = 0; i < n; i++) {

				for (j = 0; j < m; j++) {

					counter += function(a[i],b[j]);
				}
			}
			cout << counter << endl;
		}
	}
	return 0;
}