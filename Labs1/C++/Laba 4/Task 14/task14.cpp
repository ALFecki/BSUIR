#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, m, i, k, l = 0;
	cout << "Program will made the field for game \"sapper\"";
	while (true)
	{

		cout << "\nEnter the number of lines: ";
		cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (n < 0)
			{
				std::cout << "\nIncorrect input. Try again.\n";
				continue;
			}
		}

		cout << "\nEnter the number of columns: ";
		cin >> m;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (m < 0)
			{
				std::cout << "\nIncorrect input. Try again.\n\n";
				continue;
			}
			else break;
			
		}
		cout << endl;
	}
	cout << endl;
	char** A = new char* [n];
	for (i = 0; i < n; i++)
	{
		A[i] = new char[m];
	}
	
	for ( i = 0; i < n; i++)
	{
		for (k = 0; k < m; k++)
		{
			while (true)
			{
				cout << "Enter A[" << i << "][" << k << "]";
				cin >> A[i][k];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "\nIncorrect input. Try again.\n";
					continue;
				}
				else break;
			}
		}
	}
	char** C = new char* [n];
	for (i = 0; i < n; i++)
	{
		C[i] = new char[m];
	}
	for ( i = 0; i < n; i++)
	{
		for ( k = 0; k < m; k++)
		{
			if (A[i][k] == '*')
			{
				C[i][k] = A[i][k];
				continue;
			}
			else if (i == 0 && k == 0) // upper left
			{
				if (A[i][k + 1] == '*') l++;
				if (A[i + 1][k] == '*') l++;
				if (A[i + 1][k + 1] == '*') l++;
			}
			else if (k + 1 == m && i == 0) // upper right
			{
				if (A[i][k - 1] == '*') l++;
				if (A[i + 1][k] == '*') l++;
				if (A[i + 1][k - 1] == '*') l++;
			}
			else if (k + 1 == m && i + 1 == n) // lower right
			{
				if (A[i][k - 1] == '*') l++;
				if (A[i - 1][k] == '*') l++;
				if (A[i - 1][k - 1] == '*') l++;
			}
			else if (k == 0 && i + 1 == n) // lower left
			{
				if (A[i][k + 1] == '*') l++;
				if (A[i - 1][k + 1] == '*') l++;
				if (A[i - 1][k] == '*') l++;
			}
			else if (i == 0) // upper line
			{
				if (A[i][k + 1] == '*') l++;
				if (A[i + 1][k + 1] == '*') l++;
				if (A[i + 1][k] == '*') l++;
				if (A[i + 1][k - 1] == '*') l++;
				if (A[i][k - 1] == '*') l++;
			}
			else if (k + 1 == m) // right column
			{
				if (A[i + 1][k] == '*') l++;
				if (A[i + 1][k - 1] == '*') l++;
				if (A[i][k - 1] == '*') l++;
				if (A[i - 1][k - 1] == '*') l++;
				if (A[i - 1][k] == '*') l++;
			}
			else if (i + 1 == n) // lower line
			{
				if (A[i][k + 1] == '*') l++;
				if (A[i - 1][k + 1] == '*') l++;
				if (A[i - 1][k] == '*') l++;
				if (A[i - 1][k - 1] == '*') l++;
				if (A[i][k - 1] == '*') l++;
			}
			else if (k == 0) // left column
			{
				if (A[i - 1][k] == '*') l++;
				if (A[i - 1][k + 1] == '*') l++;
				if (A[i][k + 1] == '*') l++;
				if (A[i + 1][k + 1] == '*') l++;
				if (A[i + 1][k] == '*') l++;
			}
			else
			{
				if (A[i + 1][k + 1] == '*') l++;
				if (A[i + 1][k] == '*') l++;
				if (A[i + 1][k - 1] == '*') l++;
				if (A[i][k - 1] == '*') l++;
				if (A[i - 1][k - 1] == '*') l++;
				if (A[i - 1][k] == '*') l++;
				if (A[i - 1][k + 1] == '*') l++;
				if (A[i][k + 1] == '*') l++;

			}
			if (l == 0) C[i][k] = A[i][k];
			else
			{
				char l1 = l + '0';
				C[i][k] = l1;
				l = 0;
			}
		}
	}
	cout << "\n\nField:\n\n";
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < m; k++)
		{
			cout << "\t" << C[i][k];
		}
		cout << endl;
	}
	

}