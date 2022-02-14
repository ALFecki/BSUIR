#include<iostream>

using namespace std;

int main() {

	int a, S = 0, i = 1;
	bool f = true;
	while (f)
	{
		cout << "You need to enter the last number, programm will find the sum of even numbers from 1 to your number.\n";
		cout << "Enter the last number: ";
		cin >> a;
		if (cin.fail()) // проверка на наличие букв во входных данных
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (a < 0)
			{
				cout << "Incorrect input. Try again.\n";
			}
			else
			{
				f = false;
			}
		}
	}
	while (i <= a)
	{
		if (i % 2 == 0)
		{
			S += i;
			i++;
		}
		else
		{
			i++;
		}
	}
	cout << "Sum is " << S << endl;



}