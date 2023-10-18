/*
input:
2
2 3
output:
2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void allSub(vector<pair<long long,long long>> &nums){
    for(auto &p:nums){
        if(p.second==0){
            continue;
        }
        p.second--;
    }
}
long long solve(vector<pair<long long,long long>> &nums){
    long long n=nums.size();
    long long res=0;
    for(long long i=0;i<n;++i){
        long long temp=0;
        if(nums[i].first==1 && nums[i].second!=0){
            temp=1;
        } else{
            temp=nums[i].second-(nums[i].first+1)/2;
        }
        if(temp<=0){
            allSub(nums);
        } else{
            res+=temp;
            nums[i].second-=temp;
            allSub(nums);
        }
    }
    for(auto &p:nums){
        res+=p.second;
    }
    return res;
}
int main(){
    long long n;
    cin>>n;
    vector<pair<long long,long long>> nums(n);
    long long temp;
    for(long long i=0;i<n;++i){
        cin>>temp;
        nums[i].first=temp;
        nums[i].second=temp;
    }
    sort(nums.begin(),nums.end());
    //reverse(nums.begin(),nums.end());
    cout<<solve(nums)<<endl;
    return 0;
}