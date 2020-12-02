#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
 
int main(int argc,char *argv[])
{
	string s = "ab2c3d7r4e6";
	string s1 = "1234567";
	string s2 = "abcdefgr";
 
	string::size_type pos=0;
	while ((pos = s.find_first_of(s1,pos)) != string::npos)
	{
		cout << pos << s[pos] << endl;
		++pos;
	}
 
	pos = 0;
	while ((pos = s.find_first_not_of(s1,pos)) != string::npos)
	{
		cout <<pos << s[pos] << endl;
		++pos;
	}
 
	return 0;
}