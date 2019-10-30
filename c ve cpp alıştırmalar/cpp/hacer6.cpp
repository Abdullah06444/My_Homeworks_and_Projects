#include <iostream>

using namespace std;

class Vector
{
	
	int* pData;
	int dim;
	public:
		Vector (int V[], int _dim)
		{
			
			dim = _dim;
			pData = new int[dim];
			for (int i=0; i<dim; i++)
				pData[i] = V[i];
		}
		~Vector()
		{
			
			delete [] pData;
		}
		Vector (const Vector& arr)
		{
			
			this->dim = arr.dim;
			pData = new int[dim];
			for (int i=0; i<dim; i++)
				pData[i] = arr.pData[i];
		}
};

int main()
{
	
	int V[] = {1,2,3,4,5,6,7,8,9,10};
	Vector A(V,10);
	Vector B=A;
}
