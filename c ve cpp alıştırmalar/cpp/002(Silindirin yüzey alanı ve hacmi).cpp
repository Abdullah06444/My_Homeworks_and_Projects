#include <iostream>
#define PI 3.14
#define Feet 30.48
using namespace std;

int main()
{
	float radius, high;
	float result, result2;
	cout << "Write the radius of cylinder: ";
	cin >> radius;
	cout << "Write the high of cyclinder: ";
	cin >> high;
	
	result  = 2*PI*radius*(high + radius);
	result2 = PI*radius*radius*high;
	
	cout << "The surface area of cylinder is " << result << " meters^2 and " << result / Feet << " feets^2." << endl;
	cout << "The volume of cylinder is " << result2 << " meters^3 and " << result2 / Feet << " feets^3.\n";
	
	return 0;
}
