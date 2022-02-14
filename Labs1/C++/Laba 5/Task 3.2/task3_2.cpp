#include<iostream>
#include<vector>

double** matrixinput(int Str, int Col) {

	double** a = new double* [Str];
	for (int i = 0; i < Str; i++)
	{
		a[i] = new double[Col];
	}
	for (int i = 0; i < Str; i++)
	{
		for (int l = 0; l < Col; l++)
		{
			std::cout << "Enter a[" << i + 1 << "][" << l + 1 << "]";
			std::cin >> a[i][l];
		}
	}
	return a;
}


void FindZero(double** a, int Str, int Col, int l) {
	int j = 0;
	std::cout << "Indices are ";
	for (int i = 0; i < Str; i++)
	{
		for (int k = 0; k < Col; k++)
		{
			if (a[i][k] == 0)
			{
				std::cout << i << " " << k << "; ";
			}
			
		}
	}
	std::cout << std::endl << std::endl;
}

void ViceVersa(double** a, int Str, int Col) {
	int i = 0, k = 0, n = Str - 1, j = Col - 1;
	double** NewMatrix = new double* [Str];
	for (int i = 0; i < Str; i++)
	{
		NewMatrix[i] = new double[Col];
	}
	while (i < Str && n >= 0) 
	{
		k = 0;
		j = Col - 1;
		while (k < Col && j >= 0)
		{
			NewMatrix[n][j] = a[i][k];
			k++;
			j--;
		}
		i++;
		n--;
	}
	for (int i = 0; i < Str; i++)
	{
		for (int k = 0; k < Col; k++)
		{
			std::cout << NewMatrix[i][k] << "\t";
		}
		std::cout << std::endl;
	}

}

void main() {

	int Str, Col, l = 0;
	std::cout << "Program will find a count of elements, which are equal to 0, show their indices and replace all elemnts of array vice versa.";
	while (true)
	{
		std::cout << "\n\nEnter the number of strings and columns: ";
		std::cin >> Str >> Col;
		if (std::cin.fail() || Str <= 0 || Col <= 0)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect input. Try again.";
			continue;
		}
		else break;
	}
	double** Matrix = new double* [Str];
	for (int i = 0; i < Str; i++)
	{
		Matrix[i] = new double[Col];
	}
	Matrix = matrixinput(Str, Col);
	std::cout << "\nYour matrix: " << std::endl;
	for (int i = 0; i < Str; i++)
	{
		for (int k = 0; k < Col; k++)
		{
			std::cout << Matrix[i][k] << "\t";
		}
		std::cout << std::endl;
	}
	
	for (int i = 0; i < Str; i++)
	{
		for (int k = 0; k < Col; k++)
		{
			if (Matrix[i][k] == 0)
			{
				l++;
			}
		}
	}
	std::cout << "\nThe count of zero elements is " << l << std::endl;
	FindZero(Matrix, Str, Col, l);
	ViceVersa(Matrix, Str, Col);
	



}