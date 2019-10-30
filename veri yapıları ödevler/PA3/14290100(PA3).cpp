#include <iostream>
#include <cstdlib>

using namespace std;

struct nodeFB{
	
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS{
	
	int id;
	struct nodeGS *next;
};

struct nodeFBGS{
	
	int id;
	int age;
	struct nodeGSFB *next;
};

struct nodeGSFB{
	
	int id;
	struct nodeFBGS *next;
};

void printFB(struct nodeFB *head)
{
	
	while(head != NULL)
	{
		
		cout << "Id:" << head->id << "\tAge:" << head->age << endl;
		head = head->next;
	}
}

void printGS(struct nodeGS *head)
{
	
	while(head != NULL)
	{
		
		cout << "Id:" << head->id << endl;
		head = head->next;
	}
}

void printAll(struct nodeFBGS *head)
{
	
	while(head->next != NULL)
	{
		
		cout << "Id:" << head->id << "\tAge:" << head->age << endl;
		
		if(head->next->next == NULL)
			break;
		
		cout << "Id:" << head->next->id << endl;
		
		head = head->next->next;
	}
}

nodeFB *function1(nodeFB *head, int id, int age)
{
	
	if(head == NULL){
		
		head = (nodeFB*)malloc(sizeof(nodeFB));
		head->next = NULL;
		
		head->id = id;
		head->age = age;
		
		return head;
	}
	else if(head->id > id){
		
		nodeFB *temp;
		temp = (nodeFB*)malloc(sizeof(nodeFB));
		
		temp->id = id;
		temp->age = age;
		
		temp->next = head;
		
		return temp;
	}
	else{
		
		nodeFB *temp2;
		temp2 = head;
		
		while(temp2->next != NULL && temp2->next->id < id){
			
			temp2 = temp2->next;
		}
		
		nodeFB *temp;
		temp = (nodeFB*)malloc(sizeof(nodeFB));
		
		temp->id = id;
		temp->age = age;
		
		temp->next = temp2->next;
		temp2->next = temp;
		
		return head;
	}
}

nodeGS *function2(nodeGS *head, int id)
{
	
	if(head == NULL){
		
		head = (nodeGS*)malloc(sizeof(nodeGS));
		head->next = NULL;
		
		head->id = id;
		
		return head;
	}
	else if(head->id < id){
		
		nodeGS *temp;
		temp = (nodeGS*)malloc(sizeof(nodeGS));
		
		temp->id = id;
		
		temp->next = head;
		
		return temp;
	}
	else{
		
		nodeGS *temp2;
		temp2 = head;
		
		while(temp2->next != NULL && temp2->next->id > id){
			
			temp2 = temp2->next;
		}
		
		nodeGS *temp;
		temp = (nodeGS*)malloc(sizeof(nodeGS));
		
		temp->id = id;
		
		temp->next = temp2->next;
		temp2->next = temp;
		
		return head;
	}
}

int main()
{
	
	nodeFB *root1, *temp1;
	nodeGS *root2, *temp2;
	nodeFBGS *complex1, *root3;
	int id, age;

	root1 = NULL;
	root2 = NULL;

	while(1){
		
		cin >> id >> age;
		
		if (id == -1 && age == -1)
			break;
			
		root1 = function1(root1, id, age);
	}
	
	while(1){
		
		cin >> id;
		
		if (id == -1)
			break;
			
		root2 = function2(root2, id);
	}
	
	temp1 = root1;
	temp2 = root2;

	complex1 = (nodeFBGS*)malloc(sizeof(nodeFBGS));
	root3 = complex1;
	
	while(1)
	{
		
		if(temp1 == NULL)
		{
			
			root3 = NULL;
			break;
		}
		
		root3->id = temp1->id;
		root3->age = temp1->age;
		
		root3->next = (nodeGSFB*)malloc(sizeof(nodeGSFB));
		temp1 = temp1->next;
		
		if(temp2 == NULL)
		{
			
			root3->next = NULL;
			break;
		}
		
		root3->next->id = temp2->id;
		
		root3->next->next = (nodeFBGS*)malloc(sizeof(nodeFBGS));
		root3 = root3->next->next;
		temp2 = temp2->next;
	}
		
	printFB(root1);
	cout << endl;	
	printGS(root2);
	cout << endl;
	printAll(complex1);
}
