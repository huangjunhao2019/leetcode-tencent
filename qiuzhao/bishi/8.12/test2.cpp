/*
3
1 2 2
2 3
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long solve(vector<long long> &nums,long long start,long long end){
    long long n=nums.size();
    long long res1=0;
    for(long long i=start;i<end;++i){
        
        res1+=nums[i];
    }
    long long res2=0;
    for(long long i=end;i!=start;i=(i+1)%n){
        
        res2+=nums[i%n];
    }
    return min(res1,res2);
}
int main(){
    long long n;
    cin>>n;
    vector<long long> nums(n,0);
    for(long long i=0;i<n;++i){
        cin>>nums[i];
    }
    long long start;
    long long end;
    cin>>start>>end;
    if(start>end){
        swap(start,end);
    }
    long long res=solve(nums,start-1,end-1);
    cout<<res<<endl;
    return 0;
}