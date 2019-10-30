#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int x;
	node* next;
};
typedef n node;

int main()
{
	
	struct node* root;
	root = (node*)malloc(sizeof(node));
	root->x = 25;
	printf ("%d\n", root->x);
	
	root->next = (node*)malloc(sizeof(node));
	root->next->x = 74;
	printf ("%d\n", root->next->x);	
	
	root->next->next = (node*)malloc(sizeof(node));
	root->next->next->x = 41;
	printf ("%d\n", root->next->next->x);
}
