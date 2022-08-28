#include<iostream>
using namespace std;
const long long mod = 1e9+7;
long long choose(int n){
    long long res=0;
    for(int i=2;i<n;++i){
        if(i+1>n-3){
            continue;
        }
        //cout<<"i= "<<i<<endl;
        res+=(n-3)-(i+1)+1;
    }
    return res;
}
long long solve(int n){
    if(n<6){
        return 0;
    }
    if(n==6){
        return 1;
    }
    long long res=choose(n);//n里面选择6个
    cout<<"choose "<<res<<endl;
    for(int i=0;i<n-6;++i){
        res=res*2%mod;
        res=res*13%mod;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}