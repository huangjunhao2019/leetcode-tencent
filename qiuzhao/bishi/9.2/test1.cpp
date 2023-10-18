#include<iostream>
#include<vector>
using namespace std;

const int mod=1e9+7;

vector<int> path;
int res=0;
bool isOk(vector<int> &path,int num){
    for(int i=0;i<path.size();++i){
        if(path[i]%num!=0 && num%path[i]!=0){
            return false;
        }
    }
    return true;
}
void backTrack(vector<int> &nums,int start,int n,int k){
    if(path.size()==n-k){
        res++;
        return ;
    }
    for(int i=start;i<n;++i){
        if(isOk(path,nums[i])){
            path.push_back(nums[i]);
            backTrack(nums,i+1,n,k);
            path.pop_back();
        }
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    backTrack(nums,0,n,k);
    cout<<res<<endl;
    return 0;
}
int solve2(vector<int> &nums,int n,int k){
    vector<vector<long long>> dp(n+1,vector<long long>(k+1,0));
    for(int i=0;i<=n;++i){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }
    for(int i=0;i<=n;++i){
        for(int j=0;j<=k;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    long long res=0;
    for(int i=1;i<=n;++i){
        res=(res+dp[i][k])%mod;
    }
    return res;
}