#include <iostream>
using namespace std;

class nesne{
	
	int x;
	public:
		void ata(int n){
			
			x = n;
		}
		int goster(){
			
			return x;
		}
};

int main()
{
	
	int i;
	nesne a[5];
	
	for (i=0; i<5; i++)
		a[i].ata(i);
	
	for (i=0; i<5; i++)
		cout << a[i].goster() << endl;
}
