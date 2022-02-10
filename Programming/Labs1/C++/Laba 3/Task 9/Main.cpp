#include<iostream>


int main() {
	bool f = true;
	int i= 1, S = 0, a, n;
	while (f)
	{

		std::cout << "Enter the number of members: ";
		std::cin >> n;
		if (std::cin.fail()) // проверка на наличие букв во входных данных
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (n <= 0)
			{
				std::cout << "Incorrect input. Try again.\n";
				continue;
			}
			else break;
		}
	}
	do
	{
		while (f)
		{

			std::cout << "Enter a" << i - 1 << ": ";
			std::cin >> a;
			if (std::cin.fail()) // проверка на наличие букв во входных данных
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Incorrect input. Try again.\n";
				continue;
			}
			break;
		}
		
		
		S += pow(2, (i - 1)) * pow(-1, (i - 1)) * a;
		i++;


	} while (i<=n);
	std::cout << "Row is 2^(n-1)*(-1)^(n-1)*a[n-1]\n";
	std::cout << "Sum is " << S;
}