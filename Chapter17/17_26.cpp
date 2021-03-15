#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool valid(const smatch &m)
{
    if(m[1].matched)
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[7].str();
}

int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?([ ]*)?(\\d{3})([-. ]?)([ ]*)?(\\d{4})";
    regex r(phone);
    smatch m;
    string s;

    while(getline(cin, s))
    {
        vector<string> vs;
        for(sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
            if(valid(*it))
                vs.push_back(it->str());
        if (vs.size() == 0)
        {
            cout << "no matched number" << std::endl;
        }else if(vs.size() == 1)
        {
            cout << vs[0] << std::endl;
        }else if(vs.size() >1)
        {
            for(int i = 1; i < vs.size(); ++i)
                cout << vs[i] << " ";
            cout <<endl;
        }
    }

    return 0;
}