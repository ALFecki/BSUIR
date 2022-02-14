#include<iostream>

using namespace std;

long long MaxDivider(long long n) {
	long long Divider = 1;
	for (long long i = n; i > 0; i--)
	{
		if (n % i == 0 && (i % 2 != 0))
		{
			Divider = i;
			break;
		}
	}
	return Divider;
}

long long Summ(int Divider) {
	long long Sum = 0;
	for (long long i = 1; i <= Divider; i++)
	{
		Sum += MaxDivider(i);
	}
	return Sum;

}


int main() {

	long long n, Sum;

	cout << "Program will find for all numbers from 1 to maximum odd divider of n.";
	while (true)
	{
		cout << "\n\nEnter n: ";
		cin >> n;
		if (cin.fail() || n <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.";
			continue;
		}
		else break;
	}
	Sum = Summ(n);
	cout << "\nThe sum is " << Sum << endl;
}