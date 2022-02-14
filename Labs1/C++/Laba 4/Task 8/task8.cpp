#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> a;
	vector<int> b;
	int N, i, maxi = 0, mini = 0, max, min, l = 0, g = 0;
	cout << "Program will replace all elenents for 0, which are between max and min of the array.";
	while (bool f = true)
	{
		cout << "\n\nEnter the number of elements: ";
		cin >> N;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.";
			continue;
		}
		else
		{
			if (N < 0)
			{
				cout << "\nIncorrect input. Try again.";
				continue;
			}
			else break;
		}
	}
	a.resize(N);
	cout << "\nEnter the array, please\n\n"; // ввод массива
	for ( i = 0; i < N; i++)
	{
		while (bool f = true)
		{
			cout << "Enter a[" << i << "]";
			cin >> a[i];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\nIncorrect input. Try again.";
				continue;
			}
			else break;
		}
	}
	cout << "\nYour array:\n\t"; // вывод массива
	for ( i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	max = a[0];
	min = max;
	for ( i = 0; i < N; i++) // нахождение максимума и минимума
	{
		if (a[i] > max)
		{
			max = a[i];
			maxi = i;
		}
		if (a[i] < min)
		{
			min = a[i];
			mini = i;
		}
	}
	if (maxi > mini && (maxi - mini) > 1)
	{
		for ( i = mini + 1 ; i < maxi; i++)
		{
			a[i] = 0;
			g++;
		}
	}
	else
	{
		if (maxi < mini && (mini - maxi) > 1)
		{
			for ( i = maxi + 1; i < mini; i++)
			{
				a[i] = 0;
				g++;
			}
		}
	}
	int k = abs(maxi - mini);
	b.resize(k);
	if (g > N / 2)
	{
		k = 0;
		for (i = 0; i < N; i++)
		{
			if (a[i] == 0)
			{
				continue;
			}
			else
			{
				b[k] = a[i];
				k++;
			}
		}
		int k1 = k;
		cout << "\n\nNew array is:\n\n\t";
		for ( k = 0; k < k1 ; k++)
		{
			cout << b[k] << " ";
		}

	}
	else
	{
		cout << "\n\nNew array is:\n\n\t";
		for ( i = 0; i < N; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
}