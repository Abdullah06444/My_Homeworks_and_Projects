#include<iostream>

using namespace std;

struct Address
{
	
	char HouseNo[25];
	char City[25];
    char PinCode[25];
};

struct Employee
{
    
	int Id;
    char Name[25];
    float Salary;
    struct Address Add;
};

int main()
{

	int i;
	Employee E;

	cout << "\n\tEnter Employee Id : ";
	cin >> E.Id;

    cout << "\n\tEnter Employee Name : ";
    cin >> E.Name;

    cout << "\n\tEnter Employee Salary : ";
    cin >> E.Salary;

    cout << "\n\tEnter Employee House No : ";
    cin >> E.Add.HouseNo;

    cout << "\n\tEnter Employee City : ";
    cin >> E.Add.City;

    cout << "\n\tEnter Employee House No : ";
    cin >> E.Add.PinCode;

    cout << "\nDetails of Employees";
    cout << "\n\tEmployee Id : " << E.Id;
    cout << "\n\tEmployee Name : " << E.Name;
    cout << "\n\tEmployee Salary : " << E.Salary;
    cout << "\n\tEmployee House No : " << E.Add.HouseNo;
    cout << "\n\tEmployee City : " << E.Add.City;
    cout << "\n\tEmployee House No : " << E.Add.PinCode;

}
