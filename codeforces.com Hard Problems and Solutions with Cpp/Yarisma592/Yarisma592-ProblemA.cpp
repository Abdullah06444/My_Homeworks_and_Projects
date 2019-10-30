#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{

	int query, i, a, b, c, d, k;
	int x_, y_, x2, y2;
	double x, y;
	srand(time(0));
	// You determine how many queries will be
	cin >> query;

	// x + y <= k
	if (query > 0 && query < 101)
	{

		for (i = 0; i < query; i++)
		{

			cin >> a >> b >> c >> d >> k;
			if (a < 1 || a>100 || b < 1 || b>100 || c < 1 || c>100 || d < 1 || d>100 || k < 1 || k>100)
				break;

			x = (double) a / c; // at least
			y = (double) b / d; // at least
			x_ = ceil(x);
			y_ = ceil(y);

			if (x_ + y_ > k)
				cout << "-1" << endl;
			else
			{
				do
				{
					x2 = rand() % (k - x_ + 1) + x_;
					y2 = rand() % (k - y_ + 1) + y_;
				} while (x2 + y2 > k);
				cout << x2 << " " << y2 << endl;
			}
		}
	}

	return 0;
}