#include<iostream>

using namespace std;

int main() {

	int i = 0, k, numberofwords = 0;
	char string[80] = "";
	cout << "Program will find the word, which has a number k.";

	cout << "\n\nEnter your words with spaces: ";
	cin.getline(string, 80);
	cout << "\nEnter the word number: ";
	cin >> k;
	cout << "\nYour words are \"" << string << "\"" << endl;

	while (string[i] != '\0')
	{
		if (i == k)
		{
			cout << "The number of the word is " << numberofwords + 1 << endl;
			i--;
			if (numberofwords == 0) // если номер слова 0
			{
				cout << "Word is \"";
				while (i != 0)
				{
					i--;
				}
				while (string[i] != ' ')
				{
					cout << string[i];
					i++;
				}
				cout << "\"" << endl;
			}
			else
			{
				while (string[i] != ' ' || i != 0)
				{
					i--;
				}
				i++;
				cout << "Word is \"";
				while (string[i] != ' ')
				{
					if (string[i] == '\0') break;
					cout << string[i];
					i++;
					
				}
				cout << "\"" << endl;
			}
		}
		if (string[i] == ' ')
		{
			numberofwords++;	
		}
		i++;
	}
	cout << "This index isn't in string" << endl;
}

