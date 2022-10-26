#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int solve(vector<int> &nums,int n,int k){
    int res=0;
    vector<int> mp(n+1,0);
    for(int i=0;i<n;++i){
        mp.assign(n+1,0);
        int maxTime=0;
        for(int j=i;j<n;++j){
            mp[nums[j]]++;
            if(j-i+1<k){
                continue;
            }
            maxTime=max(maxTime,mp[nums[j]]);
            if(maxTime>=k){
                res++;
            }
        }
    }
    return res;
}
int main(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    cout<<solve(nums,n,k)<<endl;
    return 0;
}