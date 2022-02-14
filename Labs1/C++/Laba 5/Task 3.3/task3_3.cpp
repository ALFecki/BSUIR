#include<iostream>
#include<vector>

using namespace std;

int** matrixinput(int Str, int Col) {

	int** a = new int* [Str];
	for (int i = 0; i < Str; i++)
	{
		a[i] = new int[Col];
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

vector<int> FindEven(int** a, int Str, int Col, int l) {
	
	vector<int> b;
	b.resize(l);
	int j = 0;
	for (int k = 1; k < Col; k+=2)
	{
		for (int i = 0; i < Str; i++)
		{
			if (a[i][k] % 2 != 0)
			{
				b[j] = a[i][k];
				j++;
			}
		}
	}
	return b;
}

void main() {

	int Str, Col, l = 0;
	double  AVG = 0;
	std::cout << "Program will make an array from odd elements of even columns.\n\n";
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
	int** Matrix = new int* [Str];
	for (int i = 0; i < Str; i++)
	{
		Matrix[i] = new int[Col];
	}
	Matrix = matrixinput(Str, Col);
	for (int k = 1; k < Col; k+=2)
	{
		for (int i = 0; i < Str; i++)
		{
			if (Matrix[i][k] % 2 != 0)
			{
				l++;
			}
		}
	}
	vector<int> NewArray;
	NewArray = FindEven(Matrix, Str, Col, l);

	cout << "\nArray is ";
	for (int j = 0; j < l; j++)
	{
		cout << NewArray[j] << " ";
		AVG += NewArray[j];
	}
	AVG /= l;
	cout << "\n\nThe average of array is " << AVG << endl;


}