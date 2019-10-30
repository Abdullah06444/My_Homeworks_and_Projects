#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	
	int data;
	int height;
	node *left;
	node *right;
};

int height(node *head);
int max(int a, int b);
int getBalance(node *head);



//rotation functions
node *right(node *head)
{
	
	node *temp = head->left, *temp2 = temp->right;
	
	temp->right = head;
	head->left = temp2;
	
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	head->height = max(height(head->right), height(head->right)) + 1;
	
	return temp;
}

node *left(node *head)
{
	
	node *temp = head->right, *temp2 = temp->left;
	
	temp->left = head;
	head->right = temp2;
	
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	head->height = max(height(head->right), height(head->right)) + 1;
	
	return temp;
}



//insert function
node *insertion(node *head, int input)
{
	
	if(head == NULL)
	{
		
		node *root = (node*)malloc(sizeof(node));
		
		root->data = input;
		root->height = 1;
		
		root->left = NULL;
		root->right = NULL;
		
		return root;
	}
	
	if(head->data > input)
		head->left = insertion(head->left, input);
	else
		head->right = insertion(head->right, input);
		
	head->height = 1 + max(height(head->left), height(head->right));
	
	int balance = getBalance(head);
	
	//left left rotation
	if(balance > 1 && input < head->left->data)
		return right(head);
	
	//right right rotation
	if(balance < -1 && input > head->right->data)
		return left(head);
	
	//left right rotation
	if(balance > 1 && input > head->left->data)
	{
		
		head->left = left(head->left);
		return right(head);
	}
	
	//right left rotation
	if(balance < -1 && input < head->right->data)
	{
		
		head->right = right(head->right);
		return left(head);
	}
	
	return head;
}



int height(node* head);
void print2(node* head, int level, int data, char rotation);



void printLevelOrder(node* head)
{
    int h = height(head);
    int i;
    for (i=1; i<=h; i++){
        print2(head, i, -1, 'A');
        cout << endl;
    }
}
 
int height(node* head)
{
    if (head == NULL)
        return 0;
    else
    {
        int lheight = height(head->left);
        int rheight = height(head->right);
 
        if (lheight > rheight)
            return(lheight+1);
        else
			return(rheight+1);
    }
}

int max(int a, int b)
{
	
	return (a > b) ? a : b;
}

int getBalance(node *head)
{
	
	if(head == NULL)
		return 0;
	return height(head->left) - height(head->right);
}



//print functions
void print(node *head)
{
	
	if(head == NULL)
		return;
		
	if(head->left != NULL)
		print(head->left);
	cout << head->data << endl;
	if(head->right != NULL)
		print(head->right);
}

void print2(node* head, int level, int data=-1, char rotation='A')
{
    if (head == NULL)
        return;
    if (level == 1 && data==-1)
    	cout << head->data << " (" << getBalance(head) << " B) ";
	else if(level==1)
		cout << head->data << " (" << data << " " << rotation << ") (" << getBalance(head) << " B) ";
    else if (level > 1)
    {
        print2(head->left, level-1, head->data, 'L');
        print2(head->right, level-1, head->data, 'R');
    }
}



int main()
{
	
	node *father = NULL;
	int input;
	
	cin >> input;
	
	while(input != -1)
	{
		
		father = insertion(father, input);
		cin >> input;
	}
	
	print(father);
	cout << endl;
	printLevelOrder(father);
}
