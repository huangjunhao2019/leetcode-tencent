#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(vector<int> &nums,int n){
    vector<int> dp(n,0);
    dp[0]=1; 
    for(int i=1;i<n;++i){
        if(nums[i]>nums[i-1]){
            dp[i]=dp[i-1]+1;
        } else{
            dp[i]=1;
        } 
    }
    sort(dp.begin(),dp.end());
    for(int i=1;i<=n;++i){
        auto it=lower_bound(dp.begin(),dp.end(),i);
        cout<<dp.end()-it<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    solve(nums,n);
    return 0;
}