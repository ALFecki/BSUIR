#include<iostream>

using namespace std;
int main()
{
	const int g = 10;
	int h;
	double t;
	
	setlocale(LC_ALL, "Rus");
	cout << "Введите высоту ";
	cin >>  h;
	t = sqrt(2 * h / g);
	cout << "\nВремя падения равно: " << t << endl;

}