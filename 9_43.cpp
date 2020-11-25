#include <iostream>
#include <string>

using namespace std;

void replace(string &s, const string &oldVal, const string &newVal)
{
	auto beg = s.begin();
	
	while (beg!=s.end()) {
		string test_string(beg, beg + oldVal.length()); 
		if (test_string == oldVal) {
			beg = s.erase(beg, beg + oldVal.length());

			for (auto c : newVal) {
				beg = s.insert(beg, c);
				++beg;
			}
		}
		else {
			++beg;
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