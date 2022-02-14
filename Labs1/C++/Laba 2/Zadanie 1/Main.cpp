#include<iostream>

using namespace std;

int main() {

	int x, y;
	cout << "Enter the number: " << endl << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;

	if (x % y  == 0 || y % x == 0)
	{
		cout << "True!";
	}
	else
	{
		cout << "False!";
	}



}