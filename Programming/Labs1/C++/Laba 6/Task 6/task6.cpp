#include<iostream>
#include<string>
#include<map>

using namespace std;

long long factorial(long long N) {
	if (N > 1)
	{
		N *= factorial(N - 1);
		return N;
	}
	return 1;
	
}


int main() {
	int i = 0, j = 1, k = 0;
	map <char, int> numberofletters;
	map <char, int> ::iterator it;
	bool t = true;
	char word[14] = "";
	cout << "Program will count the number of anagramms.\n";
	while (t)
	{
		cout << "Enter your word: ";
		cin >> word;
		while (word[i] != '\0')
		{
			if (word[i] == '0' || word[i] == '1' || word[i] == '2' || word[i] == '3' || word[i] == '4' || word[i] == '5' || word[i] == '6' || word[i] == '7' || word[i] == '8' || word[i] == '9')
			{
				cout << "Incorrect input. Try again.";
				break;
			}
			else
			{
				t = false;
				break;
			}
			i++;
		}
	}
	for ( i = 0; word[i] != '\0'; i++)
	{
		it = numberofletters.find(word[i]);
		if (it == numberofletters.end())
		{
			numberofletters.insert(make_pair(word[i], j));
		}
		else
		{
			it->second++;
		}
	}
	
	it = numberofletters.begin();
	for ( i = 0; it != numberofletters.end() ; it++, i++)
	{
		if (it->second == 1) continue;
		else k += it->second;
		//cout << endl << "Letters " << it->first << " are " << it->second << endl;
	}
	
	long long fact = factorial(strlen(word))/factorial(k);
	cout << "The number of anagramms is " << fact << endl;

}