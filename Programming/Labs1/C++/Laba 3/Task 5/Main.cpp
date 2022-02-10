//Variant 11
#include<iostream>

int main() {
	int n, i, k, m = 1, factorial = 1;
	double S, Y, x;
	bool f = true, g = true;

	while (g)
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
		std::cout << "Enter the number of solutions: ";
		std::cin >> i;
		if (std::cin.fail()) // проверка на наличие букв во входных данных
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}

		if (n < 0 || i < 0)
		{
			std::cout << "\nIncorrect input. Try again\n\n";
			continue;

		}
		else
		{
			g = false;
		}
	}
	for ( k = 1; k <= n; k++)
	{
		factorial *= k; 
	}
	while (f)
	{

		do
		{

			std::cout << "Enter x: ";
			std::cin >> x; 
			if (std::cin.fail()) // проверка на наличие букв во входных данных
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Incorrect input. Try again.\n";
				continue;
			}
			if (x > 1 || x < 0.1)
			{
				std::cout << "Incorrect input! Try again!\n";
				
				continue;
				
			}
			else
			{
				S = ((pow(-1, n) * ((2 * pow(n, 2) + 1))) * pow(x, 2 * n)) / (2 * factorial);
				
				Y = (1 - pow(x, 2) / 2) * cos(x) - x * sin(x) / 2;

				std::cout << "S is " << S << std::endl << "Y is " << Y << std::endl;
				m++;
				
			}
		} while (m <= i);
		f = false;
	}
	return 0;
}