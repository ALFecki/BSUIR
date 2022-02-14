#include<iostream>
#include<string>


using namespace std;

int main() {
	string OriginalNumber;

	cout << "Program will translate from 14-th notation to 6-th notation.\n";
	cout << "Enter your number: ";
	getline(cin, OriginalNumber);
	long long Number10 = 0, Rank;
	for (int i = 0, l = OriginalNumber.length() - 1; i < OriginalNumber.length(); i++, l--)
	{
		if (OriginalNumber[l] == 'A') Rank = 10; // присваивание численных значений символам 
		else if (OriginalNumber[l] == 'B') Rank = 11;
		else if (OriginalNumber[l] == 'C') Rank = 12;
		else if (OriginalNumber[l] == 'D') Rank = 13;
		else Rank = OriginalNumber[l] - '0';
		Number10 += Rank * pow(14, i);
	}
	string NewNumber;
	while (Number10 >= 6)
	{
		NewNumber.push_back(Number10 % 6 + '0'); // перевод в 6-ричную СС
		Number10 /= 6;
	}
	NewNumber.push_back(Number10 + '0');
	string Number6;
	for (int i = NewNumber.length() - 1; i >= 0; i--) Number6.push_back(NewNumber[i]);
	cout << "New number is " << Number6 << endl;

}
