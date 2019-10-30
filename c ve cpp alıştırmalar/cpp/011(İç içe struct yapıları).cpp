// Nested Structure
#include <iostream>

using namespace std;

struct who{
	
	string name;
	
	struct where{
	
		string country;
		string city;
	}place = {"The USA", "Chicago"};
}people;

int main()
{
	
	cin >> people.name;
	
	cout << people.name << " " << people.place.country << " " << people.place.city << endl;
}
