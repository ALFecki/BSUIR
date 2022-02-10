#include<iostream>

using namespace std;

int main() {
	bool f = true;
	double d = 0, n, i = 0;
	while (f)
	{
		cout << "Enter the number of members: ";

		cin >> n;
		if (cin.fail()) // проверка на наличие букв во входных данных
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (n < 0)
			{
				cout << "Incorrect input. Try again.\n";
			}
			else
			{
				f = false;
			}
		}
	}
	

	if (n >= 0)
	{
		do
		{
			d += pow((pow(2, -1)), n) + pow((pow(3, -1)), n);
			i++;

		} while (i <= n);
		/*/for (; i <= n; ++)
		{
			d += pow((pow(2, -1)), n) + pow((pow(3, -1)), n);
		}*/
	}	
	else
	{
		do
		{
			d += pow((pow(2, -1)), n) + pow((pow(3, -1)), n);
			i--;

		} while (i >= n);
	}
	cout << "The result is " << d;
}