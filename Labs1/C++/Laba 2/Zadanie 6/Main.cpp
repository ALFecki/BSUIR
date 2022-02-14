#include<iostream>

using namespace std;

int main() {

	double a, b, c,Y;
	int N;
	cout << "Enter the numbers \n" << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	cout << "N: ";
	cin >> N;

	switch (N)
	{
	case 2:
		Y = b * c - pow(a, 2);
		cout << Y;
		break;
	case 56:
		Y = b * c;
		cout << Y;
		break;
	case 7:
		Y = pow(a, 2) + c;
		cout << Y;
		break;
	case 3:
		Y = a - b * c;
		cout << Y;
		break;

	default:
		Y = pow(a + b, 3);
		cout << Y;
		break;
	}

}