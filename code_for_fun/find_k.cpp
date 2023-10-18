#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &nums,int left,int right){
    int pivot=nums[left];
    while(left<right){
        while(left<right && nums[right]<=pivot){
            --right;
        }
        nums[left]=nums[right];
        while(left<right && nums[left]>=pivot){
            ++left;
        }
        nums[right]=nums[left];
    }
    nums[left]=pivot;
    return left;
}
int find_k(vector<int> &nums,int k,int left,int right){
    int pivot=partition(nums,left,right);
    if(pivot==k-1){
        return nums[pivot];
    } else if(pivot>k-1){
        return find_k(nums,k,left,pivot-1);
    } else{
        return find_k(nums,k,pivot+1,right);
    }
}
int main(){
    vector<int> nums;
    for(int i=0;i<10;++i){
        nums.push_back(10-i*2);
    }
    int k=3;
    cout<<find_k(nums,k,0,nums.size()-1)<<endl;
    return 0;
}