#include<iostream>
#include<vector>

using namespace std;
unsigned long long Sum = 0;
unsigned long long function(unsigned long long n, long long r, unsigned long long k) {

	
	if (n == 0 && r == 0) return 1;
	else if (n > 0 && n * (k - 1) + 1 > r && r >= 0)
	{
		for (int i = 0; i <= k - 1; i++)
		{
			Sum += function(n - 1, r - i, k);
			
		}
	}
	else return 0;
	return Sum;
}


unsigned long long Summ(unsigned long long n, unsigned long long k, int t) {
	

	unsigned long long x = 0;
	for (long long i = 0; i <= n * (k - 1); i++)
	{
		x += function(n, i, k);
	}
	long long m = pow(10, t);
	return x % m;

}



int main() {

	unsigned long long n, k, x;
	int t;
	cout << "Program will find the sum of elements of recursive function.";
	while (true)
	{
		cout << " Enter k, n and t: ";
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
	x = Summ(n, k, t);
	cout << x;
}