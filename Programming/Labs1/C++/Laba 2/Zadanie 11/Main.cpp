#include<iostream>

using namespace std;


int main() {
	const double PI = 3.141592653589793;
	double a, r,S1, S2;
	cout << "Enter the side of square: ";
	cin >> a;
	cout << "Enter the radius: ";
	cin >> r;
	S1 = pow(a, 2);
	S2 = PI * pow(r, 2);
	if (S1>S2)
	{
		cout << "The area of the square is greater than the area of the circle" << endl;
	}
	else
	{
		if (S2>S1)
		{

			cout << "The area of the cycle is greater than the area of the square ";
		}
		else
		{
			cout << "The areas are equal";
		}
	}


}