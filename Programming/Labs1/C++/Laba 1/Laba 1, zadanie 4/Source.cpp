#include<iostream>

using namespace std;
int main()
{
	const int g = 10;
	int h;
	double t;
	
	setlocale(LC_ALL, "Rus");
	cout << "������� ������ ";
	cin >>  h;
	t = sqrt(2 * h / g);
	cout << "\n����� ������� �����: " << t << endl;

}