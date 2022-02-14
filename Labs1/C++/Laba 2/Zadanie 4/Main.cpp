#include<iostream>

using namespace std;

void main() {


	double k,x,y,h;

	cout << "Enter k: ";
	cin >> k;
	cout << "Enter coordinates\n" << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	if (k > 0 && (x > k || x<0 || y>k || y < 0) || k<0 && (x < k || x>0 || y < k || y > 0))
	{
		
		if (abs(x) <= abs(k - x) && abs(x) <= abs(y) && abs(x) <= abs(k - y))
		{
			cout << "The point is outside the square.\n\nThe smallest distance to the side of the square is " << abs(x) << endl;
		}
		else
		{

			if (abs(y) <= abs(k - x) && abs(y) <= abs(x) && abs(y) <= abs(k - y))
			{
				cout << "The point is outside the square.\n\nThe smallest distance to the side of the square is " << abs(y) << endl;
			}
			else
			{
				if (abs(k-x) <= abs(x) && abs(k-x) <= abs(y) && abs(k-x) <= abs(k - y))
				{
					cout << "The point is outside the square.\n\nThe smallest distance to the side of the square is " << abs(k -x) << endl;
				}
				else
				{
					if (abs(k-y) <= abs(k - x) && abs(k-y) <= abs(y) && abs(k-y) <= abs(x))
					{
						cout << "The point is outside the square.\n\nThe smallest distance to the side of the square is " << abs(k-y) << endl;
			
					}
				}
			}
		}
	}
	else
	{
		if (abs(x) <= abs(k - x) && abs(x) <= abs(y) && abs(x) <= abs(k - y))
		{
			cout << "The smallest distance to the side of the square is " << abs(x) << endl;
		}
		else
		{

			if (abs(y) <= abs(k - x) && abs(y) <= abs(x) && abs(y) <= abs(k - y))
			{
				cout << "The smallest distance to the side of the square is " << abs(y) << endl;
			}
			else
			{
				if (abs(k - x) <= abs(x) && abs(k - x) <= abs(y) && abs(k - x) <= abs(k - y))
				{
					cout << "The smallest distance to the side of the square is " << abs(k - x) << endl;
				}
				else
				{
					if (abs(k - y) <= abs(k - x) && abs(k - y) <= abs(y) && abs(k - y) <= abs(x))
					{
						cout << "The smallest distance to the side of the square is " << abs(k - y) << endl;
					}
				}
			}
		}
		/*if (abs(x) <= abs(k - x) && abs(x) <= abs(y) && abs(x) <= abs(k - y))
		{
			cout << "Наименьшее расстояние равно: " << x;
		}
		else
		{
			if (abs(y) <= abs(k - x) && abs(y) <= abs(x) && abs(y) <= abs(k - y))
			{
				cout << "Наименьшее расстояние равно: " << y;
			}
			else
			{
				if (abs(k - x) <= abs(x) && abs(k - x) <= abs(y) && abs(k - x) <= abs(k - y))
				{
					cout << "Наименьшее расстояние равно: " << (k-x);
				}
				else
				{
					if (abs(k - y) <= abs(k - x) && abs(k - y) <= abs(y) && abs(k - y) <= abs(x))
					{
						cout << "Наименьшее расстояние равно: " << (k - y);
					}
				}


			}

		}*/
	}

}