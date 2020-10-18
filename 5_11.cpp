#include<iostream>
#include<vector>
using namespace std;

int main(){
    char ch;
    int aCnt=0, eCnt=0, iCnt=0, oCnt=0, uCnt=0, spaceCnt=0, tabCnt=0, enterCnt=0;

    while(cin>>noskipws>>ch){
        switch(ch){
            case ' ':
                spaceCnt++;
                break;
            case '\t':
                tabCnt++;
                break;
            case '\n':
                enterCnt++;
                break;
            case 'a':
            case 'A':
                aCnt++;
                break;
            case 'e':
            case 'E':
                eCnt++;
                break;
            case 'i':
            case 'I':
                iCnt++;
                break;
            case 'o':
            case 'O':
                oCnt++;
                break;
            case 'u':
            case 'U':
                uCnt++;
                break;
        }
    
    }
    cout << "Number of vowel space: " << spaceCnt << endl;
    cout << "Number of vowel tab: " << tabCnt << endl;
    cout << "Number of vowel enter: " << enterCnt << endl;
    cout << "Number of vowel a: " << aCnt << endl;
	cout << "Number of vowel e: " << eCnt << endl;
	cout << "Number of vowel i: " << iCnt << endl;
	cout << "Number of vowel o: " << oCnt << endl;
	cout << "Number of vowel u: " << uCnt << endl;
    return 0;
}