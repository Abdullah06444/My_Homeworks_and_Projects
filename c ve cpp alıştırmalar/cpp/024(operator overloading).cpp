#include <iostream>

using namespace std;

class arit{
	
	public:
		int x, y;
		arit(){
			
			x=0;
			y=0;
		}
		arit(int,int);			//	burda tanimladigimiz degerleri classin terimleri ile eslestirdik.
		arit operator+(arit);	//	+ ifadesine asiri yukleme yaptik.
		arit operator-(arit);
};
		
arit::arit(int a, int b){
			
	x=a;
	y=b;
}
arit arit::operator+(arit koord){
			
	arit gecici;
			
	gecici.x = x + koord.x;
	gecici.y = y + koord.y;
	return gecici;
}
arit arit::operator-(arit koord){
			
	arit gecici;
			
	gecici.x = x - koord.x;
	gecici.y = y - koord.y;
	return gecici;
}

int main()
{
	
	arit a(19,23);
	arit b(5,4);
	arit d(4,21);
	arit c;		// toplam icin gerekli olan terim.
	
	c = a+b+d;
	// 3 nesneyi topladýk.
	// + iþleci operator+ cagirdik.
	cout << "1. sayi: " << c.x << endl;
	cout << "2. sayi: " << c.y << endl;
	
	c = a - b;
	// 2 nesneyi topladýk.
	// - iþleci operator+ cagirdik.

	cout << "1. sayi: " << c.x << endl;
	cout << "2. sayi: " << c.y << endl;

}
