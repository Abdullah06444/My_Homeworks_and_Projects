#include <stdio.h>

struct book
{
	
	char name[50];
	char author[20];
	float price;
};

int main()
{
	
	struct book rar[6] {
	
	{"Falaka", "Omer Seyfettin", 14.90},
	{"Osmancik", "Tarik Bugra", 23.49},
	{"Fareler ve Insanlar" ,"John Steinbeck" , 26.00},
	{"Dokuzuncu Hariciye Kogusu", "Peyami Safa", 41.89},
	{"Yaprak Dokumu", "Resat Nuri Guntekin", 32.50},
	{"Imamin Manken Kizi", "Emine Senlikoglu", 19.90}
	
	};
	
	int i=0;
	struct book *ptr;
	ptr = rar; // ptr = &rar[0];
	
	for (; i < 6; i++)
	{
		
		printf ("%s yazarin %s adli eserinin fiyati %.2f\n", (*ptr).author, (*ptr).name, ptr->price);
		ptr++;
	}
}
