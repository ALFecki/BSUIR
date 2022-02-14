#include<iostream>

using namespace std;

int main() {
	cout << "Program will count the number of members of array, which are less or more than average value of all elements by no more than 3.\n\n";
	int i = 0, n = 0;
	double  S = 0;
	const int k = 10;
	double a[k]{ 0 };
	cout << "Enter the elements of array, please.\n\n";
	for ( ;  i < k;  i++)
	{
		while (true)
		{
			cout << "Enter a" << i << ": ";
			cin >> a[i];
			if (cin.fail()) 
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Incorrect input. Try again.\n";
				continue;
			}
			else
			{
				break;
			}
		
		}
		S += a[i] / k;
	} 
	i = 0;
	cout << "\nArray is ";
	for ( ; i < k; i++)
	{
		cout << a[i] << " ";
		if (abs(S - a[i]) <= 3 || abs(a[i] - S) <= 3)
		{
			n++;
		}
		else continue;
	}


	cout << "\n\nThe number of this elements is " << n << endl;

}