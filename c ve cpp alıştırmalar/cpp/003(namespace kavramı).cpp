#include <iostream>

using namespace std;

int a = 2;
namespace M
{
	
	int a = 5;
}

namespace N
{
	
	float a = 10.15;
}

int main()
{
	
	cout << a << endl;
	cout << M::a << endl;
	std::cout<<N::a<<std::endl;
	/* 23. satiri "using namespace std;" */
}
