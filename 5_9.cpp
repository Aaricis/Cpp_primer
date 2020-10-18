#include<iostream>
#include<vector>
using namespace std;

int main(){
    char ch;
    int aCnt=0, eCnt=0, iCnt=0, oCnt=0, uCnt=0;
    while(cin>>ch){
        if(ch=='a'){
            aCnt++;
        }
        else if(ch=='e'){
            eCnt++;
        }
        else if(ch=='i'){
            iCnt++;
        }
        else if(ch=='o'){
            oCnt++;
        }
        else{
            uCnt++;
        }
    }
    cout << "Number of vowel a: " << aCnt << endl;
	cout << "Number of vowel e: " << eCnt << endl;
	cout << "Number of vowel i: " << iCnt << endl;
	cout << "Number of vowel o: " << oCnt << endl;
	cout << "Number of vowel u: " << uCnt << endl;
    return 0;
}