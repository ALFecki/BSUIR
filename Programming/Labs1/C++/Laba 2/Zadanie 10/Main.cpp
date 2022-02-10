#include<iostream>

using namespace std;

int main() {
	const double PI = 3.1415926535;
	double x, a, b, c;
	cout << "Enter x: ";
	cin >> x;
	a = sin(x);
	b = cos(x);
	c = log(abs(x));
	if (x >= 0 && x < b)
	{
		cout << "The smallest is ln(|x|)" << endl;
	}
	else
	{
		if (x > (-3 * PI) / 4 && x < PI / 4)
		{
			cout << "The smallest is sin(x)" << endl;
		}
		else
		{
			if (x > PI/4 && x < (5*PI)/4)
			{
				cout << "The smallest is cos(x)" << endl;
			}
			else
			{
				if (a = b)
				{
					cout << "sin(x) = cos(x) = min";
				}
			}


		}
	}




}