#include <iostream>
#define SIZE 200

using namespace std;

int main() {

	int query, n, arr[SIZE], i, j, temp, day;

	cin >> query;

	if (query >= 1 && query <= 200) {

		for (i = 0; i < query; i++) {

			cin >> n; // students

			for (j = 0; j < n;)
				cin >> arr[j++];

			for (j = 0; j < n;) {

				day = 0;
				temp = j;
				//root = NULL;
				do {


					//root = insert(root, arr[j]);
					j = arr[j]-1;
					day++;
				} while (j != temp);
				cout << day << " ";

				j++;
				day++;
			}
			cout << endl;
		}
	}
}