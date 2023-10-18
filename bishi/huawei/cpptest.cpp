#include<iostream>
using namespace std;

class A
{
    public:
    A(){
        cout << "0";
    }
    A(const A& a)
    {
        cout << "1";
    }
    ~A()
    {
        cout << "2";
    }
};
A func()
{
    A a;
    return a;
}
int main()
{
     A b = func();
}