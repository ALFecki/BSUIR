#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


int main()
{
	long size_of_array;
	long long number;
	long long minimum= 10000000000, index;
	std::cin >> size_of_array >> number;
	std::vector<long long> array_of_number;
	for (long i = 0; i < size_of_array; i++)
	{
		long long temp;
		std::cin >> temp;
		array_of_number.push_back(temp);
		if (abs(array_of_number[i] - number) < minimum)
		{
			minimum = abs(array_of_number[i] - number);
			index = i;
		}
	}
	std::sort(array_of_number.begin(), array_of_number.end());
	int radius = std::min((unsigned long long)index - 0, array_of_number.size() - 1 - index);
	int size = radius * 2 + 1;
	std::cout << size << std::endl;
	for (int i = index - radius; i <= index + radius; i++)
	{
		std::cout << i + 1 << ' ';
	}
	

}