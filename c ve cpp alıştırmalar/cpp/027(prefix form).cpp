#include <iostream>

using namespace std;

class special{
	
	int mark;
	public:
		special(){
			
			mark = 0;
		}
		special(int a){
			
			mark = a;
		}
		void print(){
			
			cout << mark << endl;
		}
		special operator++(){
			
			mark += 1;
			return *this;
		}
		friend void operator--(special &);
		special operator-=(int);
};

void operator--(special &x){
	
	x.mark -= 1;
}

special special::operator-=(int m){
	
	mark = mark - m;
}

int main()
{
	
	special number = 67;
	number.print();
	
	++number;
	number.print();
	
	special number2 = 52;
	number2.print();
	
	--number2;
	number2.print();
	
	special number3 = 23;
	number3.print();
	
	number3 -= 7;
	number3.print();	
}
