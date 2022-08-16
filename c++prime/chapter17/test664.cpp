#include<iostream>
#include<random>
using namespace std;
int main(){
    default_random_engine e;
    uniform_real_distribution<double> u(0,1);
    for(int i=0;i<10;++i){
        cout<<u(e)<<endl;
    }
    return 0;
}