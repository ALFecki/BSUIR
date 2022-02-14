#include<iostream>


using namespace std;

int main() {
	int N = 8, i, k;
	int** a = new int* [N];
	for (i = 0; i < N; i++)
	{
		a[i] = new int[N];
	}
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < N; k++)
		{
			if (i == k || abs(i - k) == (N / 2) || i + k == 11 || i + k == N - 1 || i + k == (N / 2 - 1))
			{
				a[i][k] = 0;
			}
			else
			{
				a[i][k] = 1;
			}
		}
	}
	int l = 1;
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < N; k++)
		{
			if (a[i][k] == 1)
			{
				a[i][k] = l;
				l++;
			}
			else l++;

		}
	}
	l = 1;
	for (i = N - 1; i >= 0; i--)
	{
		for (k = N - 1; k >= 0; k--)
		{
			if (a[i][k] == 0)
			{
				a[i][k] = l;
				l++;
			}
			else l++;

		}

	}
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < N; k++)
		{
			cout << "\t" << a[i][k];
		}
		cout << endl;
	}

}