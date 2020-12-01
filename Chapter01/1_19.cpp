#include <iostream>

int main()
{
	int lval = 0, rval = 0;

	std::cout << "Enter two integers:" << std::endl;
	std::cin >> lval >> rval;

	if (lval > rval) {
		int tmp = rval;
		rval = lval;
		lval = tmp;
	}

	while (lval <= rval) {
		std::cout << lval << std::endl;
		lval++;
	}

	return 0;
}