/*
1,4,2,5,5,1,6
13
2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long getSum(vector<long long> &nums,long long left,long long right){
    long long res=0;
    for(long long i=left;i<=right;++i){
        res+=nums[i];
    }
    return res;
}
long long getSum2(vector<long long> &nums,long long mid){
    long long res=0;
    for(auto &num:nums){
        if(num<=mid){
            res+=num;
        } else{
            res+=mid;
        }
    }
    return res;
}
long long solve(vector<long long> &nums,long long hexinSum){
    long long n=nums.size();
    long long sumOfNums=getSum(nums,0,n-1);
    if(sumOfNums<=hexinSum){
        return -1;
    }
    long long left=-1;
    long long right=nums.back()+1;
    long long res=0;
    while(left+1<right){
        long long mid=left+(right-left)/2;
        long long tempSum=getSum2(nums,mid);
        if(tempSum<=hexinSum){
            res=max(res,mid);
            left=mid;
        } else{
            right=mid;
        }
    }
    return left;
    // while(left<=right){
    //     long long mid=left+(right-left)/2;
    //     long long tempSum=getSum2(nums,mid);
    //     if(tempSum<=hexinSum){
    //         res=max(res,mid);
    //         left=mid+1;
    //     } else{
    //         right=mid-1;
    //     }
    // }
   // return res;
}
int main(){
    vector<long long> nums;
    long long temp;
    while(cin>>temp){
        nums.push_back(temp);
    }
    long long n=nums.size();
    vector<long long> nums2(nums.begin(),nums.begin()+n-1);
    long long hexinSum=nums[n-1];
    sort(nums2.begin(),nums2.end());
    cout<<solve(nums2,hexinSum);
    return 0;
}