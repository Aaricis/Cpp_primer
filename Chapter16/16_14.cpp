#include <iostream>
#include "Screen.h"
using namespace std;

int main()
{
	Window_mgr<24, 80> w;
	Screen<24, 80> s('1');
	cout << s.size() << endl; 
	size_t i = w.addScreen(s);
	cout << i << endl;
	w.showScreen(cout, i);
	cin >> s;
	cout << s;
	return 0;
} 
