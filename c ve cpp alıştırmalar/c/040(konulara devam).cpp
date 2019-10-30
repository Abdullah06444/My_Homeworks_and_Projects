#include <stdio.h>

main(){
 int i=0,a=0;
 char kelime[20]={0},d;
 do {
 printf("\nKelimeyi Giriniz ---> "); scanf("%s",&kelime);
 printf("\nGirdiginiz Kelime ---> %s\n",kelime);
 for(i=0;i<20;i++)
 if(kelime[i]>0)
 a++;
 //Bu forun amacý girilen kelimenin kac karakterli oldugunu bulmaktýr.
 printf("\nKelimenin Tersi ---> ");
 for(i=a-1;i>=0;i--)   //Eleman sayisi bilinen dizi tersten yazdýrýlýyor.
 printf("%c",kelime[i]);
 printf("\n\nTekrar Denemek Ister Misiniz ? E/H ---> "); d=getchar();
 } while ( d=='e' || d=='E' );
 getchar();
}



/* #include <stdio.h>



int main ()
{
	char a;
	scanf ("%c", a);
}




Bir cümlenin tersini basma.

1 = a , 2 = b , 3 = c , c = 1 , b = 2 , c =3 ;

(getchar () = !EOF

while

counter =1 counter++

char j
scanf ("%.1c", &j)

j= counter;




second loop





*/
