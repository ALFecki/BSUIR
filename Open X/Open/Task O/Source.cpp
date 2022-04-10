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
	std::vector<long long> array_of_number, array_of_number_copy;
	long radius, radius1;
	for (long i = 0; i < size_of_array; i++)
	{
		long long temp;
		std::cin >> temp;
		array_of_number.push_back(temp);
	}
	array_of_number_copy = array_of_number;
	std::sort(array_of_number.begin(), array_of_number.end());
	for (long i = 0; i < size_of_array; i++)
	{
		std::cout << array_of_number[i] << ' ';
	}
	std::cout << std::endl;
	for (long i = 0; i < size_of_array; i++)
	{
		if (abs(array_of_number[i] - number) < minimum)
		{
			minimum = abs(array_of_number[i] - number);
			index = i;
			radius = std::min(index, size_of_array - 1 - index);
		}
		else if (abs(array_of_number[i] - number) == minimum)
		{
			radius1 = std::min(i, size_of_array - 1 - i);
			if (radius1 > radius)
			{
				index = i;
				radius = radius1;
			}
		}
	}
	long size = radius * 2 + 1;
	std::cout << size << std::endl;
	
	for (long i = 0, count = index - radius; i < size_of_array; i++)
	{
		if (array_of_number_copy[i] == array_of_number[count] && count <= index + radius)
		{
			std::cout << i << ' ';
			count++;
		}
	}
	

}