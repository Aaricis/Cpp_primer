#include<iostream>
#include<string>
#include<memory>

#include "shared_ptr2.h"
#include "unique_ptr2.h"
#include "DebugDelete.h"
using namespace std;

template class shared_ptr2<int>;

int main(){
    shared_ptr2<int> sp(new int(3), DebugDelete()) ,sp1;;
	shared_ptr2<string> ssp(new string("12345"));
	cout << *sp << endl;
	cout << sp.unique() << " " << sp.use_count() << " " << *(sp.get()) << endl;
	cout << ssp.unique() << " " << ssp.use_count() << " " << *(ssp.get()) << endl;

	sp1 = sp;
	cout << sp1.unique() << " " << sp1.use_count() << " " << *(sp1.get()) << endl;
	sp1 = std::move(sp);
	cout << sp1.unique() << " " << sp1.use_count() << " " << *(sp1.get()) << endl;
	ssp.reset(new string("qwert"), DebugDelete());
	cout << ssp.unique() << " " << ssp.use_count() << " " << *(ssp.get()) << endl;

    unique_ptr2<int> up1(new int(3)), up2;
	cout << *up1 << " " << *(up1.get()) <<endl;
	up2 = move(up1);
	cout << *up2 << " " << *(up2.get()) << endl;
	up2 = nullptr;
	up2.reset(new int(2));
	cout << *up2 << " " << *(up2.get()) << endl;
	unique_ptr2<std::string, DebugDelete> up3(new string("12345"), DebugDelete());
	cout << *up3 << " " << *(up3.get())  << " " <<  up3->size() << endl;


    return 0;
}