#include<iostream>
using namespace std;

void test(){
    static int a=0;
    a++;
    cout<<a<<endl;
}
int main(){
    for(int i=0;i<10;i++){
        test();
    }
    return 0;
}