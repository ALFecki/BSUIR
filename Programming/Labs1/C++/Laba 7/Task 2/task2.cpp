#include<iostream>
#include<string>


using namespace std;

int main() {

	long long Number;
	cout << "Program will convert your number to the additional code.\n";
	while (true) // проверка ввода
	{
		cout << "\nEnter your number: ";
		cin >> Number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.";
			continue;
		}
		else break;
	}
	string StraightCode;
	long long NumberMod = abs(Number);
	while (NumberMod >= 1)
	{
		StraightCode.insert(0, 1, NumberMod % 2 + '0');
		NumberMod /= 2;
	}
	string AdditionalCode;
	if (Number < 0)
	{
		AdditionalCode.push_back('1'); // если число меньше нуля, то в знаковый разряд добавить 1
		AdditionalCode.push_back(',');
		for (int i = 0; i < StraightCode.length(); i++) // получение обратного кода, путем смены значений всех элементов
		{
			if (StraightCode[i] == '1') StraightCode[i] = '0';
			else StraightCode[i] = '1';
		}
		AdditionalCode += StraightCode;
		for (int i = AdditionalCode.length() - 1; i > 0; i--) // добавление к младшему разряду 1
		{
			AdditionalCode[i] += 1;
			if (AdditionalCode[i] < 50) break;
			else AdditionalCode[i] = '0';
		}

	}
	else if (Number > 0)
	{
		AdditionalCode.push_back('0'); // иначе в знаковый разряд заносится 0
		AdditionalCode.push_back(',');
		AdditionalCode += StraightCode;
	}
	else AdditionalCode.push_back('0');
	cout << "\nAdditional code of your number is " << AdditionalCode << endl;

}
