#include<iostream>
#include<string>

using namespace std;

int main() {


	string String, NewString, CopyString, NewestString;
	cout << "\nProgram will show the length of maximum not-palindrom string.\n";
	
	cout << "\n\nEnter your string: ";
	getline(cin, String);
	for (int i = String.size() - 1; i >= 0; i--)
	{
		NewString.push_back(String[i]);
	}
	NewestString = NewString;
	CopyString = String;
	
	while (String == NewString)
	{
		String.erase(String.size() - 1, 1);
		NewString.erase(0, 1);
	}
	if (String != NewString)
	{
		cout << "\nThe length is " << String.size() << endl << endl;
	}
	else
	{
		while (CopyString == NewestString)
		{
			CopyString.erase(0, 1);
			NewestString.erase(NewestString.size() - 1, 1);
		}
		if (CopyString != NewestString)
		{
			cout << "\nThe length is " << String.size() << endl << endl;
		}
		else cout << 0 << endl;
	}
}