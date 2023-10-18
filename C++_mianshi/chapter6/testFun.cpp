#include<iostream>
using namespace std;
int add(int a,int b){
    return a+b;
}
void fun(int (*pf)(int,int),int a ,int b){
    cout<<pf(a,b)<<endl;
}
int main(){
    fun(add,1,3);
    return 0;
}