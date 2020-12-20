#include<iostream>
#include<string>
#include<memory>
using namespace std;

struct destination{
    string ip;
    int port;
    destination(const string &_ip, const int &_port):ip(_ip), port(_port){}
};

struct connection{
    string ip;
    int port;
    connection(const string &_ip, const int &_port):ip(_ip), port(_port){}
};

connection connect(destination *pDest){
    shared_ptr<connection> pCon(new connection(pDest->ip, pDest->port));
    cout<<"ctreat connection: "<< pCon.use_count()<<endl;
    return *pCon;
}

void disconnect(connection Con){
    cout<<"connect close "<<Con.ip<<' '<<Con.port<<endl;
}

void end_connection(connection *p){
    disconnect(*p);
}

void f(destination &d){
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](const connection *p){disconnect(*p);});
    cout<<"connection now: "<< p.use_count()<<endl;
}

int main(){
    destination d("202.118.176.67", 3316);
    f(d);
    return 0;
}