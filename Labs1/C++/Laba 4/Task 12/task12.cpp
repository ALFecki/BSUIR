#include<iostream>
#include<vector>

using namespace std;

void dublicates(int* arr, int *N)
{
	
	cout << "\nYour array:\n\n";
	for ( int i = 0; i < *N; i++)
	{
		cout << arr[i] << " ";
	}
	for (int i = 0; i < *N; i++)
	{
		
		for (int k = i + 1; k < *N; k++)
		{
			if (arr[i] == arr[k])
			{
				for (int m = k; m < *N - 1; m++)
				{
					arr[m] = arr[m + 1];
				}
				--(*N);
			}
		}
		
	}
}


int main() {
	int* arr;
	int N;
	cout << "\nProgram will delete dublicates from the array.";
	while (true)
	{
		cout << "\n\nEnter the size of the array: ";
		cin >> N;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nIncorrect input. Try again.";

			continue;
		}
		else if (N < 0)
		{
			std::cout << "\nIncorrect input. Try again.";

			continue;
		}
		else break;
	}
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		while (true)
		{
			cout << "\nEnter arr[" << i << "]";
			cin >> arr[i];
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
	dublicates(arr, &N);
	cout << "\n\nNew size of the array is " << N;
	cout << "\n\nNew array: \n";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}




}