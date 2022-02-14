#include<iostream>


using namespace std;


int main() {

	long long number = 0, Sum = 0;
	char string[255] = "";
	cout << "Program will count the sum of the numbers in the string.\n\n";
	cout << "Enter your string: ";
	cin.getline(string, 255);

	for (int i = 0; string[i] != '\0'; i++)
	{
		int j = i + 1;
		if (string[i] >= 48 && string[i] <= 57)
		{
			if (string[j] >= 48 && string[j] <= 57)
			{
				number = ((long long)string[j - 1] - '0') * 10 + (string[j] - '0');
				j++;
				i++;
				while (string[j] >= 48 && string[j] <= 57)
				{
					number = number * 10 + (string[j] - '0');
					j++;
					i++;
				}
				Sum += number;
			}
		}
	}
	cout << "\nThe summ is " << Sum << endl;

}