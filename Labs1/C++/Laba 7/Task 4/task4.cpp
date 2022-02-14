#include <iostream> 
#include <string>

// Вариант 11

std::string Sum(std::string FirstNumber, std::string SecondNumber) // операция сложения для 14-ричной СС
{
	if (FirstNumber.length() > SecondNumber.length())
	{
		while (FirstNumber.length() != SecondNumber.length())
		{
			SecondNumber.insert(0, 1, '0'); // дополнение нулями, если второе число меньше первого
		}
	}
	else if (FirstNumber.length() < SecondNumber.length())
	{
		while (FirstNumber.length() != SecondNumber.length())
		{
			FirstNumber.insert(0, 1, '0'); // то же самое, если первое меньше
		}
	}
	std::string Sum;
	int count = 0;
	for (int i = FirstNumber.length() - 1; i >= 0; i--) // перебор всех символов чисел
	{
		int Number;
		if (FirstNumber[i] == 'A') Number = 10; // присвоение численного значения буквам
		else if (FirstNumber[i] == 'B') Number = 11;
		else if (FirstNumber[i] == 'C') Number = 12;
		else if (FirstNumber[i] == 'D') Number = 13;
		else Number = FirstNumber[i] - '0';
		int Number1;
		if (SecondNumber[i] == 'A') Number1 = 10;
		else if (SecondNumber[i] == 'B') Number1 = 11;
		else if (SecondNumber[i] == 'C') Number1 = 12;
		else if (SecondNumber[i] == 'D') Number1 = 13;
		else Number1 = SecondNumber[i] - '0';
		int NewNumber = Number + Number1;
		if (count == 1) // если при сложении прошлого разряда, был запомнен десяток, то добавить к новой сумме
		{
			NewNumber++;
			count = 0;
		}
		if (NewNumber >= 14) // если сумма больше 14, то отнять 14 и записать в символах 14-ричной СС
		{
			NewNumber -= 14;
			count++;
			if (NewNumber == 10) Sum.insert(0, 1, 'A');
			else if (NewNumber == 11) Sum.insert(0, 1, 'B');
			else if (NewNumber == 12) Sum.insert(0, 1, 'C');
			else if (NewNumber == 13) Sum.insert(0, 1, 'D');
			else Sum.insert(0, 1, NewNumber + '0');
		}
		else if (NewNumber >= 10 && NewNumber <= 13)
		{
			if (NewNumber == 10) Sum.insert(0, 1, 'A');
			else if (NewNumber == 11) Sum.insert(0, 1, 'B');
			else if (NewNumber == 12) Sum.insert(0, 1, 'C');
			else if (NewNumber == 13) Sum.insert(0, 1, 'D');
		}
		else Sum.insert(0, 1, NewNumber + '0');
		
	}
	return Sum;



}

std::string Subtraction(std::string FirstNumber, std::string SecondNumber) 
{
	if (FirstNumber.length() > SecondNumber.length())
	{
		while (FirstNumber.length() != SecondNumber.length())
		{
			SecondNumber.insert(0, 1, '0');
		}
	}
	else if (FirstNumber.length() < SecondNumber.length())
	{
		while (FirstNumber.length() != SecondNumber.length())
		{
			FirstNumber.insert(0, 1, '0');
		}
		std::string FirstNumberCopy = FirstNumber;
		FirstNumber = SecondNumber;
		SecondNumber = FirstNumberCopy;
	}
	std::string Result;
	int count = 0;
	for (int i = FirstNumber.length() - 1; i >= 0; i--)
	{
		int Number;
		if (FirstNumber[i] == 'A') Number = 10;
		else if (FirstNumber[i] == 'B') Number = 11;
		else if (FirstNumber[i] == 'C') Number = 12;
		else if (FirstNumber[i] == 'D') Number = 13;
		else Number = FirstNumber[i] - '0';
		int Number1;
		if (SecondNumber[i] == 'A') Number1 = 10;
		else if (SecondNumber[i] == 'B') Number1 = 11;
		else if (SecondNumber[i] == 'C') Number1 = 12;
		else if (SecondNumber[i] == 'D') Number1 = 13;
		else Number1 = SecondNumber[i] - '0';
		if (count == 1)
		{
			Number--;
			count = 0;
		}
		if (Number < Number1)
		{
			count++;
			Number += 14;
		}
		int NewNumber = Number - Number1;
		if (NewNumber >= 10 && NewNumber <= 13)
		{
			if (NewNumber == 10) Result.insert(0, 1, 'A');
			else if (NewNumber == 11) Result.insert(0, 1, 'B');
			else if (NewNumber == 12) Result.insert(0, 1, 'C');
			else if (NewNumber == 13) Result.insert(0, 1, 'D');
		}
		else Result.insert(0, 1, NewNumber + '0');

	}
	return Result;
}

int main() 
{

	std::cout << "Program can make \"+\" and \"-\" operations with 14-th notation.\n";
	std::string FirstNumber, SecondNumber;
	std::cout << "Enter the 1-st number: ";
	std::getline(std::cin, FirstNumber);
	std::cout << "Enter the 2-nd number: ";
	std::getline(std::cin, SecondNumber);		
	std::cout << "Choose the operation.\n Enter \"+\" or \"-\": ";
	char Operation;
	std::cin >> Operation;
	std::string Result;
	switch (Operation) 
	{
		case '+':
			if (FirstNumber[0] == '-') Result = Subtraction(SecondNumber, FirstNumber);
			else if (SecondNumber[0] == '-') Result = Subtraction(FirstNumber, SecondNumber);
			else Result = Sum(FirstNumber, SecondNumber);
			std::cout << Result << std::endl;
			break;
		case '-': 
			if (FirstNumber[0] == '-' && SecondNumber[0] != '-' || FirstNumber[0] != '-' && SecondNumber[0] == '-')
			{
				FirstNumber.erase(0, 1);
				Result = Sum(SecondNumber, FirstNumber);
				Result.insert(0, 1, '-');
			}
			else Result = Subtraction(FirstNumber, SecondNumber);
			std::cout << Result << std::endl;
			break;
	}
}
