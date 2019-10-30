#include <stdio.h>
#include <stdlib.h>
//sirali ekleme sirasi
struct n{
	
	int x;
	n *next;
};
typedef n node;

void bastir(node* r){
	
	while(r != NULL){
		
		printf("%d ", r->x);
		r = r->next;
	}
}


node *ekleSirali(node *r, int x){
	
	if(r == NULL){	// link list bos ise
		
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}
	
	if(r->x > x){	// ilk elemandan kucuk durumu
		// root degisiyor	
		node *temp= (node*)malloc(sizeof(node));
	//	temp->next = NULL;  gerek yok
		temp->x = x;
		temp->next = r;
		return temp;
	}
	else{	//	ortadaki ya da sondaki elemandan kucuk durumu
	
	node *iter = r;	// r bize lazim o yuzden iterator tanimlariz.
	
	while(iter->next != NULL && iter->next->x < x){
		
		iter = iter->next;
	}
	node *temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = x;
	return r;
	}

/*	
	if (r->next == NULL){
		
		if(r->x > x){
			
			node *temp= (node*)malloc(sizeof(node));
			temp->next = NULL;
			temp->x = x;
			temp->next = root;
			return temp;
		}
		else{
			
			node *temp= (node*)malloc(sizeof(node));
			temp->x = x;
			temp->next = NULL;
			r->next = temp;
			return r;
		}
	}
*/
}

int main()
{
	
	node *root;
	root = NULL;
	root = ekleSirali(root, 400);
	root = ekleSirali(root, 40);
	root = ekleSirali(root, 4);
	root = ekleSirali(root, 450);
	root = ekleSirali(root, 50);
	
	bastir(root);

}


