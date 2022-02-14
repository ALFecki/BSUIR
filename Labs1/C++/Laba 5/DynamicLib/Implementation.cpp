#include "pch.h"
#include "Functions.h"
#include <iostream>


int function(int a, int b) {
	int max = a;
	if (b > a)
	{
		max = b;
	}
	return max;
}