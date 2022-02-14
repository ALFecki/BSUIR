#include<iostream>
#include<vector>

using namespace std;

int main()
{
	cout << "Program will will find two decimal number in your position.\n";
	long long Position;
	while (true)
	{
		cout << "\nEnter your position: ";
		cin >> Position;
		if (cin.fail() || Position <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else break;
	}
	vector<long long> TwoDecimal; //массив двудесятичных чисел
	char NumberString[255] = "";
	for (unsigned long long Number = 1; Number < pow(10,14); Number++) // проверка всех чисел на "двудесятичность"
	{
		/*itoa(Number, NumberString, 10);
		bool t = true;
		for (int i = 0; i < 266; i++)
		{
			if (NumberString[i] > 49)
			{
				t = false;
				break;
			}
		}
		if (!t) continue;*/
		unsigned long long NumberCopy = Number;
		string SecondNotation;
		while (NumberCopy >= 1) //перевод числа в десятичную СС
		{
			SecondNotation.insert(0, 1, NumberCopy % 2 + '0');
			NumberCopy /= 2;
		}
		NumberCopy = Number;
		long Length = SecondNotation.length();
		bool f = false;
		while (NumberCopy > 0) // сравнение цифр числа с десятичной записью
		{
			int Modulo = NumberCopy % 10; 
			if (SecondNotation[Length - 1] - '0' == Modulo) // если цифры совпадают, то true
			{
				f = true;
				Length--;
			}
			else // иначе false
			{
				f = false;
				break;
			}
			NumberCopy /= 10;
		}
		if (f)
		{
			TwoDecimal.push_back(Number); // заполнения массива двудесятичных
			//cout << Number << endl;
		}
		
		
		if (TwoDecimal.size() == Position) // если размер массива равен введеной позиции, вывести последнее число
		{
			cout << TwoDecimal[Position - 1] << endl;
			return 0;
		}
	}

}
