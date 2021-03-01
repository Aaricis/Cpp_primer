#include<iostream>
#include<string>
#include<fstream>
#include<memory>
#include"TextQuery.h"
#include"Query.h"

using namespace std;

int main(){
    ifstream ifs("text.txt");
    TextQuery tq(ifs);
    Query q = Query("fiery") & Query("bird") | Query("wind");
    cout<<q<<endl;
    
    return 0;
}