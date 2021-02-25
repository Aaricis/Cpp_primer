#include<iostream>
#include"Query.h"
#include"NotQuery.h"
#include"AndQuery.h"
#include"OrQuery.h"

int main(){
    Query q = Query("fiery") & Query("bird") | Query("wind");
    cout<<q<<endl;
    return 0;
}