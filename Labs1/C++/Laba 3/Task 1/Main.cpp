#include<iostream>

using namespace std;

int main() {
	
	int N = 0, a, b, i = 1;
	while (i <= 30)
	{
		if (i % 2 == 0)
		{
			a = i / 2;
			b = pow(i, 3);
		}
		else
		{
			a = i;
			b = pow(i, 2);
		}
		N += pow(a - b, 2);
		i++;
	
	}
	cout << "a = i, when i is odd\na = i/2, when i is even\n";
	cout << "b = i^2, when is odd\nb = i^3, when i is even\n";
	cout << "Row is (a[i]-b[i])^2\n";
	cout << "Sum of 30 members of the row is " <<  N;


}