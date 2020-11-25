#include <iostream>
#include <string>

using namespace std;

void replace(string &s, const string &oldVal, const string &newVal)
{
	int i=0;
    while(i<s.length()){
        string t(s, i, oldVal.length());
        if(t==oldVal){
            s.replace(i, oldVal.length(), newVal);
            i += newVal.length();
        }
        else{
            i++;
        }
    }
}

int main()
{
	string s = "hello tho thru";
	cout << s << endl;

	replace(s, "tho", "though");
	cout << s << endl;

	replace(s, "thru", "through");
	cout << s << endl;

	return 0;
}