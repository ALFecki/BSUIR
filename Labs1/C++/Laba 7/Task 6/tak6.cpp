#include <iostream>

using namespace std;

int main() {
	long long Number;
	int NumberOfSolutions;
	while (true)
	{
		cout << "\nEnter the number of solutions: ";
		cin >> NumberOfSolutions;
		if (cin.fail() || NumberOfSolutions <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else break;
	}
	int t = 0;
	while (t < NumberOfSolutions)
	{
		while (true)
		{
			cout << "\nEnter your number: ";
			cin >> Number;
			if (cin.fail() || Number <= 0)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\nIncorrect input. Try again.\n";
				continue;
			}
			else break;
		}
		if (Number % 10 == 9) cout << "\nCount of \"interesting\" X is " << Number / 10 + 1 << endl; // проверка на "интересное число"
		else cout << "\nCount of \"interesting\" X is " << Number / 10 << endl;
		t++;
	}
}
