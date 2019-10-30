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

node *dellete(node *head, int value)
{
	
	if(head == NULL)
	{
	
		cout << "The linked list is empty." << endl;
		return NULL;
	}
		
	if(value == head->data)
		return head->next;
	
	if(value < head->data)
	{
	
		cout << "There is no this value in the linked list." << endl;
		return head;
	}
	
	node *temp = head;	
	while(head->next != NULL && value > head->next->data)
		head = head->next;
		
	if(head->next != NULL)
		head->next = dellete(head->next, value);
	else
		cout << "There is no this value in the linked list." << endl;
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
		
		cin >> x;
	}
	print(root);
	cout << endl << endl;
	
	cout << "x = ";
	cin >> x;
	
	while(x != -1)
	{
		
		root = dellete(root,x);
		print(root);
		cout << endl << endl;
		
		cout << "x = ";
		cin >> x;
	}
}
