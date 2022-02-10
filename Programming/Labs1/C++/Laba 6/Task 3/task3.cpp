#include<iostream>

using namespace std;


int main() {

	char string[100] = " ";
	int i = 0, j = 1, Sum = 0;
	cout << "Program will count the sum of the numbers.\nThe first number will have sign \"+\", the second will have sign \"-\" and so on. ";
	cout << "\nEnter your string: ";
	cin.getline(string, 100);
	while (string[i] != '\0')
	{
		if (string[i] == '0' || string[i] == '1' || string[i] == '2' || string[i] == '3' || string[i] == '4' || string[i] == '5' || string[i] == '6' || string[i] == '7' || string[i] == '8' || string[i] == '9')
		{
			if (j % 2 == 0)
			{
				Sum -= (int)(string[i] - '0');
			}
			else
			{
				Sum += (int)(string[i] - '0');
			}
			j++;
		}
		i++;
	}
	cout << "The summ is " << Sum << endl;
}