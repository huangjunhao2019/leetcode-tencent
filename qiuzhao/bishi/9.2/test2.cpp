#include<iostream>

using namespace std;
class A{
    int a1;
public:
    A(int x=2):a1(x){}
    void f1(){cout<<a1;}
    A operator ++(int){
        A T=*this;
        a1++;
        return T;
    }
    friend A operator++(A &p){
        ++p.a1;
        return p;
    }

};
int main(){
    A ob1;
    (++ob1).f1();
    operator++(ob1).f1();
    operator++(ob1,0).f1();
    
    return 0;
}