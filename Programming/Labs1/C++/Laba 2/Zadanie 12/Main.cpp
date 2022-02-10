#include<iostream>

using namespace std;

int main() {
	int x1, y1, x2, y2, r, R, L;
	cout << "Enter the coordinates of the center of the first circle: ";
	cin >> x1 >> y1;
	cout << "Enter the radius of the first cycle: ";
	cin >> r;
	cout << "Enter the coordinates of the center of the second circle: ";
	cin >> x2 >> y2;
	cout << "Enter the radius of the second cycle: ";
	cin >> R;
	L = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	if (L<r+R)
	{
		cout << "Yes.\n";
	}
	else
	{
		if (L==r+R)
		{
			cout << "Shapes intersect.\n";
		}
		else
		{
			cout << "None of the conditions are right.\n";
		}
	
	}
	
}