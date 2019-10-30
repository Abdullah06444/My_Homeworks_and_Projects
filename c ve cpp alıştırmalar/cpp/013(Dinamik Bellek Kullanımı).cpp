#include <iostream>

using namespace std;

void read(int [], int);

int main()
{
	
	int total, sum=0;
	int higher_grade = 0;
	int *grade;
	
	cout << "Please enter the total of student in the class : ";
	cin >> total;
	
	grade = new int[total];
	
	read(grade, total);
	
	for (int i=0; i<total; i++)
	{
		
		sum += grade[i];
		if (grade[i] > higher_grade)
			higher_grade = grade[i];
	}
	
	cout << "The average of class is " << (float) sum/total << endl;
	cout << "The higher grade is " << higher_grade << endl;
	
	delete [] grade;
	return 0;
}

void read(int grade[], int limit)
{
	
	cout << "Please enter the grades of the sdudents : ";
	
	for (int i=0; i<limit; i++)
		cin >> grade[i];
}
