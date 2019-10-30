#include <iostream>

using namespace std;

class business{
	
	private:
		char name[10];
		char surname[10];
		char occupation[25];
		int age;
		
	public:
		business(){	// It is a constructor method of class. If we don't define it, the code
					//	can be defined self to this constructor method.			
			cout << "Hello guys. Welcome to the our company." << endl;
			cout << "First of all you have to do to several options for join us." << endl;
			cout << "**********************************************" << endl;
		}
		business(char p[]){	// If we call to this method with a value, the code
					//	do the operation in here.
			cout << "Hello guys. Welcome to the our company." << endl;
			cout << "First of all you have to do to several options for join us." << endl;
			cout << "**********************************************" << endl;
			cout << "I am not a constructor method to this class. :-) :-) :-)" << endl;
		}		
		~business(){	// It is a descructor method of class. We don't define a parameter for
						// this method.
			cout << "It disappeared the values." << endl;
		}
		void names(){
			
			cout << "Please enter the your name : ";
			cin >> name;
			cout << "Please enter the your surname : ";
			cin >> surname;
			cout << "How old are you?" << endl;
			cin >> age;
		}
		void job(){
			
			cout << "What is the your occupation?" << endl;
			cin >> occupation;
		}
};

int main()
{
	
	business employee1;
	
	employee1.names();
	employee1.job();
	
	business employee2("a");
	
	employee2.names();
	employee2.job();
}
