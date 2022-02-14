#include<iostream>

using namespace std;

int main() {
	const double PI = 3.141592653589793;
	double Q, R, P, S, h;
	cout << "Enter the side of the rhombus: ";
	cin >> P;
	cout << "Enter the angle of the rhombus: ";
	cin >> Q;
	cout << "Enter the radius of the cycle: ";
	cin >> R;
	S = pow(P, 2) * sin(Q / 180 * PI);
	h = S / P;
	if (h>=2*R)
	{
		cout << "Will be able!";
	}
	else
	{
		cout << "Can not!";
	}
}