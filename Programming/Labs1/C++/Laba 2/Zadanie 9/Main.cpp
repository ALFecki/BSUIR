#include<iostream>

using namespace std;

void main() {

	int x, y, z;
	cout << "Enter	the sides of triangle: \n";
	cin >> x >> y >> z;
	if ( y + z <=x || x + z <= y || y + x <= z)
	{
		cout << "The triangle does not exist !";

	}
	else
	{
		cout << "The triangle exists!";
	}


}