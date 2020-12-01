#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 计算val的阶乘，即1 * 2 * 3 ... * val
int factorial(int val)
{
	if (val>1)
		return factorial(val--) * val;
	return 1;
}

int main()
{
    cout << factorial(5) << endl;
	//cout << factorial(-5) << endl;
	

	return 0;
}
