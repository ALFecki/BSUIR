#include<iostream>


using namespace std;
long long Sum = 0;
long long i = 0;

long long function(long long n, long long k, long long r) {
	
	if (n == 0 && r == 0) return 1;
	else if (r >= 0 && n * (k - 1) + 1 > r)
	{
		while (i <= (k - 1))
		{
			Sum += function(n - 1, k, r - i);
			i++;
			cout << Sum << endl;
		}
		return Sum;
	}
		
	else return 0;


}

int main() {
	long long k, n, x = 0;
	int t;
	cout << "Program will find the sum of elements of recursive function.";
	
	while (true)
	{
		cout << "\n\nEnter k, n and t: ";
		cin >> k >> n >> t;
		if (cin.fail() || k < 0 || n < 0 || t < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.";
			continue;
		}
		else break;
	}
	if (k == 0 && n == 0 && t == 0) return 0;
	for (long long i = 0; i < n * (k - 1); i++)
	{	
		
		x += function(n, k, i);
	}
	cout << "\nThe Sum is " << x << endl;
}