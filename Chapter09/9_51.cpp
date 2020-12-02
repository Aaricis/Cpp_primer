#include<iostream>
#include<string>
using namespace std;

class Date{
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

public:
    Date(const string& s){
        if(s.find_first_of(',')!=string::npos){
            convert1(s);
        }
        else if(s.find_first_of('/')!=string::npos){
            convert2(s);
        }
        else{
            convert3(s);
        }
    }

    unsigned int getMonth(const string& s){
        if(s.find("Jan")!=string::npos) return 1;
        else if(s.find("Feb")!=string::npos) return 2;
        else if(s.find("Mar")!=string::npos) return 3;
        else if(s.find("Apr")!=string::npos) return 4;
        else if(s.find("May")!=string::npos) return 5;
        else if(s.find("Jun")!=string::npos) return 6;
        else if(s.find("Jul")!=string::npos) return 7;
        else if(s.find("Aug")!=string::npos) return 8;
        else if(s.find("Sep")!=string::npos) return 9;
        else if(s.find("Oct")!=string::npos) return 10;
        else if(s.find("Nov")!=string::npos) return 11;
        else return 12;
    }

    void convert1(const string& s){
        month = getMonth(s); 
        day = stoi(s.substr(s.find_first_of("0123456789"), s.find_first_of(",")-s.find_first_of("0123456789")));
        year = stoi(s.substr(s.find_first_of(",")+1));       
    }

    void convert2(const string& s){
        day = stoi(s.substr(0, s.find_first_of('/')));
        month = stoi(s.substr(s.find_first_of('/')+1, s.find_last_of('/')-s.find_first_of('/')-1));
        year = stoi(s.substr(s.find_last_of('/')+1));
    }

    void convert3(const string& s){
        month = getMonth(s);
        day = stoi(s.substr(s.find_first_of(' ')+1, s.find_last_of(' ')-s.find_first_of(' ')-1));
        year = stoi(s.substr(s.find_last_of(' ')+1));
    }

    void print()
	{
		cout << "day:" << day << " " << "month: " << month << " " << "year: " << year << endl;
	}
};

int main(){
    Date d1("January 1, 1900");
    Date d2("1/1/1900");
    Date d3("Jan 1 1900");

    d1.print();
    d2.print();
    d3.print();

    return 0;
}