#include <iostream>

int main()
{
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		int t = 11;
		std::cout << t << std::endl;;
		std::string answer = "";
		while (answer != "YES") {
			std::cin >> answer;
			if (answer == "NO") {
				t--;
				std::cout << t << std::endl;
			}
		}
	}
	return 0;
}