#include<iostream>
#include<string>


using namespace std;


int main() {

	string String1, String2;
	long long Length, Module, NumberOfStrings;
	int NumberOfSolutions, t = 1, count = 1;
	cout << "\nProgram will count the number of strings with it's prefixx and suffixx.\n";
	while (true)
	{
		cout << "Enter the number of actions: ";
		cin >> NumberOfSolutions;
		if (cin.fail() || NumberOfSolutions < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else break;
	}
	while (t <= NumberOfSolutions)
	{
		while (true)
		{
			cout << "\nEnter the length of string S and Module: ";
			cin >> Length >> Module;
			if (cin.fail() || Length < 0 || Module < 0)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\nIncorrect input. Try again.\n";
				continue;
			}
			else
			{
				cin.ignore();
				break;
			}
		}
		
		cout << "Enter String1: ";
		
		getline(cin, String1);
		cout << "Enter String2: ";
		getline(cin, String2);
		if (String1.size() + String2.size() < Length)
		{
			NumberOfStrings = pow(26, Length - String1.size() - String2.size()) * 2;
			cout << NumberOfStrings % Module << endl;
		}
		else if (String1.size() + String2.size() > Length)
		{
			
			for (int i = 0; i < String1.size(); i++)
			{
				for (int j = 0; j < String2.size(); j++)
				{
					if (String1[i] == String2[j] && String1[i + 1] != String2[j + 1]) continue;
					else if (String1[i] == String2[j]) count++;
				}
			}
			if (count == 1)
			{
				cout << 0 << endl;
				t++;
				continue;
			}
			int Empty = Length - String1.size() - String2.size() + count;
			if (Empty > 0)
			{
				NumberOfStrings = pow(26, Empty) * 2;
				cout << NumberOfStrings % Module << endl;
			}
			else if (Empty == 0) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (String1.size() + String2.size() == Length)
		{
			cout << 2 << endl;
		}
		String1.clear();
		String2.clear();
		t++;
	}

}