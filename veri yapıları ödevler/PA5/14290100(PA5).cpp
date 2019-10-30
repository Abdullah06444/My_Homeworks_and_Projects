#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	
	int identity;
	int grade;
	node* left;
	node* right;
};

node *insertion(node* head, int id, int gr){
	
	if(head == NULL){
		
		node* root = (node*)malloc(sizeof(node));
		
		root->identity = id;
		root->grade = gr;
		
		root->left = NULL;
		root->right = NULL;
		
		return root;
	}
	
	if(head->grade < gr)
		head->right = insertion(head->right, id, gr);
	else
		head->left = insertion(head->left, id, gr);
	return head;
}



void print_student(node *head);
int height(struct node* node);
void printGivenLevel(struct node* root, int level, int grade, char rotation);
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++){
        printGivenLevel(root, i, -1, 'A');
        cout << endl;
    }
}
 
void printGivenLevel(struct node* root, int level, int grade=-1, char rotation='A')
{
    if (root == NULL)
        return;
    if (level == 1 && grade==-1)
    	cout << root->identity << " " << root->grade;
	else if(level==1)
		cout << root->identity << " " << root->grade << " (" << grade << " " << rotation << ") ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1, root->grade, 'L');
        printGivenLevel(root->right, level-1, root->grade, 'R');
    }
}
 
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

int main(){

	node *father, *root;
	father = NULL;
	
	int input, input2;
	
	cin >> input >> input2;
	
	while(input != -1 && input2 != -1)
	{
		
		father = insertion(father, input, input2);
		cin >> input >> input2;
	}
	
	root = father;
	
	print_student(father);
	cout << endl;
	printLevelOrder(father);
}

void print_student(node *head){
	
	if(head == NULL)
		return;
	
	if(head->left != NULL)
		print_student(head->left);
	cout << head->identity << " " << head->grade << endl;
	if(head->right != NULL)
		print_student(head->right);
}


