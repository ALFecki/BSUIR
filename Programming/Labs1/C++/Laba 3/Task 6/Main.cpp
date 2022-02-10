#include<iostream>
#include<cmath>
using namespace std;

int main() {
	
	int i = 1;
	bool f = true;
	double a[2]{ 0,0 }, b[1]{ 0 };
	double x = 0.5, n, x1 = 0, k;
	
	while (f)
	{


		cout << "Enter the number of parts: ";
		cin >> n;
		if (std::cin.fail()) // проверка на наличие букв во входных данных
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}
		if (n <= 0)
		{
			cout << "Incorrect input. Try again.\n";
			continue;
		}
		else
		{

			k = pow(n, -1);
			a[i - 1] = abs(sin(log10(x)) + 1 / (tan(pow(x, 2))) * x);
			for (x; x <= 1.5; x += k)
			{


				for (i; i < 5; )
				{

					a[i] = abs(sin(log10(x)) + 1 / (tan(pow(x, 2))) * x);
					if (a[i] < a[i - 1])
					{
						a[i - 1] = a[i];
						b[i - 1] = x;
						break;
					}
					else
					{
						break;
					}


				}
			}
		}
		f = false;
	}
	cout << "\nSolution is " << b[i - 1] << endl;

}