#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class ShorterString{
public:
    bool operator()(const string &s1, const string &s2) const{
        return s1.size()<s2.size();
    }
};

class SizeComp{
public:
    SizeComp(size_t n):sz(n){}
    bool operator()(const string &s) const{
        return s.size()>=sz;
    }
private:
    size_t sz;
};

class Print{
public:
    void operator()(const string &s){
        cout<<s<<" ";
    }
};


void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

string make_plural(int count, const string &word, const string &ending){
    return (count>1)? word+ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(), words.end(), ShorterString());

    auto wc = find_if(words.begin(), words.end(), SizeComp(sz));

    auto count = words.end()-wc;
    cout<<count<<" "<<make_plural(count, "word", "s")<<" of length "<<sz<<" or longer"<<endl;
    for_each(wc, words.end(), Print());
    cout<<endl;
}

int main(){
    vector<string> words={"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);
    return 0;
}