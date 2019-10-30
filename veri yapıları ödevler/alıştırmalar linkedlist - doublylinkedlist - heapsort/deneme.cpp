#include <iostream>
using namespace std;

int main()
{
	
	int arr[3][3] = {4,5,6,9,-5,-3,0,-1,0};
	
	cout << arr[0][0];
	cout << arr[1][0];
	cout << arr[1][1] << endl << endl << endl;
	
	
	
	char temp[4][4] = {' ',' ',' ','*','*',' ','*',' ',' ','*','*','*',' ',' ',' ','*'};
	
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			
			cout << temp[i][j];
		}
		cout << endl;
	}
}
