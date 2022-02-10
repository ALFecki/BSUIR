#include<iostream>

using namespace std;

int main() {

	int a, b, c, i;
	for (i = 10; i < 100; i++)
	{
		a = i % 10;
		b = (i - a) / 10;
		c = pow(a + b, 3);
		if (c == pow(i,2))
		{
			cout << "Solution is ";
			cout << i;
			break;
		}
	}


}