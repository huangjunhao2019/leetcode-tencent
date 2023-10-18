#include<iostream>
#include<vector>
using namespace std;
long long solve(int a,int b){
    int res1=a-b;
    int res2=a-(-1)*b;
    int res3=(-1)*a-b;
    int res4=(-1)*a-(-1)*b;
    return min(min(abs(res1),abs(res2)),min(abs(res3),abs(res4)));
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    long long res=0;
    for(int i=0;i<n;++i){
        res+=solve(a[i],b[i]);
    }
    cout<<res<<endl;
    return 0;
}