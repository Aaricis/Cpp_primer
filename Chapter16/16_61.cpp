#include<iostream>
#include<memory>
#include<string>
#include<utility>
using namespace std;

template <typename T, typename... Args>
auto make_shared2(Args&&... args)->shared_ptr<T>{
    return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
    auto num = make_shared2<int>(42);
    cout << *num << endl;

    auto str = make_shared2<string>(10, 'c');
    cout << *str << endl;
    
    return 0;
}
