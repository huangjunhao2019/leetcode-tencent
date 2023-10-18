#include<iostream>
#include<vector>
using namespace  std;
long long solve(vector<long long> &sizeBottle,vector<long long> &initSize, vector<long long> &cost,long long n,long long index){
    --index;
    if(initSize[index]==sizeBottle[index]){
        return 0;
    }
    long long res=cost[index]*(sizeBottle[index]-initSize[index]);
    for(int i=0;i<index;++i){ 
        long long resSize=0;
        for(int j=i;j<=index;++j){
            resSize+=sizeBottle[j]-initSize[j];
        }
        res=min(res,resSize*cost[i]);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<long long> sizeBottle(n);
    for(int i=0;i<n;++i){
        cin>>sizeBottle[i];
    }
    vector<long long> initSize(n);
    for(int i=0;i<n;++i){
        cin>>initSize[i];
    }
    vector<long long> cost(n);
    for(int i=0;i<n;++i){
        cin>>cost[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;++i){
        long long index;
        cin>>index;
        long long res=solve(sizeBottle,initSize,cost,n,index);
        if(i!=m-1){
            cout<<res<<" ";
        } else{
            cout<<res<<endl;
        }
    } 
    return 0;
}