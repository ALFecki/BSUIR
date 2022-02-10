#include<iostream>
#include<vector>

using namespace std;

int main() {
	int i = 0;
	char Null = '\0';
	char String[255] = "", vowels[6] = { 'e','a','y','i','u','o' };
	char* Str;
	cout << "\nProgram will find the words, which begin and end for the vowel.\n";
	cout << "Enter your words: ";
	cin.clear();
	cin.getline(String, 255);
	Str = String;
	while (Str[i] != '\0')
	{
		if ((Str[i] == vowels[0] || Str[i] == vowels[1] || Str[i] == vowels[2] || Str[i] == vowels[3] || Str[i] == vowels[4] || Str[i] == vowels[5]) && (i == 0 ||  Str[i - 1] == ' '))
		{
			int j = i;
			while (Str[j] != ' ')
			{
				j++;
				if (Str[j] == '\0') break;
			

				
			}
			if (Str[j - 1] == vowels[0] || Str[j - 1] == vowels[1] || Str[j - 1] == vowels[2] || Str[j - 1] == vowels[3] || Str[j - 1] == vowels[4] || Str[j - 1] == vowels[5])
			{
				for ( i ; Str[i] != ' '; i++)
				{
					cout << Str[i];
					if (Str[i] == '\0') break;
				}
				cout << endl;
			}
		}
		i++;
	}


}