#include<iostream> 
#include<string>
#include<fstream> 
#include<memory>
#include "TextQuery.h"
#include "Query.h"
using namespace std;



int main(){
    ifstream ifs("test.txt");
	TextQuery tq1(ifs);
	string s1, s2;
	cin >> s1 >> s2;
	Query q1(s1), q2(s2);
	Query qand = q1 & q2;
	Query qor = q1 | q2;
	print(cout, q1.eval(tq1)) << endl;
	print(cout, (~q1).eval(tq1)) << endl;
	print(cout, qand.eval(tq1)) << endl;
	print(cout, qor.eval(tq1)) << endl;
	print(cout, (~(q1 & q2) & (q1 | q2)).eval(tq1)) << endl;
	cout << q1.rep() << " " << q2.rep() << " " << qand.rep() << " " << qor.rep() << endl;
	
	Query qq1 = q1;
	qq1 = qq1;
	print(cout, qq1.eval(tq1)) << endl;
	q1 = move(qq1);
	//print(std::cout, qq1.eval(tq1)) << std::endl;
	print(cout, q1.eval(tq1)) << endl;
	qq1 = move(qand);
	print(cout, qq1.eval(tq1)) << endl;
	qand = qor;
	print(cout, qand.eval(tq1)) << endl;
	qq1 = move(qand);
	print(cout, qor.eval(tq1)) << endl;
    return 0;
}