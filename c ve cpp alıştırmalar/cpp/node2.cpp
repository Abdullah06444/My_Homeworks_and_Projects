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
	
	node* root = (node*)malloc(sizeof(node));
	node* iter = root;
		
	cin >> iter->x;

	root->next = (node*)malloc(sizeof(node));
	cin >> iter->next->x;

	root->next->next = (node*)malloc(sizeof(node));
	cin >> iter->next->next->x;

	root->next->next->next = (node*)malloc(sizeof(node));
	cin >> iter->next->next->next->x;

	root->next->next->next->next = (node*)malloc(sizeof(node));
	cin >> iter->next->next->next->next->x;	

	cout << root->x << endl;
	cout << root->next->x << endl;
	cout << root->next->next->x << endl;
	cout << root->next->next->next->x << endl;
	cout << root->next->next->next->next->x << endl;
	
	return 0;
}
