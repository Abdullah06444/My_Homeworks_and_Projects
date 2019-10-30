#include <iostream>
#define SIZE 200000

using namespace std;

int arr[SIZE][2];

int main() {

	int query, n, i, j, temp, day;

	cin >> query;

	if (query >= 1 && query <= 1000) {

		for (i = 0; i < query; i++) {

			cin >> n; // students



			for (j = 0; j < n;)
			{

				arr[j][1] = 0;
				cin >> arr[j++][0];
			}
			for (j = 0; j < n;) {

				day = 0;
				temp = j;
				if (arr[j][1] == 0) {
					
					do {

						j = arr[j][0] - 1;
						day++;
					} while (j != temp);
					j = temp;
					do {

						j = arr[j][0] - 1;
						arr[j][1] = day;
					} while (j != temp);

					cout << day << " ";
				}
				else
					cout << arr[j][1] << " ";
				j++;
				day++;
			}
			cout << endl;
		}
	}
	
}
