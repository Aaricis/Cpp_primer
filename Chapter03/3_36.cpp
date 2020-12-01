#include<iostream>
#include<vector>
using namespace std;

int main(){
    /*int a[]={1,2,5};
    int b[]={1,2,3};
    int *sa=begin(a), *ea=end(a);
    int *sb=begin(b), *eb=end(b);
    if(ea-sa != eb-sb) cout<<"No";
    while(sa<ea && sb<eb){
        if(*sa!=*sb){
            cout<<"No";
            break;
        }
        sa++;
        sb++;
    }*/

    vector<int> a={1,2,3}, b={1,2};
    cout<<(a==b);

    return 0;
}