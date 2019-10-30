#include <iostream>
#define PI (double)22/7

using namespace std;

class calculate{
	
	public:
		int high, radius;
		float volume();
		float surfacearea();
		
}cylinder;

float calculate::volume()
{

	return PI*radius*radius*high;
}

float calculate::surfacearea()
{
	
	return 2*PI*radius*(radius+high);
}

int main()
{
	
	cylinder.high = 5;
	cylinder.radius = 3;
	cout << "The volume of cylinder : " << cylinder.volume() << " and the surface area of cylinder : " << cylinder.surfacearea() << endl;	
}
