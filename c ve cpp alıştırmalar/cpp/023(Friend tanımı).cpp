#include <iostream>
using namespace std;

class deneme{
	
	int n, d;
	public:
		deneme(int i, int j){
			
			n=i;
			d=j;
		}
		friend int fonk(deneme a);
};

int fonk(deneme a){
	
	if(!(a.n%a.d))
		return 1;
	else
		return 0;
}

int main()
{
	
	deneme nesne1(8,4);
	deneme nesne2(7,3);
	
	if(fonk(nesne1))
		cout << "Tam katidir." << endl;
	else
		cout << "Tam kati degildir." << endl;
		
	if(fonk(nesne2))
		cout << "Tam katidir." << endl;
	else
		cout << "Tam kati degildir." << endl;

}
