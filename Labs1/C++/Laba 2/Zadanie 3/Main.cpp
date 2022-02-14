#include<iostream>

using namespace std;

int main() {

	//bool decision;
	int X, Y;
	cout << "Enter the numbers: ";
	cin >> X >> Y;
	/*decision = X > Y ? true : false;
	if (decision)
	{
		cout << "X more than Y";
	}
	else
	{
		cout << "Y more than X";
	} */
	X>Y ? cout << "X more than Y" : cout << "Y more than X";
}