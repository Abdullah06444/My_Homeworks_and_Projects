#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	
	int number;
	struct node *next;
};

node *function(node *constant, int sayi)
{
	
	if(constant == NULL){	// link list bos ise
		
		constant = (node*)malloc(sizeof(node));
		constant->next = NULL;
		constant->number = sayi;
		return constant;
	}
	
	if(constant->number > sayi){	// ilk elemandan kucuk durumu
		// root degisiyor	
		node *temp= (node*)malloc(sizeof(node));
		temp->next = NULL;
		temp->number = sayi;
		temp->next = constant;
		return temp;
	}
	else{
	
	node *iter = constant;
	
	while(iter->next != NULL && iter->next->number < sayi){
		
		iter = iter->next;
	}
	node *temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->number = sayi;
	return constant;
	}
}

int main()
{
	
	int sayi, t, i = 0;
	node *constant;
	
	constant = NULL;
	cin >> sayi;
	
	while(sayi != -1)
	{
		
		constant = function(constant, sayi);
		
		cin >> sayi;
		i++;
	}
	
	while(constant != NULL)
	{
		
		cout << constant->number << "   ";
		
		constant = constant->next;
	}
}








