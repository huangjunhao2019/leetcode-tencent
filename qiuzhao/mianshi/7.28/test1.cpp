#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    int index=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        if(nums[i]==-1){
            index=i;
        }
    }
    int minLeft=INT_MAX;
    int minRight=INT_MAX;
    for(int i=0;i<index;++i){
        if(nums[i]<minLeft){
            minLeft=nums[i];
        }
    }
    for(int i=index+1;i<nums.size();++i){
        if(nums[i]<minRight){
            minRight=nums[i];
        }
    }
    cout<<minLeft+minRight<<endl;
    return 0;
}