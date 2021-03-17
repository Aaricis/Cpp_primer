#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
	int a = 169;
	double d = 123.4567890123, d2 = -11;
	string s;
	
	cout << true << " " << false << endl;
	cout << boolalpha << true << " " << false << noboolalpha <<endl;
	cout << endl;
	cout << a << " " << d << " " << d2 << endl; 
	cout << showbase << showpoint << showpos << uppercase
	<< dec << a << " " << d << " " << d2 << endl
	<< hex << a << " " << d << " " << d2 << endl
	<< oct << a << " " << d << " " << d2 << endl
	<< fixed << a << " " << d << " " << d2 << endl
	<< scientific << a << " " << d << " " << d2 << endl
	<< hexfloat << a << " " << d << " " << d2 << defaultfloat << endl
	<< left << setw(10) << a << " " << setw(10) << d << " " << setw(10) << d2 << endl
	<< right << setw(10) << a << " " << setw(10) << d << " " << setw(10) << d2 << endl
	<< internal << setw(10) << a << " " << setw(10) << d << " " << setw(10) << d2 << endl
	<< setprecision(5) << setw(10) << a << " " << setw(10) << d << " " << setw(10) << d2 << endl
	<< setfill('*') << setw(10) << a << " " << setw(10) << d << " " << setw(10) << d2 << endl
	<< setw(10) << setbase(16) << a << " " << setw(10) << d << " " << setw(10) << d2 << endl
	<< dec << nouppercase << noshowpos << noshowbase << noshowpoint << endl;
	
	cout << unitbuf << a << " " << d << " " << d2 << nounitbuf << endl;
	
	cin >> noskipws >> s >> skipws;
	cout << s << flush << s << ends;
	return 0;
}
