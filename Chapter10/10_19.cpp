#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void elimDups(vector<string>& words){
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;
    
    sort(words.begin(), words.end());
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;

    auto end_unique = unique(words.begin(), words.end());
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;

    words.erase(end_unique, words.end());
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;
}

string make_plural(int count, const string &word, const string &ending){
    return (count>1)? word+ending : word;
}

void biggies(vector<string> &words, int sz){
    elimDups(words);
    

    auto wc = stable_partition(words.begin(), words.end(), [sz](const string &s){
        return s.length()>=sz;
    });
    auto count = wc-words.begin();
    cout<<count<<" "<<make_plural(count, "word", "s")<<" of length "<<sz<<" or longer"<<endl;
    for_each(words.begin(), wc, [](const string &s){
        cout<<s<<" ";
    });
    cout<<endl;
}

int main(){
    vector<string> words={"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);
    return 0;
}