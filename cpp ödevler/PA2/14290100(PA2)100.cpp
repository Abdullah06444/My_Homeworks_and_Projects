#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	
	char word[1000];
	node* left;
	node* right;
};

int i;
node* iter[100000];

void add(node* father){
		
	if(father == NULL){
		
		father = (node*)malloc(sizeof(node));
		
		cin >> father->word;
		if(father->word[0] == 'e' && father->word[1] == 'n' && father->word[2] == 'd' && father->word[3] == '\0'){
			
			father = NULL;			
			return;
		}
		
		iter[i++] = father;
		
	}
	
	father->left = NULL;
	father->right = NULL;
	
	father->left = (node*)malloc(sizeof(node));
	
	cin >> father->left->word;
	if(father->left->word[0] == 'e' && father->left->word[1] == 'n' && father->left->word[2] == 'd' && father->left->word[3] == '\0'){
		
		father->left = NULL;
		return;
	}
	
	iter[i++] = father->left;
	

		
	father->right = (node*)malloc(sizeof(node));
	
	cin >> father->right->word;
	if(father->right->word[0] == 'e' && father->right->word[1] == 'n' && father->right->word[2] == 'd' && father->right->word[3] == '\0'){
		
		father->right = NULL;
		return;
	}
	
	iter[i++] = father->right;
	
	add(iter[i/2]);
}

int j;

void id1(node* father);
void id2(node* father);
void id3(node* father);
void id4(node* father);

int main()
{
	
	int option;
	node* btree;
	btree = NULL;
		
		add(btree);
				
	while(1){
	cin >> option;
		if (option == -1)
			continue;
		else if (option == 1)
			id1(btree);
		else if (option == 2)
			id2(btree);
		else if (option == 3)
			id3(btree);
		else if (option == 4)
			id4(btree);	
}
	cout << "Done!";
	
	for (int j=i-1; j>=0; j--)
		free (iter[j]);

	return 0;
}



void id1(node* father){

	if (father == NULL){
		
		father = (node*)malloc(sizeof(node));
		father = iter[0];
		
		cout << "*****" << endl;		
	}
	
	cout << father->word << endl;
	if (father->left != NULL)
		id1(father->left);
	if (father->right != NULL)
		id1(father->right);
}

void id2(node* father){
	
	if (father == NULL){
		
		father = (node*)malloc(sizeof(node));
		father = iter[0];
		
		cout << "*****" << endl;		
	}
	
	if (father->left != NULL)
		id2(father->left);
	if (father->right != NULL)
		id2(father->right);
	cout << father->word << endl;

}

void id3(node* father){
	
	if (father == NULL){
		
		father = (node*)malloc(sizeof(node));
		father = iter[0];
		
		cout << "*****" << endl;		
	}

	if (father->left != NULL)
		id3(father->left);
	cout << father->word << endl;
	if (father->right != NULL)
		id3(father->right);	
}

void id4(node* father){
	
	if (father == NULL){
		
		father = (node*)malloc(sizeof(node));
		father = iter[0];
		
		cout << "*****" << endl;
	}
	while(father->left != NULL)
		father = father->left;
	
	for(j=0; j<i; j++){
		
		if(father == iter[j])
			break;
	}

	while (iter[j] != NULL)
		cout << iter[j++]->word << endl;

	j = j/2-1;
	
	while (iter[++j] != father)
		cout << iter[j]->word << endl;
}
