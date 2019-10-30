#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	
	int data;
	node *left;
	node *right;
};

node *iter[10000];
int i;

void heapify(int j)
{
	
	while(j > 0)
	{
	
		if(iter[j]->data > iter[(j-1)/2]->data)
		{
		
			int temp = iter[j]->data;
			iter[j]->data = iter[(j-1)/2]->data;
			iter[(j-1)/2]->data = temp;
		}
		
		j = (j-1)/2;
	}
}

node *insert(node *head, int value)
{
	
	if(head == NULL)
	{
		
		head = (node*)malloc(sizeof(node));
		
		head->data = value;
		head->left = NULL;
		head->right = NULL;
		
		iter[i++]=head;
		
		return head;
	}
	
	if(head->left == NULL)
	{
		
		head->left = (node*)malloc(sizeof(node));
		
		head->left->data = value;
		head->left->left = NULL;
		head->left->right = NULL;
		
		iter[i]=head->left;
		
		heapify(i++);
		
		return head;
	}
	
	if(head->right == NULL)
	{
		
		head->right = (node*)malloc(sizeof(node));
		
		head->right->data = value;
		head->right->left = NULL;
		head->right->right = NULL;
		
		iter[i]=head->right;
		
		heapify(i++);
		
		return head;
	}
	
	insert(iter[(i+1)/2], value);
}

void print()
{
	
	int k=0;
	while(iter[k] != NULL)
	{
		
		cout << iter[k]->data << " ";
		
		k++;
	}
	cout << endl;
}

int main()
{
	
	node *root = NULL;
	int x;
	
	cin >> x;
	
	while(x != -1)
	{
		
		root = insert(root, x);
		print();
		cin >> x;
	}
	
	print();
}
