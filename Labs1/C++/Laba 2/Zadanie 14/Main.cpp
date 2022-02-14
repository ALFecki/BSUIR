#include<iostream>

using namespace std;

int main() {
	double a, b, c, x, y;
	cout << "Enter the sides of brick: ";
	cin >> a >> b >> c;
	cout << "Enter hole dimensions: ";
	cin >> x >> y;
	if (a * b <= x * y || a * c <= x * y || b * c <= x * y)
	{
		cout << "Yes.";		 
	} 
	else
	{
		cout << "No.";
	}

}