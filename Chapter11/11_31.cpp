#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	multimap<string, string> mumap = { {"ben","think in C++"},{ "rock", "C++ Primer" }, { "rock", "the C program" }, { "li", "hackers" }, { "li", "C++ primer plus" } };  
	string keyword;  
	cout << "请输入要删除的关键字:";  
	cin >> keyword;  
	auto cnt = mumap.count(keyword);  
	if (cnt == 0)  
	{  
		cout << "要删除的关键字" << keyword << "不在mumpa中" << endl;  
	}  
	else  
	{  
		while (cnt){  
			auto iter = mumap.find(keyword);  
			mumap.erase(iter);  
			--cnt;  
		}  
		cout << "删除成功，删除后的mumap内的内容为：" << endl;  
		for (const auto &w : mumap)  
			cout << w.first << " " << w.second << endl;  
	}  
  
    return 0;
}