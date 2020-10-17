#include<iostream>
#include<vector>
using namespace std;

int main(){
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade;
    cin>>grade;
    string lettergarde;
    lettergarde = grade<60? scores[0] : scores[(grade-50)/10];
    lettergarde += (grade!=100 && grade>60? (grade%10>7? '+': (grade%10<3? '-':' ')): ' ');
    cout<<lettergarde;
    return 0;
}