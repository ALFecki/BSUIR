#include<iostream>
#include<string>


using namespace std;

string Convert(long long Number) // перевод числа в обратный код 
{

	string StraightCode;
	long long NumberMod = abs(Number);
	while (NumberMod >= 1) // перевод в двоичную СС
	{
		StraightCode.insert(0, 1, NumberMod % 2 + '0');
		NumberMod /= 2;
	}
	
	string BackCode;
	if (Number > 0) // если число положительное то обратный код равен прямому коду
	{
		StraightCode.insert(0, 1, '0');
		BackCode += StraightCode;
		BackCode.insert(0, 1, '0');
	}
	else if (Number < 0) // если число отрицательное то обратный код равен прямому коду с противоположными занчениями
	{
		StraightCode.insert(0, 1, '0');
		for (int i = 0; i < StraightCode.length(); i++) // получение обратного кода, путем смены значений всех элементов
		{
			if (StraightCode[i] == '1') StraightCode[i] = '0';
			else StraightCode[i] = '1';
		}
		BackCode.push_back('1');
		BackCode += StraightCode;
	}
	else BackCode.push_back('0');
	return BackCode;
}


int main() 
{
	cout << "Program will sum your numbers in the back code.\n";
	long long Number1, Number2;
	while (true)
	{
		cout << "\nEnter the 1-st number: ";
		cin >> Number1;
		if (cin.fail()) // проверка на ввод первого числа
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.";
			continue;
		}
		else break;
	}
	while (true)
	{
		cout << "\nEnter the 2-nd number: ";
		cin >> Number2;
		if (cin.fail()) // проверка на ввод второго числа
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.";
			continue;
		}
		else break;
	}
	bool f = false;
	if (Number1 < 0 && Number2 < 0)
	{
		f = true;
		Number1 *= -1;
		Number2 *= -1;
	}
	string FirstNumber, SecondNumber;
	FirstNumber = Convert(Number1);

	SecondNumber = Convert(Number2);

	if (FirstNumber.length() > SecondNumber.length())
	{
		while (FirstNumber.length() != SecondNumber.length()) SecondNumber.insert(2, 1, '0'); // если длина первого числа больше второго, дополнить второе нулями
	}
	else if (FirstNumber.length() < SecondNumber.length())
	{
		while (FirstNumber.length() != SecondNumber.length()) FirstNumber.insert(2, 1, '0'); // если длина второго числа больше первого, дополнить первое нулями
	}
	int count = 0;
	string Result;
	for (int i = FirstNumber.length() - 1; i >= 0; i--) // нахождение суммы
	{
		if (count == 1) // счетчик на случай переполнения разряда
		{
			FirstNumber[i]++;
			count = 0;
		}
		if (FirstNumber[i] + SecondNumber[i] - 96 > 1) // условие переполнения разряда
		{
			Result.insert(0, 1, '0');
			count++;
		}
		else if (FirstNumber[i] + SecondNumber[i] - 96 == 1) Result.insert(0, 1, '1');
		else Result.insert(0, 1, '0');
	}
	long long NewNumber = 0;
	bool t = false;
	if (Result[0] == '1')
	{
		t = true;
		Result.erase(0, 1);
		for (int i = 0; i < Result.length(); i++) // замена записи на противоположные значения
		{
			if (Result[i] == '1') Result[i] = '0';
			else Result[i] = '1';
		}

	}
	for (int i = Result.length() - 1, j = 0; i >= 0; i--, j++) // перевод в десятичную СС
	{
		NewNumber += (Result[i] - '0') * pow(2, j);
	}
	if (t || f) NewNumber *= -1; // проверка числа на знак
	cout << NewNumber << endl;
}
