#include<iostream>
using namespace std;
//尾置返回类型,206
auto fun(int a,int b)->int{
    return a+b;
}
int main(){
    cout<<fun(10,5)<<endl;
    return 0;
}