#include <iostream>
using namespace std;

class Dene{
	
	int no;
	public:
		Dene(int n=0):no(n){}	//Yapici fonksiyon tanimi
		friend void yaz(Dene);	//Arkadaþ fonksiyon prototipi
};
void yaz(Dene x)
{
	
	cout << "numara = " << x.no << endl;
}
int main()
{
	
	Dene test1(7),test2(12);
	yaz(test1);	//Arkadaþ fonksiyonun cagrimi
	yaz(test2);
	return 0;
}
