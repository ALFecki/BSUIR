#include<iostream>
#include<string>
using namespace std;

string MakeRomanNumber(long long a, long long b, long long c, long long d, long long e, long long f, long long g) {
	string RomanNumber;
	int Th = 0, H5 = 0, H = 0, T5 = 0, T = 0, U5 = 0, U = 0;
	for (; Th < g; Th++) RomanNumber.push_back('M');
	if (f * 500 + e == 900) // проверка на 900
	{
		RomanNumber.push_back('M');
		RomanNumber.push_back('C');
	}
	else if (e == 4) // проверка на 4
	{
		RomanNumber.push_back('C');
		RomanNumber.push_back('D');
	}
	else
	{
		for (; H5 < f; H5++) RomanNumber.push_back('D');
		for (; H < e; H++) RomanNumber.push_back('C');
	}
	if (c + d * 50 == 90) //проверка на 90
	{
		RomanNumber.push_back('C');
		RomanNumber.push_back('X');

	}
	else if(c == 4)
	{
		RomanNumber.push_back('X');
		RomanNumber.push_back('L');
	}
	else
	{
		for (; T5 < d; T5++) RomanNumber.push_back('L');
		for (; T < c; T++) RomanNumber.push_back('X');

	}
	if (a + b * 5 == 9) // проверка на 9
	{
		RomanNumber.push_back('I');
		RomanNumber.push_back('X');
	}
	else if (a == 4)
	{
		RomanNumber.push_back('I');
		RomanNumber.push_back('V');
	}
	else
	{
		for (; U5 < b; U5++) RomanNumber.push_back('V');
		for (; U < a; U++) RomanNumber.push_back('I');
	}
	return RomanNumber;
}

int main() {


	cout << "\nProgram will convert numbers from arabian to the roman numbers.";
	long long ArabNumber;
	while (true)
	{
		cout << "\n\nEnter your number: ";
		cin >> ArabNumber;
		if (cin.fail() || ArabNumber <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else break;
	}
	long long NumberOfThousands, NumberOf5Hundred, NumberOfHundred, NumberOf5Tens, NumberOfTens, NumberOf5, NumberOfUnits;
	NumberOfThousands = ArabNumber / 1000; // кол-во 1000
	ArabNumber -= 1000 * NumberOfThousands;
	NumberOf5Hundred = ArabNumber / 500; // кол-во 500
	ArabNumber -= 500 * NumberOf5Hundred;
	NumberOfHundred = ArabNumber / 100; // кол-во 100
	ArabNumber -= 100 * NumberOfHundred;
	NumberOf5Tens = ArabNumber / 50; // кол-во 50
	ArabNumber -= 50 * NumberOf5Tens;
	NumberOfTens = ArabNumber / 10; // кол-во 10
	ArabNumber -= 10 * NumberOfTens;
	NumberOf5 = ArabNumber / 5; // кол-во 5
	ArabNumber -= 5 * NumberOf5;
	NumberOfUnits = ArabNumber; // кол-во единиц
	string RomanNumber = MakeRomanNumber(NumberOfUnits, NumberOf5, NumberOfTens, NumberOf5Tens, NumberOfHundred, NumberOf5Hundred, NumberOfThousands);
	cout << "\nRoman number is " << RomanNumber << endl;
}
