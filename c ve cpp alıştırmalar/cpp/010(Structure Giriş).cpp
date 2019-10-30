#include <iostream>

using namespace std;

struct student{
	
	string name;
	int clas;
	int numberoflesson;
	float grade;
}s1,
s2 = {"Ahmet Tatli", 4, 5, 3.1};

int main()
{
	
	cin >> s1.name >> s1.clas >> s1.numberoflesson >> s1.grade;
	student s3 = {"Derya Yaman", 2, 7, 2.5};
	
	cout << s1.name << " " << s1.clas << " " << s1.numberoflesson << " " << s1.grade << endl;
	cout << s2.name << " " << s2.clas << " " << s2.numberoflesson << " " << s2.grade << endl;
	cout << s3.name << " " << s3.clas << " " << s3.numberoflesson << " " << s3.grade << endl;
	return 0;
}
