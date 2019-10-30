#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	
	int data;
	node *next;
};

node *insert(node *head, int value)
{
	
	// if the root is null
	if(head == NULL)
	{
		
		node *temp = (node*)malloc(sizeof(node));
		
		temp->data = value;
		temp->next = NULL;
		
		return temp;
	}
	
	// if the value is smaller than the root
	if(value < head->data)
	{
		
		node *temp = (node*)malloc(sizeof(node));
		
		temp->data = value;
		temp->next = head;
		
		return temp;
	}
	// if the value is bigger than the root
	node *temp = head;
	while(head->next != NULL && value > head->next->data)
		head = head->next;
		
	head->next = insert(head->next, value);
	return temp;
}

void print(node *head)
{
	
	while(head != NULL)
	{
		
		cout << head->data << " ";
		
		head = head->next;
	}
}

int main()
{
	
	node *root = NULL;
	int x;
	
	cin >> x;
	
	while(x != -1)
	{
		
		root = insert(root,x);
		print(root);
		cout << endl << endl;
		cin >> x;
	}
}
