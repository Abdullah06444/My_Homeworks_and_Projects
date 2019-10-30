#include <stdio.h>
#include <stdlib.h>

struct n{
	
	int x;
	n* next;
};
typedef n node;

int main()
{
	
	struct node* root = (node*)malloc(sizeof(node));
	node* iter = root;
		
	scanf("%d", &iter->x);

	root->next = (node*)malloc(sizeof(node));
	scanf("%d", &iter->next->x);

	root->next->next = (node*)malloc(sizeof(node));
	scanf("%d", &iter->next->next->x);

	root->next->next->next = (node*)malloc(sizeof(node));
	scanf("%d", &iter->next->next->next->x);

	root->next->next->next->next = (node*)malloc(sizeof(node));
	scanf("%d", &iter->next->next->next->next->x);

	printf ("%d\n", root->x);
	printf ("%d\n", root->next->x);
	printf ("%d\n", root->next->next->x);
	printf ("%d\n", root->next->next->next->x);
	printf ("%d\n", root->next->next->next->next->x);

	return 0;
}
