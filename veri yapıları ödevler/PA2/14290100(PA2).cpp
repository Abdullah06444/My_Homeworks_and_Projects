#include <iostream>
#include <cstdlib>

using namespace std;

struct nodeClass{
	
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent{
	
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

void printAll(nodeClass *head)
{
	
	while(head->studentPtr->next != NULL){
		
		cout << head->studentPtr->studentID << " " << head->studentPtr->midterm << endl;
		head->studentPtr = head->studentPtr->next;	
	}
}

void printClassList(nodeClass *head, int classID)
{
	
	cout << head->classID << " " << head->classMidtermAverage << endl;
}

int main()
{
	
	int x = 0, y = 0, z = 0, t = 0;
	int lowcnt, i = 0, j, k, arr[10000][2];
	nodeClass *root;
	nodeStudent *root2, *temp, *temp2;
	nodeStudent *rot1, *rot2, *rot3, *rot4;
	nodeStudent *iter1, *iter2, *iter3, *iter4;
	nodeStudent *kok1, *kok2, *kok3, *kok4;
	
	root = NULL;
	root2 = NULL;
			
	
	root = (nodeClass*)malloc(sizeof(nodeClass));
	root->classID = 1;
	
	
	root->studentPtr = (nodeStudent*)malloc(sizeof(nodeStudent));
	rot1 = root->studentPtr;
	iter1 = root->studentPtr;
	kok1 = root->studentPtr;

	
	root->next = (nodeClass*)malloc(sizeof(nodeClass));
	root->next->classID = 2;



	root->next->studentPtr = (nodeStudent*)malloc(sizeof(nodeStudent));	
	rot2 = root->next->studentPtr;
	iter2 = root->next->studentPtr;
	kok2 = root->next->studentPtr;


	root->next->next = (nodeClass*)malloc(sizeof(nodeClass));
	root->next->next->classID = 3;



	root->next->next->studentPtr = (nodeStudent*)malloc(sizeof(nodeStudent));	
	rot3 = root->next->next->studentPtr;
	iter3 = root->next->next->studentPtr;
	kok3 = root->next->next->studentPtr;


	root->next->next->next = (nodeClass*)malloc(sizeof(nodeClass));
	root->next->next->next->classID = 4;
	
	
	
	root->next->next->next->studentPtr = (nodeStudent*)malloc(sizeof(nodeStudent));
	rot4 = root->next->next->next->studentPtr;
	iter4 = root->next->next->next->studentPtr;
	kok4 = root->next->next->next->studentPtr;

	
	root->next->next->next->next = NULL;



	//input scope
	while (1){
		
		cin >> arr[i][0];
		cin >> arr[i][1];
	
		if(arr[i][0] == -1 || arr[i][1] == -1)
			break;
			
		i++;
	}
	
	
	
	//from high grade to low grade
	for(j=0; j<i; j++){
				
		for(k=j+1; k<i; k++){
					
			if(arr[k][1] > arr[j][1]){
						
				int m, n;
				m = arr[j][1];
				n = arr[j][0];
				arr[j][1] = arr[k][1];
				arr[j][0] = arr[k][0];
				arr[k][1] = m;
				arr[k][0] = n;
			}
		}
	}
		
	root2 = (nodeStudent*)malloc(sizeof(nodeStudent));		
	temp = root2;
		
	for (j=0; j<i; j++){
		
		root2->studentID = arr[j][0];
		root2->midterm = arr[j][1];
		
		root2->next = (nodeStudent*)malloc(sizeof(nodeStudent));
		root2->next->next = NULL;
		root2 = root2->next;
	}
	
	

	//inputlari sinifina koyma
	for(j=0; j<i; j++){
		

		if((temp->studentID / 1000) == 66){			
			
			rot1->studentID = temp->studentID;
			rot1->midterm = temp->midterm;
			

			rot1->next = (nodeStudent*)malloc(sizeof(nodeStudent));
			rot1->next->next = NULL;
			temp = temp->next;
			rot1 = rot1->next;
			x++;
		}
		else if((temp->studentID / 1000) == 77){
			
			rot2->studentID = temp->studentID;
			rot2->midterm = temp->midterm;
			
				
			rot2->next = (nodeStudent*)malloc(sizeof(nodeStudent));
			rot2->next->next = NULL;
			temp = temp->next;
			rot2 = rot2->next;
			y++;
		}
		else if((temp->studentID / 1000) == 88){
			
			rot3->studentID = temp->studentID;
			rot3->midterm = temp->midterm;

				
			rot3->next = (nodeStudent*)malloc(sizeof(nodeStudent));
			rot3->next->next = NULL;
			temp = temp->next;
			rot3 = rot3->next;
			z++;
		}
		else if((temp->studentID / 1000) == 99){
			
			rot4->studentID = temp->studentID;
			rot4->midterm = temp->midterm;

				
			rot4->next = (nodeStudent*)malloc(sizeof(nodeStudent));
			rot4->next->next = NULL;
			temp = temp->next;
			rot4 = rot4->next;
			t++;
		}
	}
	
	
	
	// find the minimum class number
	if (x>y){//forget x
		
		if (y>z){//forget x,y
			
			if (z>t)//forget x,y,z
				lowcnt = t;
			else//forget x,y,w
				lowcnt = z;
		}
		else {//forget x,z
			
			if (y>t)//forget x,y,z
				lowcnt = t;
			else//forget x,z,w
				lowcnt = y;
		}
	}
	else {//forget y
		
		if (x>z){//forget x,y
			
			if (z>t)//forget x,y,z
				lowcnt = t;
			else//forget x,y,w
				lowcnt = z;
		}
		else{//forget y,z
			
			if (x>t)//forget x,y,z
				lowcnt = t;
			else//forget y,z,w
				lowcnt = x;
		}
	}
	
	
	
	//delete operation
	for(j=0; j<lowcnt; j++){
		
		if(j == lowcnt-1){
			
			kok1->next->next = NULL;
		}
	
			kok1 = kok1->next;
	}
	for(j=0; j<lowcnt; j++){
		
		if(j == lowcnt-1){
			
			kok2->next->next = NULL;
		}
	
			kok2 = kok2->next;
	}
	for(j=0; j<lowcnt; j++){
		
		if(j == lowcnt-1){
			
			kok3->next->next = NULL;
		}

			kok3 = kok3->next;
	}
	for(j=0; j<lowcnt; j++){
		
		if(j == lowcnt-1){
			
			kok4->next->next = NULL;
		}

			kok4 = kok4->next;
	}	

	
	
	
	//the midterm averages of the all classes
	int sum=0;
	double average;
	for(j=0; j<lowcnt; j++){
		
		sum += iter1->midterm;
		iter1 = iter1->next;
	}
	average = (double) sum/j;
	root->classMidtermAverage = average;
	
	
	sum=0;
	for(j=0; j<lowcnt; j++){
		
		sum += iter2->midterm;
		iter2 = iter2->next;
	}
	average = (double) sum/j;
	root->next->classMidtermAverage = average;
	
	
	sum=0;
	for(j=0; j<lowcnt; j++){
		
		sum += iter3->midterm;
		iter3 = iter3->next;
	}
	average = (double) sum/j;
	root->next->next->classMidtermAverage = average;
	

	sum=0;
	for(j=0; j<lowcnt; j++){
		
		sum += iter4->midterm;
		iter4 = iter4->next;
	}
	average = (double) sum/j;
	root->next->next->next->classMidtermAverage = average;

	
	printAll(root);
	printf("\n");
	
	
	printClassList(root,root->classID);
	printClassList(root->next,root->next->classID);
	printClassList(root->next->next,root->next->next->classID);
	printClassList(root->next->next->next,root->next->next->next->classID);
}

