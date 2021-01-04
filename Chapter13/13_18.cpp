#include<iostream>
#include<string>
using namespace std;

class Employee{
    private:
        string name;
        unsigned int id;
        static unsigned int no;
    public:
        Employee();
        Employee(const string &_name);
        const unsigned int get_id() const{
            return id;
        }
};

unsigned int Employee::no=0;

Employee::Employee(){
    id = no++;
}

Employee::Employee(const string &_name){
    name = _name;
    id = no++;
}

int main(){
    Employee ee("ffhghj");
    return 0;
}