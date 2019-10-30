#include <iostream>
#include <cstdlib>

using namespace std;

enum color{RED, BLACK};

struct node{
	
	int data;
	int height;
	bool color;
	node *left, *right, *parent;
};

node *leftrotate(node *head);

node *rightrotate(node *head){

	node *grandparent;
	
	if(head->parent->parent != NULL){
		
		grandparent = head->parent->parent;
		// ll
		if(grandparent->left == head->parent)
		{
			
		grandparent->left = NULL;//head->parent->right;
		head->parent->right = grandparent;
		
		head->parent->color = BLACK;
		grandparent->color = RED;
		}
		//rl
		else{
		/*
		grandparent->right = head;
		head->parent->left = head->right;
		head->right = head->parent;
		
		head->parent = leftrotate(head->parent);*/
		}
	}
	
	
	return head;
}

node *leftrotate(node *head){

	node *grandparent;

	if(head->parent->parent != NULL){
		
		grandparent = head->parent->parent;
		// rr
		if(grandparent->right == head->parent)
		{

		grandparent->right = NULL;//head->parent->left;
		head->parent->left = grandparent;
		
		head->parent->color = BLACK;
		grandparent->color = RED;
		}
		//lr
		else
		{
		/*	
		grandparent->left = head;
		head->parent->right = head->left;
		head->left = head->parent;
		
		head->parent = rightrotate(head->parent);*/
		}
	}
	
	return head;
}









int i;

node *fixColor(node *head){
	
	node *grandparent, *uncle;
	grandparent = NULL;
	uncle = NULL;
	
	if(head->parent != NULL && head->parent->parent != NULL){
		
		grandparent = head->parent->parent;
		
		if(grandparent->left == head->parent)
			if(grandparent->right != NULL)
				uncle = grandparent->right;
				
		else
			if(grandparent->left != NULL)
				uncle = grandparent->left;
	}
	
	
	// en buyuk parent yani treenin root kismi
	if(head->parent == NULL){
		
		head->color = BLACK;
	}
	// root degilse
	else{
		
		if(head->parent->color != BLACK){
			
			if(uncle != NULL && uncle->color == RED){
				
				head->parent->color = BLACK;
				uncle->color = BLACK;
				
				grandparent->color = RED;
				
				grandparent = fixColor(grandparent);
			}
			else{
			
				// Left Left Case // Right Left Case
				if(head->parent->left == head)
					rightrotate(head);
				// Left Right Case // Right Right Case
				else if(head->parent->right == head)
					leftrotate(head);
			}
		}
		//else
		//	 parent siyah ise anormal birsey yok
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

node *insert(node *tree, int x){
	
	node *grandparent = NULL;
	node *parent = NULL;
	node *uncle = NULL;
	
	if(tree == NULL){
		
		node *temp = (node*)malloc(sizeof(node));
	
		if(i == 0)
			temp->parent = NULL;
		
		temp->data = x;
		temp->height = 1;
		temp->color = RED;
		
		temp->left = NULL;
		temp->right = NULL;
		
		return temp;
	}
	
	if(tree->data > x){
		
		tree->left = insert(tree->left,x);
		tree->left->parent = tree;
	}
		
	else{
	
		tree->right = insert(tree->right,x);
		tree->right->parent = tree;
	}
	
	// rengi ayarlama
	tree = fixColor(tree);
	
	
	// leveli ayarlama
	tree->height = 1 + max(height(tree->left), height(tree->right));
		
	return tree;	
}


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
    if (level == 1 && data==-1){
    	
    	if(head->color == BLACK)
    		cout << head->data << " B";
    	else
    		cout << head->data << " R";
	}
	else if(level==1){
		
    	if(head->color == BLACK)
    		cout << head->data << " B (" << data << " " << rotation << ") ";
    	else
    		cout << head->data << " R (" << data << " " << rotation << ") ";
	}
    else if (level > 1)
    {
        print2(head->left, level-1, head->data, 'L');
        print2(head->right, level-1, head->data, 'R');
    }
}

int main()
{
	
	node *tree = NULL;
	int x;
	
	cin >> x;
	
	while(x != -1){
		
		tree = insert(tree,x);
				
		cin >> x;
	}
	
//	node *temp = tree;
	
	print(tree);
	cout << endl;
	printLevelOrder(tree);
}
