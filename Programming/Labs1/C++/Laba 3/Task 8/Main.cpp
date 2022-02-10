#include<iostream>

using namespace std;

int main() {

	int a, b, c, n, i, d, e, g, S, i1;
	cout << "The Armstrong's numbers are ";
	for ( i = 153; i < pow(10,6); i++)
	{
		n = 1;
		i1 = i;
		a = i % 10;
		b = (i % 100 - a)/10;
		c = (i % 1000 - a - b)/100;
		d = (i % 10000 - a - b - c)/1000;
		e = (i % 100000 - a - b - c - d)/10000;
		g = (i % 1000000 - a - b - c - d - e)/100000;
		
		while ((i1 /= 10) > 0)
		{
			n++;
		}
		S = pow(a, n) + pow(b, n) + pow(c, n) + pow(e, n) + pow(g, n);
		if (S == i)
		{
			
			cout << i << ", ";

		}
		
		
	
	}

}