#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int solve(vector<int> &nums,int n,int k){
    unordered_map<int,int> locMp;
    for(int i=0;i<n;++i){
        locMp[nums[i]]=i;
    }
    int res=0;
    vector<int> newNums(nums.begin(),nums.end());
    sort(newNums.begin(),newNums.end());
    for(int i=0;i<n-1;++i){
      //  cout<<newNums[i]<<" "<<newNums[i+1]<<" "<<locMp[newNums[i]]<<" "<<locMp[newNums[i+1]]<<endl;
        if(locMp[newNums[i]]>locMp[newNums[i+1]]){
            locMp[newNums[i]]=i;
            locMp[newNums[i+1]]=i+1;
            ++res;
        }
    }
    return res;
}
int main(){
    int T;
    int n,k;
    cin>>T;
    for(int i=0;i<T;++i){
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;++i){
            cin>>nums[i];
        }
        cout<<solve(nums,n,k)<<endl;
    }
    return 0;
}