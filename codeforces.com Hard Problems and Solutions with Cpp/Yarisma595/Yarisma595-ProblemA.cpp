#include <iostream>
#include <cstdlib>
#include <cmath>
#define SIZE 100

using namespace std;

struct n {

	int data;
	n* next;
};
typedef n node;

node* insert(node* y, int x) {

	if (y == NULL)
	{

		y = (node*)malloc(sizeof(node));
		y->next = NULL;
		y->data = x;
		return y;
	}
	node* newSpace = (node*)malloc(sizeof(node));
	newSpace->data = x;
	if (y->data > newSpace->data) {

		newSpace->next = y;
		return newSpace;
	}

	node* iter = y;
	while (iter->next != NULL && iter->next->data < newSpace->data)
		iter = iter->next;

	newSpace->next = iter->next;
	iter->next = newSpace;

	return y;
}

int main() {

	int query, n, a, i, j, team;

	cin >> query;

	if (query >= 1 && query <= 100) {

		for (i = 0; i < query; i++) {

			node* root = NULL;
			team = 1;
			cin >> n;

			for (j = 0; j < n; j++) {

				cin >> a;
				root = insert(root, a);
			}

			node* iter = root;

			while (iter->next != NULL)
			{
			
				if (iter->next->data - iter->data == 1) {
					team ++;
					break;
				}
				iter = iter->next;
			}
			cout << team << endl;
		}

	}
}