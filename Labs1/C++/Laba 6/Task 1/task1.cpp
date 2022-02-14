/*#include<iostream>

using namespace std;


int main() {
	
	int i = 0,k, numberofwords = 0;
	char string[80] = "";
	cout << "Program will find the word, which has a number k.";

	cout << "\n\nEnter your words with spaces: ";
	cin.getline(string, 80);
	cout << "\nEnter the word number: ";
	cin >> k;
	cout << "\nYour words are \"" << string << "\"" << endl;
	
	if (k == 1) // если номер слова
	{
		cout << "Word is \"";
		while (string[i] != ' ')
		{
			cout << string[i];
			i++;
		}
		cout << "\"" << endl;
	}
	else
	{
		while (string[i] != '\0')
		{
			if (string[i] == ' ')
			{
				numberofwords++;
				if (numberofwords == k)
				{
					i--;
					while (string[i] != ' ')
					{
						i--;
						if (string[i] == ' ')
						{
							break;
						}
					}
					i++;
					cout << "Word is \"";
					while (string[i] != ' ')
					{
						cout << string[i];
						i++;
					}
					cout << "\"" << endl;
					break;
				}
			}
			i++;
		}
		numberofwords++;
		if (string[i] == '\0' && numberofwords == k)
		{
			i--;
			while (string[i] != ' ')
			{
				i--;
			}
			i++;
			cout << "Word is \"";
			while (string[i] != '\0')
			{
				cout << string[i];
				i++;
			}
			cout << "\"" << endl;
			
		}
	}

}*/