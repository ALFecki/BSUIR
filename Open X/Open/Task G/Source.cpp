#include <iostream>


int main()
{
	int N, minutes = 0;
	long* K, *A;
	std::cin >> N;
	K = new long[N];
	A = new long[N];
	long sum_of_sheeps = 0, sum_of_pasture = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> K[i] >> A[i];
		sum_of_pasture += K[i];
		sum_of_sheeps += A[i] * K[i];
	}
	long** array = new long*[sum_of_pasture];
	for (int i = 0; i < sum_of_pasture; i++) // array of pastures
	{
		array[i] = new long[2];
		array[i][0] = i;
		int counter = 0;
		while (counter != K[i])
		{
			int j = i;
			array[j][1] = A[i];
			j++; counter++;
		}
	}
	int count = sum_of_sheeps / sum_of_pasture;
	for (int i = sum_of_pasture - 1; i >= 0; i--)
	{

	}
	          

}