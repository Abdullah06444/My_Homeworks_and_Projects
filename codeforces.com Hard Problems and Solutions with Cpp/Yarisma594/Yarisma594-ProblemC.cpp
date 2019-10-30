#include <iostream>
#include <vector>
#define SIZE 100000

using namespace std;

//long long arr[SIZE];
//vector <vector <long long, std::allocator <long long> > > arr(SIZE/2, vector <long long, std::allocator <long long> > (SIZE));

long long function(long long i, long long j) {

	long long a;
	vector <long long> arr(SIZE);

	arr[0] = 2;
	arr[1] = 4;

	for (a = 2; a < SIZE; a++)
		arr[a] = (arr[a - 1] + arr[a - 2]) % 1000000007;

	return (arr[i - 1] + arr[j - 1] + 1000000005) % 1000000007;
}

int main() {

	long long n, m;

	cin >> n >> m;

	cout << (long long)function(n, m);

}