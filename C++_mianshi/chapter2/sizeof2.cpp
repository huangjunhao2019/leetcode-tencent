#include<iostream>
using namespace std;
int main(){
    char a='a';
    char *p1=&a;
    int b=0;
    int *p2=&b;
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    return 0;
}