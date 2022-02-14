#include<iostream>

using namespace std;

int main() {
	
	double a, b, c, d, Z;

	cout << "Enter the numbers \n" << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	cout << "d: ";
	cin >> d;
	if (c>=d && a<d)
	{
		Z = (a + b) / c;
		cout << "Z: " << Z;
	}
	else
	{
		if (c<d && a>=d)
		{
			Z = (a - b) / c;
			cout << "Z: " << Z;
		}
		else
		{
			Z = 0;
			cout << "Z: " << Z;
		}
	} 

}