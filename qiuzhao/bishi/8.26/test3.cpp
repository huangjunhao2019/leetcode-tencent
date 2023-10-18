#include<iostream>
#include<vector>
using namespace std;
long long main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> nums(n,0);
    for(long long i=0;i<n;++i){
        cin>>nums[i];
    }
    vector<long long> preSum(n+1,0);
    for(long long i=0;i<n;++i){
        preSum[i+1]=preSum[i]+nums[i];
    }
    long long res=-1;
    for(long long i=0;i<=n;++i){
        for(long long j=i+res;j<=n;++j){
            if(preSum[j]-preSum[i]==(j-i)*k){
                res=max(res,j-i);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}