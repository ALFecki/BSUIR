#include<iostream>
#include<string>

using namespace std;

int main() {

	int NumberOfSolutions, t = 1, Length, i = 0;
	string OriginalString, NewString, OneMoreString, ReverseString;

	cout << "\nProgram will tell you, can we make String2 of the String1.\n";
	while (true)
	{
		cout << "Enter the number of solutions: ";
		cin >> NumberOfSolutions;
		if (cin.fail() || NumberOfSolutions < 0)
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
	while (t <= NumberOfSolutions)
	{
		cout << "Enter your string: ";
		
		getline(cin, OriginalString);
		cout << "Enter new string: ";
		
		getline(cin, NewString);
		Length = OriginalString.size();
		int Length1 = Length, Length2 = Length, k = 1;
		for (int i = 0, j = Length - 2; i < Length - 1; i++, j--)
		{
			ReverseString.push_back(OriginalString[j]);
		}
		string ReverseStringCopy = ReverseString, OriginalStringCopy = OriginalString;
		OneMoreString = OriginalString + ReverseString;
		if (OneMoreString == NewString)
		{
			cout << endl << "YES" << endl;
			t++;
			OriginalString.clear();
			ReverseString.clear();
			NewString.clear();
			OriginalStringCopy.clear();
			ReverseStringCopy.clear();
			OneMoreString.clear();
			continue;
		}
		for (int i = 0; i < Length; i++)
		{
			ReverseString = ReverseStringCopy;
			Length2 = Length;
			
			for (; !OriginalString.empty();)
			{
				OneMoreString = OriginalString + ReverseString;
				for (int k = 0; k != OriginalString.size(); k++)
				{
					OneMoreString.erase(OneMoreString.size() - 1);
					if (OneMoreString == NewString)
					{
						cout << endl << "YES" << endl;
						break;
					}

				}
				if (OneMoreString == NewString) break;
				
				OriginalString.erase(OriginalString.size() - 1);
				ReverseString.erase(0, 1);
			}
			if (OneMoreString == NewString) break;
			OriginalString = OriginalStringCopy.erase(0,1);
			if (OriginalString.size() == 1) continue;
			else OriginalString.erase(0, 1);

		}
		if (OneMoreString != NewString) cout << endl << "NO" << endl;
		OriginalString.clear();
		ReverseString.clear();
		NewString.clear();
		OriginalStringCopy.clear();
		ReverseStringCopy.clear();
		OneMoreString.clear();
		t++;
	}

}