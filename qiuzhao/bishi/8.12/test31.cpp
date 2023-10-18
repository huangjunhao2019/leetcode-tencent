#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>> cake(n,vector<long long>(m,0));
    long long allSum=0;
    for(long long i=0;i<n;++i){
        for(long long j=0;j<m;++j){
            cin>>cake[i][j];
            allSum+=cake[i][j];
        }
    }
    long long rowSum=0;
    long long res=allSum;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            rowSum+=cake[i][j];
        }
        res=min(res,abs(allSum-rowSum-rowSum));
    }
    long long colSum=0;
    for(int j=0;j<m;++j){
        for(int i=0;i<n;++i){
            colSum+=cake[i][j];
        }
        res=min(res,abs(allSum-colSum-colSum));
    }
    cout<<res<<endl;
    return 0;
}