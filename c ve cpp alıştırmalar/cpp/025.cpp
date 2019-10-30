#include <iostream>

using namespace std;

class mult{

	public:	
	float first, second;

	mult(){
		
		first = 0;
		second = 0;
	}
	mult(float x, float y){
		
		first = x;
		second = y;
	}
	mult operator*(mult);
};

mult mult::operator*(mult coor){
	
	mult variable;
	variable.first = first * coor.first;
	variable.second = second * coor.second;
	return variable;
}

int main()
{
	
	mult m(2,5);
	mult n(7,3);
	mult result;
	
	result = m*n;
	
	cout << "first value is " << result.first << endl;
	cout << "second value is " << result.second << endl;
}
