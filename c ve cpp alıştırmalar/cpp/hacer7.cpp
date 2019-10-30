#include <iostream>
using namespace std;

class Rectangle{
	
	public:
		float upper_x;
		float upper_y;
		float width;
		float height;

		Rectangle(float a, float b, float w, float h)
		{
			
			upper_x = a;
			upper_y = b;
			width = w;
			height = h;
		}
		Rectangle()
		{
			
			upper_x = 0;
			upper_y = 0;
			width = 0;
			height = 0;
		}
		Rectangle operator+()
		{
			
			
		}
		void operator=()
		{
			
			Rectangle x;
			float b = &x;
		}
};

int main()
{
	
	Rectangle value(7,4,4,3);	// (11,1)
	Rectangle value2(4,5,2,5);	// (6,10)
	
	Rectangle result;

}
