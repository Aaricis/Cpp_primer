#include<iostream>
#include<vector>
using namespace std;

int main(){
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade;
    cin>>grade;
    string lettergarde;
    if(grade<60){
        lettergarde = scores[0];
    }
    else{
        lettergarde = scores[(grade-50)/10];
        if(grade != 100){
            if(grade%10>7) lettergarde += '+';
            else if(grade%10<3) lettergarde += '-';
        }
    }
    cout<<lettergarde;
    return 0;
}