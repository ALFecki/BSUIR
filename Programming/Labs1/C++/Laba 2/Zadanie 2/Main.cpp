#include<iostream>

using namespace std;

int main() {
	
	int X, Y;
	double A, B, C, K;

	cout << "Enter the number \n" << "X: ";
	cin >> X;
	cout << "Y: ";
	cin >> Y;
	cout << "A: ";
	cin >> A;
	cout << "B: ";
	cin >> B;
	cout << "C: ";
	cin >> C;
	cout << "K: ";
	cin >> K;
	if (X > Y)
	{
		Y = 0;
		cout << X << " " << Y << endl;
	}
	else
	{
		if (Y > X)
		{
			X = 0;
			cout << X << " " << Y << endl;
		}
		else
		{
			X = 0;
			Y = 0;
			cout << X << " " << Y << endl;
		}
	}
	if (A > B && A > C)
	{
		A = A - K;
		cout << A << " " << B << " " << C;
	}
	else
	{
		if (B > A && B > C)
		{
			B = B - K;
			cout << A << " " << B << " " << C;

		}
		else
		{
			if (C>A && C>B)
			{
				C = C - K;
				cout << A << " " << B << " " << C;
			}
		}


	}
}