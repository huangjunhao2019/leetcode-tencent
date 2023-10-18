#include<iostream>
using namespace std;
class A{
public:
    int a;
    int b;
};
class B:public A{
public:
    int c;
    int d;
};
int main(){
    B b;
    cout<<&(b.a)<<" "<<&(b.b)<<" "<<&(b.c)<<" "<<&(b.d)<<endl;
    return 0;
}