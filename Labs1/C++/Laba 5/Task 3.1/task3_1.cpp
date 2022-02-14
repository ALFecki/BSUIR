#include<iostream>
#include<vector>

using namespace std;

int** matrixinput(int n, int k) {

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[k];
	}
	for (int i = 0; i < n; i++)
	{
		for (int l = 0; l < k; l++)
		{
			cout << "Enter a[" << i + 1 << "][" << l + 1 << "]";
			cin >> a[i][l];
		}
	}
	return a;
}

vector<int> newarray(int** a, int n, int k, int m) {
	int j = 0;
	vector<int> newarray;
	
	newarray.resize(m);
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] % 2 == 0) 
		{
			newarray[j] = a[i][i];
			j++;
		}
	}

	return newarray;
}

void printarray(int n, std::vector<int> y) {

	for (int i = 0; i < n; i++)
	{
		std::cout << y[i] << " ";
	}
	std::cout << std::endl;
}


int production(vector<int> newarray, int m) {
	int P = 1;
	for (int i = 0; i < m; i++)
	{
		P *= newarray[i];
	}
	return P;
}


void main() {
	
	cout << "Program will make an array from even elements of the main diagonal of matrix and find a production of they.\n\n";
	int n, k, m = 0, P;
	while (true)
	{
		cout << "Enter the number of strings and columns: ";
		cin >> n >> k;
		if (cin.fail() || n <= 0 || k <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.";
			continue;
		}
		else break;
	}
	
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[k];
	}
	a = matrixinput(n, k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		
		if (a[i][i] % 2 == 0) m++;
		
	}
	vector<int> newvec;
	newvec = newarray(a, n, k, m);
	printarray(m, newvec);
	P = production(newvec, m);
	cout << P << endl;
}