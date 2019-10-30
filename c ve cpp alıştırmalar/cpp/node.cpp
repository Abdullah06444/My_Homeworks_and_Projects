#include <iostream>
#include <cstdlib>

using namespace std;

struct n{
	
	int x;
	n* next;
};
typedef n node;

int main()
{
	
	int a;
	
	node* root;
	root = (node*)malloc(sizeof(node));
	root->x = 25;
	cout << root->x << endl;
	a = root->x;
	
	root->next = (node*)malloc(sizeof(node));
	root->next->x = 74;
	cout << root->next->x << endl;	
	
	root->next->next = (node*)malloc(sizeof(node));
	root->next->next->x = 41;
	cout << root->next->next->x << endl;
	
//	root = (node*)malloc(sizeof(node));
	root->x = 94;
	cout << root->x << endl;
}
