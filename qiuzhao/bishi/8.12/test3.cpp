#include<iostream>
#include<vector>
using namespace std;
long long solve(vector<vector<long long>> &cake,long long n,long long m){
    vector<long long> rowSum(n,0);
    vector<long long> colSum(m,0);
    long long allSum=0;
    for(long long i=0;i<n;++i){
        for(long long j=0;j<m;++j){
            rowSum[i]+=cake[i][j];
            colSum[j]+=cake[i][j];
            allSum+=cake[i][j];
        }
    }
    for(int i=0;i<n;++i){
        if(i>0){
            rowSum[i]+=rowSum[i-1];
        }
    }
    for(int j=0;j<m;++j){
        if(j>0){
            colSum[j]+=colSum[j-1];
        }
    }
    long long res=allSum;
    for(long long i=0;i<n;++i){
        res=min(res,abs(allSum-rowSum[i]-rowSum[i]));
    }
    for(long long j=0;j<m;++j){
        res=min(res,abs(allSum-colSum[j]-colSum[j]));
    }
    return res;
}
int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>> cake(n,vector<long long>(m,0));
    for(long long i=0;i<n;++i){
        for(long long j=0;j<m;++j){
            cin>>cake[i][j];
        }
    }
    long long res=solve(cake,n,m);
    cout<<res<<endl;
    return 0;
}