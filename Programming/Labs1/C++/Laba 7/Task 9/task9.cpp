#include <iostream>
#include <string>

int main() {

	std::cout << "\nProgram will convert number to the 3-rd notation with 1,2,3.\n";
	std::cout << "Enter your number: ";
	long long OriginalNumber;
	std::cin >> OriginalNumber;
	std::string ThirdNotation;
	ThirdNotation.insert(0, 1, OriginalNumber % 3 + '0'); // записываем количество единиц
	OriginalNumber -= OriginalNumber % 3;
	for (int i = 1; OriginalNumber > 1; i++)
	{
		int Number;
		Number = OriginalNumber / 3; // делим оставшееся число на 3
		if (Number <= 3) // если частное меньше 4
		{
			ThirdNotation.insert(0, 1, OriginalNumber / pow(3, i) + '0'); // вставляем частное от деления на 3
			break;
		}
		else // если больше 3
		{
			for (int j = 1; j < 4; j++)
			{
				auto Modulo = (long long)(OriginalNumber - j * pow(3, i)) % (long long)pow(3, i + 1); // проверяем деление оставшегося числа на 3^i+1
				if (Modulo == 0) // если остаток от деления равен 0, то записываем j в перевод
				{
					ThirdNotation.insert(0, 1, j + '0');
					OriginalNumber -= j * pow(3, i);
					break;
				}
			}
		}
		
		
	}
	std::cout << ThirdNotation << std::endl;
}
