#include<iostream>
using namespace std;

int main(){
    //int x;
    /*while(cin>>x){
        cout<<x<<endl;
    }*/

    /*for(;cin>>x; ){
        cout<<x<<endl;
    }*/

    int sum=0;
    /*for(int i=0; i<10; i++){
        sum += i;
    }
    cout<<sum<<endl;*/

	int a = 0;
	while (a < 10) {
		sum += a;
		++a;
	}

	cout << sum << endl;

    return 0;
}