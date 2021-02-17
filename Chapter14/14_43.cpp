#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using namespace std::placeholders;

int main(){
    vector<int> vec = {4, 6, 10};
	int n = 0;
	cin >> n;

    auto check_func = modulus<int>();

	bool can_modulus = true;
	for (auto i : vec)
	{
		if (check_func(i, n) != 0)
		{
			can_modulus = false;
			break;
		}
	}

	cout << "Can modulus: " << can_modulus << endl;
    return 0;
}
