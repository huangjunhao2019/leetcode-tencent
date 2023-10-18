#include<iostream>
#include<string>
using namespace std;
long long solve(long long n,long long a,long long b,string &hurt){
    long long res=0;
    long long count=0;
    for(long long i=0;i<n;++i){
        res+=a+count*b;
        if(hurt[i]=='o'){
            ++count;
        } else{
            count=0;
        }
    }
    return res;
}
long long main(){
    long long n,a,b;
    cin>>n>>a>>b;
    string hurt;
    cin>>hurt;
    long long res=solve(n,a,b,hurt);
    cout<<res<<endl;
    return 0;
}