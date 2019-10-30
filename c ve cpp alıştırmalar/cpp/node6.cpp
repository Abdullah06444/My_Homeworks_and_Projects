#include <iostream>
#include <cstdlib>

using namespace std;

class Tree
{
public:
	int value;
	Tree* left;
	Tree* right;


void insert(Tree* root, int newValue)
{
	if(root== NULL)
	{
		root = new Tree;
		root-> value = newValue;
		root -> left = NULL;
		root -> right = NULL;
		return;
	}
	else if(newValue < root->value)
	{
		insert(root->left,newValue);
	}
	else
		insert(root->right,newValue);
}

void printInOrder(Tree* node)
{
	if(node = NULL)
		return;
	else
	{
		printInOrder(node->left);
		cout<<node;
		printInOrder(node->right);
	}
}
void TreeSort (int list[], int N)
{
	Tree* root;
	root= NULL;

	for (int i=0; i<N; i++)
	{
		insert(root, list[i]);
	}
	printInOrder(root);

}
};

int main()
{
	Tree bst;
//	int* list = new int[];
	int numArray;
	cout<<"Enter num to be inserted in array\n";
	cin>>numArray;
//	bst.TreeSort(list, numArray);

	return 0;
}
