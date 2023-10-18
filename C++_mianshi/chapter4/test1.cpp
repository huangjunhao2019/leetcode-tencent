#include<iostream>
using namespace  std;
class Base1{//4
public:
    int var1;
};
class Base2:virtual public Base1{//8
    public:
        int var2;
};
class Base3:virtual public Base1{//8
public:
    int var3;
};
class Derive:public Base2,public Base3{//8+8+4
public:
    char var4;
};
class Derive2{
public:
    Base2 b2;//8
    Base3 b3;//8
    char var4;
};
int main(){
    Derive d;
    cout<<sizeof(d)<<endl;
    Derive2 d2;
    cout<<sizeof(d2)<<endl;
    cout<<sizeof(d2.b2)<<endl;
    cout<<sizeof(d2.b3)<<endl;
    long c;
    cout<<sizeof(c)<<endl;
    return 0;
}

