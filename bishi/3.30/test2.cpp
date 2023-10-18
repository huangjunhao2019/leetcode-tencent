/*给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

输入：nums = [-1,0,1,2,-1,-4]
[-4,-1,-1,0,1,2]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve1(vector<int> &nums,vector<vector<int>> &res){
    //{-4,-1,-1,0,1,2}
    for(int i=0;i<nums.size();++i){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        for(int j=i+1;j<nums.size();++j){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            for(int k=j+1;k<nums.size();++k){
                if(k>j+1 && nums[k]==nums[k+1]){
                    continue;
                }
                if(nums[i]+nums[j]+nums[k]==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
    }
}
void solve(vector<int> &nums,vector<vector<int>> &res){
    for(int i=0;i<nums.size();++i){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int left=i+1;
        int right=nums.size()-1;
        while(left<right){
            if(nums[left]+nums[right]<-1*nums[i]){
                ++left;
            } else if(nums[left]+nums[right]>-1*nums[i]){
                --right;
            } else{
                res.push_back({nums[i],nums[left],nums[right]});
                int initLeftVal=nums[left];
                int initRightVal=nums[right];
                while(left<right && nums[left]==initLeftVal){
                    ++left;
                }
                while(left<right && nums[right]==initRightVal){
                    --right;
                }
            }
        }
    }
}
int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    //{-4,-1,-1,0,1,2}
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    solve(nums,res);
    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[i].size();++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}