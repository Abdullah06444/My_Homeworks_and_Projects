#include <iostream>
#define SIZE 1000

using namespace std;

// Firstly, no visit the any room of the any floor
int arr[2][SIZE], counter;	//1st & 2nd floor

void visit(int n, int i, int j, char stairs[], int c) {

	// It starts any rooms of the first floor. It does not matter started which floor
	arr[i][j] = 1, c++; // Visited

	if (j - 1 >= 0 && arr[i][j - 1] == 0)
		visit(n, i, j - 1, stairs, c);
	if (j + 1 < n && arr[i][j + 1] == 0)
		visit(n, i, j + 1, stairs, c);
	if (stairs[j] == '1' && i == 0 && arr[1][j] == 0)
		visit(n, 1, j, stairs, c);
	if (stairs[j] == '1' && i == 1 && arr[0][j] == 0)
		visit(n, 0, j, stairs, c);

	if (c > counter)
		counter = c;
	c = 0;
}

int main()
{

	int query, i, j, roomsNumber;
	char stair[SIZE];
	cin >> query;	// You determine how many queries will be

	if (query > 0 && query < 101)
	{

		for (i = 0; i < query; i++)
		{

			cin >> roomsNumber >> stair;
			visit(roomsNumber, 0, 0, stair, 0);
			for (j = 0; j < roomsNumber; j++)
				arr[0][j] = arr[1][j] = 0;
			visit(roomsNumber, 0, roomsNumber-1, stair, 0);
			for (j = 0; j < roomsNumber; j++)
				arr[0][j] = arr[1][j] = 0;
			if (i == -1)
				cout << "query " << i << endl;
			cout << counter << endl;
			counter = 0;
		}
	}
}
