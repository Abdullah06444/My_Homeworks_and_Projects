#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	
	char c;
	char text[] = "this is an example";
	
	for (int i=0; i<strlen(text); i++)
	{
		
		if(text[i]>='a' && text[i]<='z' && text[i] != 'a' && text[i] != 'e' && text[i] != 'i')
		{
			
			text[i] = text[i] - 'a' + 'A';
		}
	}
	
	cout << text << endl;
	
	int x;
	
	cout << (x=5) << endl;
	cout << (x++<=5) << endl;
	cout << (x>5) << endl;
	cout << (x=0) << endl;
	cout << ((x || 5) && !x) << endl;
}
