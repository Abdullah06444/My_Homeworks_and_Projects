#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

long double n, p, w, d, x, y, z;

int main()
{

	bool flag = true;
	cin >> n >> p >> w >> d;

	if (n > 0 && p >= 0 && d > 0 && w > 1 && w > d) {

		long double diskriminant = w - d;

		for (z = 0; z <= n;)
		{

			x = (p - d * (n - z)) / diskriminant;
			y = (w * (n - z) - p) / diskriminant;

			if (z == diskriminant)
				break;

			if (std::fmod((double)(p - d * (n - z)) / diskriminant, 1) != 0 || std::fmod((double)(w * (n - z) - p) / diskriminant, 1) != 0)
				z++;
			else if (x >= 0 && y >= 0) {

				cout << setprecision(18) << x << " " << setprecision(18) << y << setprecision(18) << " " << setprecision(18) << z << endl;
				cout.unsetf(ios::fixed);
				z += diskriminant;
				flag = false;
				break;
			}
			else
				z += diskriminant;
		}
		if (flag)
			cout << "-1" << endl;
	}
}