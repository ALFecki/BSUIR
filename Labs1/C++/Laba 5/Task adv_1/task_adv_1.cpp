#include<iostream>

using namespace std;

int F(int n) {
	if (n % 10 > 0) return (n % 10);
	
	else if (n == 0) return 0;
	
	else F(n / 10);
}

int S(int p, int q) {

	int S = 0;
	for ( int i = p; i <= q; i++)
	{
		S += F(i);
	}
	return S;
}


int main() {
	int p, q, Sum;
	cout << "Program will find a sum of the recursive function.";
	while (true)
	{
		cout << "\n\nEnter the start and finish indicies: ";
		cin >> p >> q;
		if (cin.fail() || p > q)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.";
			continue;
		}
		else break;
	}
	if (p < 0 || q < 0 || p == q)
	{
		return 0;
	}
	
	Sum = S(p, q);
	cout << "The sum is " << Sum << endl;
}