#include<iostream>

using namespace std;

int main() {

	int x, y, z, n, S1[4]{ 0 };
	cout << "\nProgram will find the sum of the numbers on each diagonal of the cube.\n\n";
	while (true)
	{
		cout << "Enter the cube edges: ";
		cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else if (n < 0)
		{
			std::cout << "\nIncorrect input. Try again.\n\n";
			continue;
		}
		else break;

		
		cout << endl;
	}
	int ***a = new int**[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int* [n];
		for ( int k = 0; k < n; k++)
		{
			a[i][k] = new int[n];
		}
	}
	cout << "Enter the numbers.\n\n";
	for ( x = 0; x < n; x++)
	{
		for ( y = 0; y < n; y++)
		{
			for ( z = 0; z < n; z++)
			{
				while (true)
				{
					cout << "a[" << x << "][" << y << "][" << z << "]: ";
					cin >> a[x][y][z];
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "\nIncorrect input. Try again.\n";
						continue;
					}
					else
					{
						if (a[x][y][z] < 0)
						{
							std::cout << "\nIncorrect input. Try again.\n\n";
							continue;
						}
						else break;

					}
					cout << endl;
				}
			}
		}
	}
	x = 0;
	y = 0;
	z = 0;
	while (x < n && y < n && z < n) 
	{
		S1[0] += a[x][y][z];
		x++;
		y++;
		z++;
	}
	x = 0;
	y = n - 1;
	z = 0;
	while (x < n && y >= 0 && z < n)
	{
		S1[1] += a[x][y][z];
		x++;
		y--;
		z++;
	}
	x = 0;
	y = 0;
	z = n - 1;
	while (x < n && y < n && z >= 0)
	{
		S1[2] += a[x][y][z];
		x++;
		y++;
		z--;
	}
	x = 0;
	y = n - 1;
	z = n - 1;
	while (x < n && y >= 0 && z >= 0)
	{
		S1[3] += a[x][y][z];
		x++;
		y--;
		z--;
	}
	int max = 0;
	cout << "\nSums are: \n";
	for ( int i = 0; i < 4; i++)
	{
		cout << S1[i] << " ";
		if (S1[i] > max)
		{
			max = S1[i];
		}
	}
	cout << "\n\nThe maximum sum is " << max << endl << endl;

}