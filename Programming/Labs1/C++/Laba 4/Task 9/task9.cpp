#include<iostream>

using namespace std;

int main() {

	int i = 0, k, N, M, i1 = 0, k1 = 0;
	cout << "Program will find A * B. A and B - matrix.";
	while (true)
	{ 

		cout << "\nEnter the number of lines: ";
		cin >> N;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (N < 0)
			{
				std::cout << "\nIncorrect input. Try again.\n";
				continue;
			}
		}

		cout << "\nEnter the number of columns: ";
		cin >> M;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (M < 0)
			{
				std::cout << "\nIncorrect input. Try again.\n\n";
				continue;
			}
			else
			{
				if (M != N)
				{
					cout << "Failed. M != N, try again.";
					continue;
				}
				else
				{
					break;
				}
			}
		}
		cout << endl;
	}
	cout << endl;


	int **A = new int *[N];
	for (i = 0; i < N; i++)
	{
		A[i] = new int[M];
	}
	int **B = new int *[N];
	for (i = 0; i < N; i++)
	{
		B[i] = new int[M];
	}
	int** C = new int* [N];
	for (i = 0; i < N; i++)
	{
		C[i] = new int[M];
	}
	cout << "Enter matrix A:\n";
	
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < M; k++)
		{
			while (true)
			{
				std::cout << "Enter A[" << i << "][" << k << "]";
				std::cin >> A[i][k];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "\nIncorrect input. Try again.";

					continue;
				}
				else break;
			}
		}
	}
	cout << "Enter matrix B:\n";

	for (i = 0; i < N; i++)
	{
		for (k = 0; k < M; k++)
		{
			while (true)
			{
				std::cout << "Enter B[" << i << "][" << k << "]";
				std::cin >> B[i][k];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "\nIncorrect input. Try again.";

					continue;
				}
				else break;
			}
		}
	}
	for (i = 0; i < M; i++)
	{
		for (k = 0; k < M; k++)
		{
			C[i][k] = 0;
		}
	}
	for ( int i = 0; i < N; i++)
	{
		for ( k = 0; k < M; k++)
		{
			
			while (k1 < N)
			{
				C[i][k] += A[i][k1] * B[k1][k];
				k1++;
			}
			k1 = 0;
			
		}
	}
	cout << "\n\nA * B is\n\n";
	for (i = 0; i < M; i++)
	{
		for (k = 0; k < M; k++)
		{
			cout << "\t" << C[i][k];
		}
		cout << endl;
	}

}