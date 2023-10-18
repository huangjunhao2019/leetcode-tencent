#include<iostream>
#include<vector>
using namespace std;
long long cal(long long k,long long cost){
    if(cost%k==0){
        return cost/k;
    } 
    return cost/k+1;
}
int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long> nums(m+1,0);
    for(long long i=0;i<n;++i){
        long long k,cost;
        cin>>k>>cost;
        long long moneyToHong=cal(k,cost);
        for(long long j=0;j<k-1;++j){
            long long manIndex;
            cin>>manIndex;
            nums[manIndex]+=moneyToHong;
        }
    }
    for(long long i=1;i<=m;++i){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}