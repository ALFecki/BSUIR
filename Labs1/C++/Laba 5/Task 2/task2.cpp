#include<iostream>
#include<vector>
#include "Functions.h"

using namespace std;
vector<int> ArrayInput(int N) {
	vector<int> a;
	a.resize(N);
	for (int i = 0; i < N; i++)
	{
		while (true)
		{
			cout << "Enter A[" << i + 1 << "]: ";
			cin >> a[i];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Incorrect input. Try again.";
				continue;
			}
			else break;
		}
	}
	return a;
}

int main() {

	vector<int> A;
	int N;

	cout << "This program will find the maximum of the array with recursive function.";

	while (true)
	{
		cout << "\n\nEnter the number of members: ";
		cin >> N;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.";
			continue;
		}
		else if (N % 3 != 0)
		{
			cout << "Incorrect input. The number of members need to be multiple of 3.";
		}
		else break;
	}
	A.resize(N);
	A = ArrayInput(N);

	int max, max1, MaxAll;
	for (int i = 0; i < N / 3 - 1; i++)
	{
		max = function(A[i], A[i + 1]);
	}

	for (int i = N / 3; i < N - N / 3 - 1; i++)
	{
		max1 = function(A[i], A[i + 1]);
	}
	MaxAll = function(max, max1);
	cout << MaxAll << endl;



}