#include "My_unique_ptr.h"

int main()
{
	My_unique_ptr<int> pointer(new int(10));
	
	std::cout << *pointer << std::endl;
}