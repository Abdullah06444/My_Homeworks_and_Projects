#include <iostream>
using namespace std;

class Bir{
	
	public:
		static int sayi;	// Statik üyenin tanimi
		Bir()				// Yapici fonksiyon cagrildiginda sayi degeri artirilir
		{
			
			sayi++;
		}
};

int Bir::sayi;			// Static uyenin ilk deger atamasi
int main()
{
	
	Bir n1, n2, n3, n4;
	cout << "Nesnelerin sayisi: " << n1.sayi << endl;
	return 0;
}
