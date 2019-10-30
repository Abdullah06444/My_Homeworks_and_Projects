#include <iostream>

using namespace std;

class intdizi{
	
	private:
		
		int *p;		//	dinamik dizinin baslangic adresini tutan dizi
		int ES;		//	dizide bulunan sayi adedi
		int TS;		//	dizinin alacagi maximum eleman sayisi
		
	public:
		
		intdizi(){
			
			p = new int[10];
			TS = 10;
			ES = 0;
		}
		int dizi(int boyut){
			
			p = new int[boyut];
			TS = boyut;
			ES = 0;
		}
		void ekle(int a){
			
			if(TS == ES)
				genislet(TS);
			p[ES] = a;
			ES++;
		}
		int getir(int i){
			
			if(i=0)
				return 0;
			if(i>=ES)
				return 0;
			return p[i];
		}
		void genislet(int boyut){
			
			int *yenialan = new int[TS+boyut];
			
			memcpy(yenialan,p,sizeof(int)*ES);
			delete [] p;
			p = yenialan;
		}
};
