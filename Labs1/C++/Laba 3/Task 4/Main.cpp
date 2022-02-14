#include<iostream>

using namespace std;

int main() {
	bool f = true;
	int a1 = 2, a, S, n = 0;
	while (f)
	{
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
	
	if (a % 2 == 0)
	{
			n = a / 2;
	}
	else
	{
			a--;
			n = a / 2;
	}
	
	S = (a1 + a) * n / 2;
	cout << "Sum is " << S << endl;

}