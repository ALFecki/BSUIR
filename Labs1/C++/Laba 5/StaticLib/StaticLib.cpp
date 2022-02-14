

#include "pch.h"
#include "framework.h"
#include "staticlib.h"
#include<iostream>
#include<vector>
#include<cmath>


std::vector<double> cases(int n, std::vector<double> x, std::vector<double> y) {
	std::vector<double> z;
	z.resize(n);
	double m;
	for (int k = 0; k < n; k++)
	{
		if (abs(sin(k)) <= 0.2) m = k;
		else if (abs(sin(k)) > 0.2 && abs(sin(k)) < 0.9) m = sqrt(k);
		else if (abs(sin(k)) >= 0.9) m = sqrt(sqrt(k));
		z[k] = x[k] + y[k] * m;
	}
	return z;
}

void printarray(int n, std::vector<double> y) {

	for (int i = 0; i < n; i++)
	{
		std::cout << y[i] << " ";
	}
	std::cout << std::endl;
}



