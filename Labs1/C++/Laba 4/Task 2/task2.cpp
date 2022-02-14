#include<iostream>


int main() {
	bool t = true;
	const int N = 3, M = 3;
	int a[N][M],b[N], i = 0, k = 0, d, f = 0;
	std::cout << "Program will find a maximum of every line in your  matrix.\n\n" << "You need to enter the matrix.\n\n";

	while (i <= N -1 && k <= M - 1)
	{
		while (t)
		{

			std::cout << "Enter a[" << i + 1 << "][" << k + 1 << "] ";
			std::cin >> a[i][k];
			if (std::cin.fail()) 
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "\nIncorrect input. Try again.\n\n";
				continue;
			}
			else
			{
				break;
			}
		}
		if (k == M - 1)
		{
			k = -1;
			i++;
		}
		if (k == M - 1 && i == N - 1)
		{
			break;
		}
		k++;
	}
	i = 0;
	k = 0;
	d = a[0][0];
	std::cout << "\n\nYour matrix:\n\n";
	while (i <= N - 1 && k <= M - 1)
	{
		if (d < a[i][k])
		{
			d = a[i][k];
		}
		if (k == M - 1)
		{
			b[f] = d;
			f++;
			d = a[i + 1][0];
			std::cout << "\t" << a[i][k] << std::endl;
			k = -1;
			i++;

		}
		else
		{
			std::cout << "\t" << a[i][k];
		}
		if (k == M - 1 && i == N - 1)
		{
			break;
		}
		k++;
		
	}
	for ( f = 0; f < N; f++)
	{
		std::cout << "\nThe maximum of the line number " << f + 1 << " is " << b[f] << std::endl;
	}
	
}