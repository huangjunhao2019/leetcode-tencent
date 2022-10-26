#include<iostream>
#include<random>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>m;
    }
    default_random_engine e1(time(0));
    cout<<e1()<<endl;
    return 0;
}