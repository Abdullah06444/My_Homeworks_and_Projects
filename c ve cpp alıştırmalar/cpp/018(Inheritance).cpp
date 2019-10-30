#include <iostream>
#define PI 3.14

using namespace std;

class sekil{
	
	public:
		int alan;
		void alanyaz(){
			
			cout << "Sekil turu "<< alan;
			cout << " cm2 alana sahiptir." << endl;
		}
		void f(int alan){	//	Bu fonksiyonu yapmamdaki amaç "this" operatörünün nasýl kullanýldýðýný göstermek.
			
			alan = 100;
			this->alan = alan;	//	Bu operatör aslýnda class'in parametrelerinden fonksiyonun icerisinde de
			//	ayni tanimlanmis ifade ile karistirilmadan ikisini de kullanmayi amaclar.
			cout << "Buradaki cevap yanlistir " << alan << " :-)" << endl;
		}
};

class ucgen:public sekil{		//	Kalitim sinifi...
	
	public:
		int yukseklik;
		int taban;

};
class dortgen:public sekil{		//	Kalitim sinifi...
	
	public:
		int en;
		int boy;
};
class daire:public sekil{		//	Kalitim sinifi...
	 
	public:
		int yaricap;
};

int main(){
	
	dortgen d1;
	d1.en = 15;
	d1.boy = 20;
	d1.alan=d1.en*d1.boy;
	d1.alanyaz();
	d1.f(6);
	
	daire da1;
	da1.yaricap = 7;
	da1.alan=PI*da1.yaricap*da1.yaricap;
	da1.alanyaz();
	da1.f(7);
	
	dortgen d2;
	d2.en = 12;
	d2.boy = 27;
	d2.alan=d2.en*d2.boy;
	d2.alanyaz();
	d2.f(8);
	
	ucgen u1;
	u1.yukseklik = 11;
	u1.taban = 8;
	u1.alan=u1.yukseklik*u1.taban*0.5;
	u1.alanyaz();
	u1.f(9);
}
