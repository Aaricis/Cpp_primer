#include<iostream>
#include<utility>

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2){
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void g(int &&i, int& j)
{
	std::cout << i << " " << j << std::endl;
}


int main(){
    int i=1;
    flip(g, i, 42);
    return 0;
}