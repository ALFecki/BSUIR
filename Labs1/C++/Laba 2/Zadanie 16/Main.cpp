#include<iostream>

using namespace std;

int main() {
	int a, b,c,GCD,LCM;
	cout << "Enter the numbers: \n" << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	c = b;
	if (a>b)
	{
		while (a % b != 0)
		{
			b = a % b;
		}

	}
	else
	{
		while (a % b != 0)
		{
			a = b % a;
		}
	}
	GCD = b;
	LCM = a * c / GCD;
	cout << "GCD is " << GCD << endl << "LCM is " << LCM << endl;
	
}