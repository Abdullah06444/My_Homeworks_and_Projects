#include <iostream>

using namespace std;

class Marks{
	
	int mark;
	public:
		Marks(){
			
			mark = 0;
		}
		Marks(int m){
			
			mark = m;
		}
		void yourmark(){
			
			cout << "your mark is " << mark << endl;
		}
		void operator+=(int bonusmark){
			
			mark = mark + bonusmark;
		}
		
		friend void operator-=(Marks &object, int redmark);
};

void operator-=(Marks &object, int redmark){
	
	object.mark -= redmark;
}

int main()
{
	
	Marks anil(47);
	anil.yourmark();
	
	anil += 23;
	anil.yourmark();
	
	anil -= 49;
	anil.yourmark();
}
