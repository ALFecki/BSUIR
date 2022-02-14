#include<iostream>
#include<vector>
#include "staticlib.h"

using namespace std;

int main() {
	int n;
	vector<double> x;
	vector<double> y;
	vector<double> z;
	cout << "Program will make a new array, from your 2 arrays and one variable.\n\n";
	cout << "Enter the number of members: ";
	while (true)
	{
		cin >> n;
		if (cin.fail() || n < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.";
			continue;
		}
		else break;
	}
	x.resize(n);
	y.resize(n);
	z.resize(n);
	cout << "Enter the array X: ";
	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			
			cin >> x[i];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Incorrect input. Try again.\nEnter the array X: ";
				continue;
			}
			else break;
		}
	}
	cout << "Enter the array Y: ";
	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			cin >> y[i];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Incorrect input. Try again.\nEnter the array Y: ";
				continue;
			}
			else break;
		}
	}
	
	z = cases(n, x, y);
	printarray(n, x);
	printarray(n, y);
	printarray(n, z);
}