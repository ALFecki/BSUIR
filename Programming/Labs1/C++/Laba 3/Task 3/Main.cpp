#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>


using namespace std;

int main() {
	bool f = true;
	double x = 0, y, i, n;
	while (f)
	{


		cout << "Enter the number of members: ";
		cin >> n;
		if (cin.fail()) // проверка на наличие букв во входных данных
		{
			cin.clear(); 
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (n <= 0)
			{
				cout << "Incorrect input. Try again.\n";
				continue;

			}
			else
			{

				for (i = 1; i <= n; i++)
				{
					x = M_PI / 40 * i;
					if (x > M_PI / 2)
					{
						//cout << "\nOut of the limit\n";

						break;
					}
					else
					{


						y = sin(x) - cos(x);
						cout << endl << y << " ";

					}

				}
				f = false;
			}
		}
	}
}