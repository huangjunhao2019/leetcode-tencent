#include<iostream>
#include<random>
using namespace std;
unsigned randomFunc(){
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u;
    return u(e);
}
unsigned randomFunc(unsigned i){
    static default_random_engine e(i);
    static uniform_int_distribution<unsigned> u;
    return u(e);
}
unsigned randomFunc(unsigned i,unsigned min,unsigned max){
    static default_random_engine e(i);
    static uniform_int_distribution<unsigned> u(min,max);
    return u(e);
}
int main(){
    cout<<randomFunc()<<endl;
    cout<<randomFunc(2)<<endl;
    for(int i=0;i<10;++i){
        cout<<randomFunc(1,0,10)<<endl;
    }
    return 0;
}