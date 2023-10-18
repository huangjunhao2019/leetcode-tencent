#include<iostream>
using namespace std;
// #pragma pack(4)
// struct test{
//     char x1; 
//     long x3;
// };
// #pragma pack()
struct test{
    char x1;
    long x3;
};
int main(){
    test t1;
    short temp;
    cout<<sizeof(t1)<<endl;
    return 0;
}