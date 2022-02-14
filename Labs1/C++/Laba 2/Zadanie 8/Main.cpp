#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int x, y, z, a, b, f, desicion;
	cout << "Enter z: ";
	cin >> z;
	cout << "Enter coefficients: ";
	cin >> a >> b;
	cout << "Choose the argument:\n" << "2x - 1\n" << "x^3 - 2\n" << "x/3 -3" << endl;
	cin >> desicion;
	if (z>0)
	{
		x = 1 / (pow(z, 2) + 2 * z);
	}
	else
	{
		x = 1 - pow(z, 3);

	}
	switch (desicion)
	{
	case 1:
		x *= 2;
			
		break;
	
	case 2:
		x = pow(x, 3);
		
		break;

	case 3:
		x /= 3;
		
		break;
	}
	y = (2.5 * a * pow(M_E, -3 * x) - 4 * b * pow(x, 2)) / (log(abs(x)) + x);
	
	cout << "Y is " << y;



}