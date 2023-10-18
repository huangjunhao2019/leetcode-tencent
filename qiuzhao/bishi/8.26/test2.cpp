#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> nums(n,0);
    for(long long i=0;i<n;++i){
        cin>>nums[i]; 
    }
    unordered_map<int,int> valToIndex;
    vector<int> preSum(n+1,0);
    valToIndex[0]=0;
    int res=-1;
    for(int i=0;i<n;++i){
        preSum[i+1]=preSum[i]+nums[i];
        if(valToIndex.find(preSum[i+1]-(i+1)*k)!=valToIndex.end()){
            res=max(res,i+1-valToIndex[preSum[i+1]-(i+1)*k]);
        } else{
            valToIndex[preSum[i+1]-(i+1)*k]=i+1;
        }
    }
    cout<<res<<endl;
    return 0;
}