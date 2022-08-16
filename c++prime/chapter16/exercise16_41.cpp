#include<iostream>
using namespace std;
template<typename T> auto sum(T lhs,T rhs) ->decltype(lhs+rhs){
    return lhs+rhs;
}
int main(){
    auto a=3;
    auto b=4;
    cout<<sum(a,b)<<endl;
    return 0;
}