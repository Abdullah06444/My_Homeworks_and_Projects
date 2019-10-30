#include <iostream>
#include <string>

using namespace std;

class Tarih
{
	
	int gun, ay, yil;
	public:
		Tarih(int g,int a,int y):gun(g),ay(a),yil(y){}//Yapici Fonksiyonun Tanimi
		void yaz();
};
void Tarih::yaz()
{
	
	cout << gun << "/" << ay << "/" << yil << endl;
}
class Birey
{
	
	string isim;
	Tarih dogumGunu;					//Burada dogumGunu Tarih class�n�n bir eleman� olarak tan�mlanm��.
	public:
		Birey(string, int, int, int);	//Yapici fonksiyon prototipi
		void yaz();
};
void Birey::yaz()
{
	
	cout << isim << " ";
	dogumGunu.yaz();
}
Birey::Birey(string s,int g,int a,int y):dogumGunu(g,a,y)	//Yapici fonksiyon
{	//Ayr�ca yukar�daki dogumGunu(g,a,y) parametresi e�itli�i dogumGunu ifadesine (g,a,y) ifadesini atar.
	
	isim=s;
}
int main()
{
	
	Birey insan("Tolga",17,1,1997);	//Nesne tanimi
	insan.yaz();
	return 0;
}
