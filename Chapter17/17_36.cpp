#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	cout << uppercase << left <<  
	setw(10) << 100 * sqrt(2.0) << '\n' <<
	setw(10) << 100 * sqrt(3.0) << '\n' <<
	setw(10) << 100 * sqrt(4.0) << '\n' <<
	setw(10) << 100 * sqrt(5.0) << '\n' <<
	nouppercase << endl;
	return 0;
}
