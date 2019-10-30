#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE 100000

using namespace std;

struct n {

	int data;
	n* prev;
	n* next;
};
typedef n node;

node* insert(node* y, int x) {

	if (y == NULL)
	{

		y = (node*)malloc(sizeof(node));
		y->next = NULL;
		y->prev = NULL;
		y->data = x;
		return y;
	}
	node* newSpace = (node*)malloc(sizeof(node));
	newSpace->data = x;
	if (y->data > newSpace->data) {

		newSpace->next = y;
		y->prev = newSpace;
		newSpace->prev = NULL;
		return newSpace;
	}

	node* iter = y;
	while (iter->next != NULL && iter->next->data < newSpace->data)
		iter = iter->next;

	newSpace->next = iter->next;
	iter->next = newSpace;
	newSpace->prev = iter;
	if (newSpace->next != NULL)
		newSpace->next->prev = newSpace;

	return y;
}

int main()
{

	node* root = NULL;
	int query, i, j, stick, temp;
	int hor = 0, ver = 0;
	cin >> query;	// You determine how many queries will be

	if (query > 0 && query < 100001)
	{

		for (i = 0; i < query; i++) {
			cin >> stick;
			root = insert(root, stick);
		}

		node* temp2 = root, * temp3;

		while (temp2->next != NULL)
			temp2 = temp2->next;

		for (j = 0; j < query;) {

			hor += temp2->data;
			//			cout << "girdi1" << endl;
			//			cout << "stick[" << j << "] :" << temp2->data << " max:" << hor << endl;
			temp3 = temp2;
			temp2 = temp2->prev;
			free(temp3);
			j++;


			if (j != query) {

				temp = 0;

				ver += root->data;
				//				cout << "girdi2" << endl;
				//				cout << "stick[" << j << "]~:" << root->data << " min~:" << ver << endl;
				temp3 = root;
				root = root->next;
				free(temp3);
				j++;
			}
		}

		//		cout << "hor:" << hor << " ver:" << ver << endl;
		cout << setprecision(30) << (long long)hor * hor + (long long)ver * ver;
	}
}


/*

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		long long i,s=0,l=0,n,a[100010],sum;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(i=0;i<n/2;i++)
			s+=a[i];
		for(;i<n;i++)
			l+=a[i];
		sum=s*s+l*l;
		cout<<sum;
		return 0;
	}
*/
