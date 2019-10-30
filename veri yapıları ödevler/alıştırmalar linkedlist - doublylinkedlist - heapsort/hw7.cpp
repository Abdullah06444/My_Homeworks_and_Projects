#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

char BLACK  = 'B';
char RED    = 'R';

struct Node{
	int data;
	int height;
    char colour;
    struct Node* parent;
    struct Node* left;
	struct Node* right;
};
struct Node* createNode(int data, struct Node* parent=NULL){
    struct Node* node       = (struct Node*)malloc(sizeof(struct Node));
    node->data              = data;
    node->height            = 1;  // new node is initially added at leaf
    node->colour             = RED;
    node->left              = NULL;
    node->parent              = parent;
    node->right             = NULL;
    return(node);
}
struct Node *root = NULL;

struct Node * grand_parent(struct Node *n){
    // No parent means no grand_parent
    if ((n != NULL) && (n->parent != NULL))
        return n->parent->parent;
    else
        return NULL;
}

struct Node *uncle(struct Node *n){
    struct Node *g;
    g = grand_parent(n);
    //With no grandparent, there cannot be any uncle
    if (g == NULL)
        return NULL;
    if (n->parent == g->left)
        return g->right;
    else
        return g->left;
}

void case5(struct Node *n);
void case4(struct Node *n);
void case3(struct Node *n);
void case2(struct Node *n);
void case1(struct Node *n);

// A utility function to get height of the tree
int height(struct Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}

struct Node *rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right  = y;
    y->left   = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    case1(x->left);
 
    // Return new root
    return x;
}

struct Node *leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left  = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

void case5(struct Node *n){
    struct Node *g;
    g = grand_parent(n);
    if ((n == n->parent->left) && (n->parent == g->left))
        rightRotate(g);
    else if ((n == n->parent->right) && (n->parent == g->right))
        leftRotate(g);
    n->parent->colour = BLACK;
    g->colour = RED;
}

void case4(struct Node *n){
    struct Node *g = grand_parent(n);
    if ((n == n->parent->right) && (n->parent == g->left)){
        leftRotate(n->parent);
        n = n->left;
    } else if ((n == n->parent->left) && (n->parent == g->right)){
        rightRotate(n->parent);
        n = n->right;
    }
    case5(n);
}

void case3(struct Node *n){
    struct Node *u, *g;
    u = uncle (n);
    g = grand_parent(n);
    if ((u != NULL) && (u->colour == RED)) {
        n->parent->colour = BLACK;
        u->colour = BLACK;
        g->colour = RED;
        case1(g);
    }
    else {
        case4(n);
    }
}

void case2(struct Node *n){
    if (n->parent->colour == BLACK)
        return; /* Red black tree property is not violated*/
    else
        case3(n);
}

void case1(struct Node *n){
    if (n->parent == NULL) // Root node
        n->colour = BLACK;
    else
        case2(n);
}


int getBalance(struct Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int data, struct Node* parent=NULL){
    /* 1.  Perform the normal BST insertion */
    if (node == NULL){
        struct Node * newNode     = createNode(data, parent);

        case1(newNode);

        return(newNode);
    }
 
    else if (data < node->data)
        node->left  = insert(node->left, data, node);
    else if (data > node->data)
        node->right = insert(node->right, data, node);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor Node */
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && data > node->left->data){
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && data < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
void inorderTraversal(struct Node *tree){
	if(tree!=NULL){
		inorderTraversal(tree->left);
		cout << tree->data << "\n";
		inorderTraversal(tree->right);
	}
}
 
void printGivenLevel(struct Node* root, int level, int data=-1, char direction='z'){
    if (root == NULL)
        return;

    if (level == 1){
    	cout << root->data << " " << root->colour;

        // if it is not root node
        if(direction!='z')
    		cout << " (" << data << " " << direction << ") ";
    }
    else if (level > 1){
        printGivenLevel(root->left, level-1, root->data, 'L');
        printGivenLevel(root->right, level-1, root->data, 'R');
    }
}
void printLevelOrder(struct Node* root){
    int h = root->height;
    for (int i=1; i<=h; i++){
        printGivenLevel(root, i);
        cout << "\n";
    }
}

int main(){
	int input;
	
	while(true){
		scanf("%d", &input);
		
		if(input==-1)
			break;
			
		root = insert(root, input);
        case1(root);
	}
	
	inorderTraversal(root);
	
	cout << "\n\n";
	
	printLevelOrder(root);
	
	return 0;
}
