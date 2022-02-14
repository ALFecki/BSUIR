#include<iostream>

using namespace std;

int main() {

	int decision;
	double a, b, c, p, q, D, x1, x2, x3, x4,t1,t2, z1, z2;
	Input:
	cout << "Select the type of equation: \n" << "1 - ax^4 + bx^2 + c = 0 \n" << "2 - ax^4 + bx^3 + cx^2 + bx + a = 0 \n" << "3 - x^3 + px + q = 0 \n";
	cin >> decision;
	switch (decision)
	{
	case 1:
		cout << "Enter coefficients\n" << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
		cout << "c: ";
		cin >> c;
		D = pow(b, 2) - 4 * a * c;
		if (D<0)
		{
			cout << "No solutions.";

		}
		else
		{
			if (D==0)
			{
				x1 = sqrt(-b / (2 * a));
				x2 = -x1;
				cout << "Solutions are " << x1 << " è " << x2;

			}
			else
			{
				x1 = sqrt((-b + sqrt(D)) / (2 * a));
				x2 = -x1;
				x3 = ((-b - sqrt(D)) / (2 * a));
				if (x3>0)
				{
					x3 = sqrt(x3);
					x4 = -x3;
					cout << "Solutions are " << x1 << " " << x2 << " " << x3 << " " << x4;
				}
				else
				{
					cout << "Solutions are " << x1 << " è " << x2;
				}
			}
		}
		break;
	
		
	case 2:
		cout << "Enter coefficients\n" << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
		cout << "c: ";								//at^2+bt+c-2a = 0		t = x+1/x	x^2-xt+1 = 0
		cin >> c;
		
		D = pow(b, 2) - 4 * a * (c - 2 * a);
		if (D < 0)
		{
			cout << "No solutions.";
		}
		else
		{
			if (D == 0)
			{
				t1 = -b / (2 * a);
				D = pow(t1, 2) - 4;
				if (D < 0)
				{
					cout << "No solutions.";

				}
				else
				{
					if (D == 0)
					{
						x1 = t1 / 2;
						cout << "Solution is" << x1 << endl;
					}
					else
					{
						x1 = (t1 + sqrt(D)) / 2;
						x2 = (t1 - sqrt(D)) / 2;
						cout << "Solutions are " << x1 << " and " << x2 << endl;
					}
				}
			}
			else
			{
				t1 = (-b + sqrt(D)) / (2 * a);
				D = pow(t1, 2) - 4;
				if (D < 0)
				{
					cout << " ";

				}
				else
				{
					if (D == 0)
					{
						x1 = t1 / 2;
						cout << "Solutions are " << x1;
					}
					else
					{
						x1 = (t1 + sqrt(D)) / 2;
						x2 = (t1 - sqrt(D)) / 2;
						cout << "Solutions are " << x1 << " and " << x2;
					}
				
				
				}
				t2 = (-b - sqrt(D)) / (2 * a);
				D = pow(t2, 2) - 4;
				if (D < 0)
				{
						cout << " ";

				}
				else
				{
					if (D == 0)
					{
						x3 = t2 / 2;
						cout << "Solutions are " << x3;
					}
					else
					{
						x3 = (t2 + sqrt(D)) / 2;
						x4 = (t2 - sqrt(D)) / 2;
						cout << "Solutions are " << x3 << " and " << x4;
					}
				}
			}
				
		}
		break;
	
	case 3:
		
		cout << "Enter coefficients\n" << "p: ";
		cin >> p;
		cout << "q: ";
		cin >> q;									//t^2+qt-p^3/27=0	t = z^3
		z1 = -q / 2 + sqrt(pow(q, 2) / 4 + pow(p, 3) / 27);
		z2 = -q / 2 - sqrt(pow(q, 2) / 4 + pow(p, 3) / 27);
		x1 = pow(z1, 1 / 3) + pow(z2, 1 / 3);
		cout << endl << "Solution is" << x1;
		break;
	default:
		cout << "You have only 3 types!";
		goto Input;
		break;
	}


}