#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	
	int data;
	
	node *left;
	node *right;
};

int i = 1;
node* array[1000];

void heapify(int j/*cagrilan arrayin numarasi*/)
{
	
	j --;
	while(j != 1)
	{
	
		if(array[j]->data > array[j/2]->data)
		{
		
			int temp = array[j]->data;
			array[j]->data = array[j/2]->data;
			array[j/2]->data = temp;
		}
		
		j = j/2;
	}
}

void insert(node *head)
{
	
	if(head == NULL)
	{
		
		head = (node*)malloc(sizeof(node));
			
		cin >> head->data;
			
		if(head->data == -1)
		{
				
			head = NULL;
			return;
		}	
	
		array[i++] = head;
	}
	head->left = NULL;
	head->right = NULL;
	
	
	
		head->left = (node*)malloc(sizeof(node));
		
		cin >> head->left->data;
		
		if(head->left->data == -1)
		{
			
			head->left = NULL;
			return;
		}
		
		array[i++] = head->left;
		heapify(i);

		head->left->left = NULL;
		head->left->right = NULL;
		


		head->right = (node*)malloc(sizeof(node));
		
		cin >> head->right->data;
		
		if(head->right->data == -1)
		{
			
			head->right = NULL;
			return;
		}
		
		array[i++] = head->right;
		heapify(i);

		head->right->left = NULL;
		head->right->right = NULL;



	insert(array[i/2]);
}                     

void printWalk(node *head)
{
	
	if(head == NULL)
	{
		
		head = (node*)malloc(sizeof(node));
		head = array[1];
	}
		
	if(head->left != NULL)
		printWalk(head->left);
	cout << head->data << endl;
	if(head->right != NULL)
		printWalk(head->right);
}

int main()
{

	node *root;
	root = NULL;
	
	insert(root);
	
	printWalk(root);
}
