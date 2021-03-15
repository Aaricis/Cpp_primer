#include<iostream>
#include<string>
#include<regex>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const smatch& m)
{
    if (m[1].matched)
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}

vector<string> s_split(const string& in, const string& delim) {
    regex re{ delim };
    return vector<string> {
        sregex_token_iterator(in.begin(), in.end(), re, -1),
            sregex_token_iterator()
    };
}

int main(int argc, char* argv[])
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream ifs("./phone.txt");
    regex r("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})");
    smatch m;
    string s;

    while (getline(ifs, line))
    {
        record.str(line);
        PersonInfo info;
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        record.clear();
        people.push_back(info);
    }

    for (const auto& person : people)
    {
        ostringstream formatted, badNums;
        for (const auto& ph : person.phones)
        {
            for (sregex_iterator it(ph.begin(), ph.end(), r), end_it; it != end_it; ++it) 
                if (!valid(*it))
                {
                    badNums << " " << ph;
                }
                else
                    formatted << " " << (*it)[2] << " " << (*it)[2] << (*it)[2];
        }
        if (badNums.str().empty())
            cout << person.name << " " << formatted.str() << endl;
        else
            cerr << " input error: " << person.name << " invalid number(s)" << badNums.str() << endl;
    }
    return 0;
}