#include "QueryResult.h"
using namespace std;

ostream &print(ostream& os, const QueryResult &qr){
    os<<qr.sought<<" occurs "<<qr->lines->size()<<" "<<(qr.Lines->size()>1? " times":"time")<<endl;
    for(auto num:*qr.lines){
        os<<"\t(lines "<<num+1<<")"<<*(qr.file->begin()+num)<<endl;
    }
    return os;
}