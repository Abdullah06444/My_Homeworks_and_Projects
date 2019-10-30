#include <stdio.h>

int main (void)

{
	int islem;
	float bakiye = 1453.29;
	float bakiye2;
	float tutar;
	int hesap;
	
	printf ("ISLEMLER\n1)Para cekme\n2)Para yatirma\n3)Odeme islemleri\n4)Havale islemleri\n5)Bakiye Sorgulama\n");
	printf ("Lutfen yapacaginiz islemi giriniz: ");
	scanf ("%d", &islem);
	
	switch (islem) {
		
		case 1:
		printf ("PARA CEKME\n");
		printf ("ISLEMLER\n1)Kendi hesabindan para cekme\n2)Baska hesaptan para cekme\n");
		printf ("Lutfen yapacaginiz islemi giriniz: ");
		scanf ("%d", &islem);
		
			switch (islem) {
			
			case 1:
			printf ("KENDI HESABINDAN PARA CEKME\n");
			printf ("Toplam Bakiyeniz %f\nLutfen cekeceginiz tutari giriniz\n", bakiye);
			scanf ("%f", &tutar);
			
				if (tutar > bakiye) {
					printf ("Yetersiz bakiye\n");
				}
				else {
					printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
				}
			
			break;
			
			case 2:
			printf ("BASKA HESAPTAN PARA CEKME\n");
			printf ("Lutfen para cekeceginiz hesabi giriniz\n");
			scanf ("%d", &hesap);
			
				if (hesap > 10000000 && hesap < 100000000) {
					
					if (hesap > 25000000 && hesap < 62500000) {
						printf ("Bu hesap kullanilmamaktadir.\n");
					}
					else {
						printf ("Lutfen hesabi kullanan kisinin kimligini giriniz.\n");
						scanf ("%d", &hesap);
						
						if (hesap > 10000000000 && hesap < 100000000000) {
						printf ("Lutfen Bekleyiniz\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n");
						
							if (hesap /= 2.0) {
								printf ("Hesap numarasini dogru girdiniz.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n");
								printf ("Toplam bakiye %.2f\nLutfen cekeceginiz tutari giriniz\n", bakiye2 = hesap / 10000000 );
								scanf ("%f", &tutar);
								
								if (tutar > bakiye2) {
									printf ("Yetersiz bakiye\n");
								}
								else {
									printf ("Yeni bakiye %.2f", bakiye2 -= tutar);
								}
								
							}	
							else {
								printf ("Kimlik bilgisini yanlis girdiniz.\n");
							}
					
						}
						else {
							printf ("Kimlik bilgisini yanlis girdiniz.\n");
						}
					}
					
				}
				else {
					printf ("Hesap numarasini yanlis girdiniz.\n");
				}
				
				
			break;

			}
		
		break;
		
		case 2:
		printf ("PARA YATIRMA\n");
		printf ("ISLEMLER\n1)Kendi hesabina para yatirma\n2)Baska hesaba para yatirma\n");
		printf ("Lutfen yapacaginiz islemi giriniz: ");
		scanf ("%d", &islem);
		
		switch (islem) {
			
			case 1:
			printf ("KENDI HESABINA PARA YATIRMA\n");
			printf ("Toplam Bakiyeniz %f\nLutfen yatiracaginiz tutari giriniz\n", bakiye);
			scanf ("%f", &tutar);
			
				if (tutar > 25000) {
					printf ("Tek seferde bu kadar para yatiramazsiniz.\n");
				}
				else {
					printf ("Yeni bakiyeniz: %.2f", bakiye += (float) tutar);
				}
			
			break;
			
			case 2:
			printf ("BASKA HESABA PARA YATIRMA\n");
			printf ("Lutfen para yatiracaginiz hesabi giriniz\n");
			scanf ("%d", &hesap);
			
				if (hesap > 10000000 && hesap < 100000000) {
					if (hesap > 25000000 && hesap < 62500000) {
						printf ("Bu hesap kullanilmamaktadir.\n");
					}
					else {
						printf ("Lutfen hesabi kullanan kisinin kimligini giriniz.\n");
						scanf ("%d", &hesap);
						if (hesap > 10000000000 && hesap < 100000000000) {
						printf ("Lutfen Bekleyiniz\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n");
							if (hesap /= 2.0) {
								printf ("Hesap numarasini dogru girdiniz.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n");
								printf ("Toplam bakiye %.2f\nLutfen yatiracaginiz tutari giriniz\n", bakiye2 = hesap / 10000000 );
								scanf ("%f", &tutar);
								
								if (tutar > 25000) {
									printf ("Tek seferde bu kadar para yatiramazsiniz.\n");
								}
								else {
									printf ("Yeni bakiye %.2f", bakiye2 += tutar);
								}
							}
							else {
								printf ("Hesap numarasini yanlis girdiniz.\n");
							}
						
						}
						
					}
					
				}
			
				else {
					printf ("Hesap numarasini yanlis girdiniz.\n");
				}
			
			break;
			
		}
		
		break;
		
		case 3:
		printf ("ODEME ISLEMLERI\n");
		printf ("ISLEMLER\n1)Vergi tahsilati\n2)Fatura odemeleri\n3)Egitim odemeleri\n4)Diger odemeler\n");
		printf ("Lutfen yapacaginiz islemi giriniz: ");
		scanf ("%d", &islem);
		
		switch (islem) {	
			case 1:
			printf ("VERGI TAHSILATI\n");
			printf ("Lutfen kimliginizi giriniz.\n");
			scanf ("%d", &hesap);
			
			printf ("ISLEMLER\n1)Tapu-Senet odemeleri\n2)Tasitli arac vergisi\n3)Emlak vergisi\n4)Ticari kazanc vergisi\n");
			printf ("Lutfen yapacaginiz islemi giriniz: ");
			scanf ("%d", &islem);
			
				switch (islem) {
					case 1:
					printf ("TAPU-SENET ODEMELERI\nucret = 5000 tl");
					tutar = 5000;
					printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
					
					break;
					
					case 2:
					printf ("TASITLI ARAC VERGISI\nucret = 1000 tl");
					tutar = 1000;
					printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
					
					break;
					
					case 3:
					printf ("EMLAK VERGISI\nucret = 5000 tl");
					tutar = 5000;
					printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
					
					break;
					
					case 4:
					printf ("TICARI KAZANC VERGISI\nucret = 799.99 tl");
					tutar = 799.99;
					printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
					
					break;
				}
			
			break;
			
			case 2:
			printf ("FATURA ODEMELERI\n");
			printf ("Lutfen kimliginizi giriniz.\n");
			scanf ("%d", &hesap);
			
			printf ("ISLEMLER\n1)Elektrik fatura\n2)Su fatura\n3)Dogalgaz fatura\n4)Kablosuz internet faturasi\n");
			printf ("Lutfen yapacagýnýz islemi giriniz: ");
			scanf ("%d", &islem);
			
				switch (islem) {
					case 1:
					printf ("ELEKTRIK FATURA\nucret = 89.99 tl");
					tutar = 89.99;
					printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);

					break;
					
					case 2:
					printf ("SU FATURA\nucret = 98.49 tl");
					tutar = 98.49;
					printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
			
					break;
					
					case 3:
					printf ("DOGALGAZ FATURA\nucret = 239.39 tl");
					tutar = 239.39;
					printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
					
					break;
					
					case 4:
					printf ("KABLOSUZ INTERNET FATURASI\nucret = 59.99 tl");
					tutar = 59.99;
					printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
					
					break;
				}
					
			case 3:
			printf ("EGITIM ODEMELERI\n");
			printf ("Lutfen kimliginizi giriniz.\n");
			scanf ("%d", &hesap);
			
			printf ("ISLEMLER\n1)Sinav odemeleri\n2)Kredi borc odemeleri\n3)Yurt odemeleri\n4)Universite harc-katki payi odemeleri\n");
			printf ("Lutfen yapacagýnýz islemi giriniz: ");
			scanf ("%d", &islem);
			
				switch (islem)	{
					case 1:
					printf ("SINAV ODEMELERI\n");
					printf ("ISLEMLER\n1)OSYM sinavi\n2)Ehliyet sinavi\n3)Yabanci dil sinavi\n4)Memur alimi sinavi\n");
					printf ("Lutfen yapacagýnýz islemi giriniz: ");
					scanf ("%d", &islem);
					
					switch (islem) {
						case 1:
						printf ("OSYM SINAVI\nucret = 75 tl");
						tutar = 75;
						printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
						
						break;
						
						case 2:
						printf ("EHLIYET SINAVI\nucret = 50 tl");
						tutar = 50;
						printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
						
						break;
						
						case 3:
						printf ("YABANCI DIL SINAVI\nucret = 225 tl");
						tutar = 225;
						printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
						
						break;
						
						case 4:
						printf ("MEMUR ALIMI SINAVI\nucret = 60 tl");
						tutar = 60;
						printf ("Yeni bakiyeniz: %.2f", bakiye -= (float) tutar);
						
						break;
					}
					
					case 2:
					printf ("KREDI BORC ODEMELERI\n");
					
					
					
				}
			
			break;
			
			case 4:
			printf ("DIGER ODEMELER\n");
			printf ("Lutfen kimliginizi giriniz.\n");
			scanf ("%d", &hesap);
			
			break;
		}
		
		break;
		
		case 4:
		printf ("HAVALE ISLEMLERI\n");
		printf ("");
		scanf ("", &islem);
		
		break;
		
		case 5:
		printf ("BAKIYE SORGULAMA\n");
		printf ("");
		scanf ("", &islem);
		
		break;
	}
	
	return 0;
}
