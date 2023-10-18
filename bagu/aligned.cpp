#include<iostream>
using namespace std;
struct A{
    char c;
    int i[2];
    double d;
};
struct B{
    double d;
    int i[2];
    char c;
};
int main(){
    cout<<sizeof(A)<<" "<<sizeof(B)<<endl;
    return 0;
}