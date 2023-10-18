#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &nums){
    int n=nums.size();
    vector<int> muxSum(n+1,1);
    vector<int> xorSum(n+1,0);
    for(int i=0;i<n;++i){
        muxSum[i+1]=muxSum[i]*(int)nums[i];
        xorSum[i+1]=xorSum[i]^(int)nums[i];
    }
    int res=0;
    for(int i=0;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if((muxSum[j]/muxSum[i])==(xorSum[j]^xorSum[i])){
                ++res;
            }
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    cout<<solve(nums)<<endl;
    return 0;
}