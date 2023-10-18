#include<iostream>
using namespace std;
#pragma pack(8)
struct s1{
    short a;
    long b;
};
struct s2{
    short c;
    s1 d;
    long long e;
};
struct s3{
    short var0;
    int var1;
    long var2;
    char var3;
   // string s;
};
#pragma pack()
int main(){
    long c;
    cout<<sizeof(c)<<endl;
    s1 t1;
    s2 t2;
    cout<<sizeof(s1)<<" "<<sizeof(t2)<<endl;
    s3 t3;
    cout<<sizeof(t3)<<endl;
    return 0;
}