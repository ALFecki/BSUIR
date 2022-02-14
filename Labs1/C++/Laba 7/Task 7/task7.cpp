#include<iostream>

using namespace std;

// Вариант 11

int Addition(int FirstNumber, int SecondNumber) // побитовое сложение
{
	int Result = FirstNumber ^ SecondNumber, NumberRank = (FirstNumber & SecondNumber) << 1;
	while (NumberRank)
	{
		int Template = Result;
		Result ^= NumberRank;
		NumberRank = (Template & NumberRank) << 1;
	}

	return Result;
}

int Subtraction(int FirstNumber, int SecondNumber) // побитовое вычитание
{
	SecondNumber = Addition(~SecondNumber, 1);
	return Addition(FirstNumber, SecondNumber);
}

int Multiplication(int FirstNumber, int SecondNumber) // побитовое умножение
{
	int Result = 0;

	while (SecondNumber)
	{
		if (SecondNumber & 1) Result = Addition(Result, FirstNumber);
		FirstNumber <<= 1;
		SecondNumber >>= 1;
	}
	return Result;
}

int Divide(int FirstNumber, int SecondNumber) // побитовое деление
{
	int Result = 0;
	while (FirstNumber >= SecondNumber)
	{
		Result = Addition(Result, 1);
		FirstNumber = Subtraction(FirstNumber, SecondNumber);
	}
	return Result;
}

int Modulo(int FirstNumber, int SecondNumber) // побитовая операция остатка от деления
{
	int Result = Subtraction(FirstNumber, Multiplication(Divide(FirstNumber, SecondNumber), SecondNumber));
	return Result;
}

int main()
{
	cout << "Program will show modulo of your number and 5, 53, 109.\n";
	int Number;
	
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
	int MyNumbers[] = { 5, 53, 109 };
	for (int i = 0; i < 3; )
	{
		if (Modulo(Number, MyNumbers[i]) != 0) // нахождение остатка от деления введенного числа на данные
		{
			cout << "The modulo of your number and " << MyNumbers[i] << " is " << Modulo(Number, MyNumbers[i]) << endl;
		}
		else cout << "Your number divide to " << MyNumbers[i] << " without modulo." << endl;
		i = Addition(i, 1);
	}

}
