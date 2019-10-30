#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	
	int data;
	node *next;
	node *prev;
};

node *insert(node *head, int value)
{
	
	if(head == NULL)
	{
		
		node *temp = (node*)malloc(sizeof(node));
		
		temp->data = value;
		
		temp->next = NULL;
		temp->prev = NULL;
		
		return temp;
	}
	
	if(value < head->data)
	{
		
		node *temp = (node*)malloc(sizeof(node));
		
		temp->data = value;
		
		temp->next = head;
		head->prev = temp;
		temp->prev = NULL;
		
		return temp;
	}
	
	node *temp = head;
	while(head->next != NULL && value > head->next->data)
		head = head->next;
		
	head->next = insert(head->next, value);
	head->next->prev = head;
	
	return temp;
}

void print(node *head)
{
	
	while(head->next != NULL)
		head = head->next;

	while(head != NULL)
	{
		
		cout << head->data << " ";
		head = head->prev;
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
