#include<iostream>
using namespace std;
#pragma pack(4)
struct test{
    char x1;
    long long x2;
};
#pragma pack()
int main(){
    test t;
    cout<<sizeof(t)<<endl;
    return 0;
}