#include<iostream>

using namespace std;

int main() {
	double N1;
	int N, M, i, k, l = 1, k1, i1;
	cout << "\nProgram will make the matrix of integers, which are arrainged in special algorithm. And will show position of ypur number.";
	while (true)
	{
		cout << "\n\nEnter you number: ";
		cin >> N;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\n\nIncorrect input. Try again.";
			continue;
		}
		else break;
	}
	N1 = sqrt(N);
	for ( i = 0; i < 10000; i++)
	{
		if (N < pow(i,2))
		{
			M = i;
			break;
		}
		else
		{
			if (N == pow(i,2))
			{
				M = i;
				break;
			}
		}
	}
	int** a = new int* [M];
	for (i = 0; i < M; i++)
	{
		a[i] = new int[M];
	}
	for ( i = 0; i < M; i++)
	{
		for ( k = 0; k < M; k++)
		{
			a[i][k] = 0;
		}
	}
	a[0][0] = l;
	l++;
	i = 0;
	k = 1;
	while (l <= pow(M,2))
	{
		if (l == N)
		{
			i1 = i;
			k1 = k;
		}
		if (k - 1 < 0)
		{
			a[i][k] = l;
			l++;
			i = 0;
			while (a[i][k] > 0)
			{
				k++;
			}

		}
		else
		{
			if (a[i][k - 1] > 0)
			{
				a[i][k] = l;
				l++;
				i++;
			}
			else
			{
				if (a[i][k - 1] == 0)
				{
					a[i][k] = l;
					l++;
					k--;
				}
			}
		}
	}
	cout << "\n\nMatrix:\n\n";
	for (i = 0; i < M; i++)
	{
		for (k = 0; k < M; k++)
		{
			cout << "\t" << a[i][k];
		}
		cout << endl;
	}
	cout << "\n\nYour number coordinates is the line number " << i1 + 1 << " and column number " << k1 + 1 << endl << endl;
	
}