#include<iostream>
#include<vector>

using namespace std;

int main() {

	int N, N1, k = 1, i, A;
	bool f = true, t = true, s;
	vector<int> a;
	cout << "Program can tell you what number is in any rank.";
	
		while (f)
		{

			cout << "\n\nEnter your number: ";
			cin >> N;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "\nIncorrect input. Try again.\n\n";
				continue;
			}
			else
			{
				break;
			}
		}
		N1 = N;
		while ((N1 /= 10) > 0)
		{
			k++;
		}
		a.resize(k);
		for (i = 0; i < k; i++)
		{
			a[i] = N % 10;
			N = (N - a[i]) / 10;
		}
		cout << "\n\nThe number of digits is " << k;
		s = true;
		while (t)
		{

				cout << "\n\nEnter i: ";
				cin >> i;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "\nIncorrect input. Try again.\n\n";
					continue;
				}
				if (i < 0)
				{
					std::cout << "\nIncorrect input. Try again.\n\n";
					continue;
				}
				else
				{
					cout << "\n\nRank i is " << a[i] << endl;
					break;
				}
		}
			/*while (t)
			{


				cout << "\n\nYou want more?\n\n1 - Yes\n2 - No\n3 - I want to enter a new number\n\nYour decision: ";
				cin >> A;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "\nIncorrect input. Try again.\n\n";
					continue;
				}
				else
				{
					if (A < 0)
					{
						std::cout << "\nIncorrect input. Try again.\n\n";
						continue;
					}
					else
					{
						break;
					}
				}
			}
		}
		switch (A)
		{
			case(1):
			{
				continue;
			}
			case(2):
			{
				t = false;
				s = false;
				break;
			}
			case(3):
			{
				s = false;
				break;
			}
			default:
			{
				s = false;
				f = false;
				t = false;
				break;
			}
		}*/

		
	
}

