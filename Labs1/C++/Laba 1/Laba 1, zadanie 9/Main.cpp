#include<iostream>
#include<cmath>

using namespace std;

void main() {

	const int n = 11;
	double b1,S,q;
	setlocale(LC_ALL, "Rus");
	cout << "������� ������ ���� �������������� ���������: ";
	cin >> b1;
	q =  pow(n+1,-1);
	
	S = b1 / (1 - q);

	cout << "����� ���������� ��������� �������������� �����: " << S;




}