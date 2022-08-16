#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &nums,int left,int right){
    int pivot=nums[left];
    while(left<right){
        while(left<right && nums[right]>=pivot){
            right--;
        }
        nums[left]=nums[right];
        while(left<right && nums[left]<=pivot){
            left++;
        }
        nums[right]=nums[left];
    }
    nums[left]=pivot;
    return left;
}
void quick_sort(vector<int> &nums,int left,int right){
    if(left<right){
        int pivot=partition(nums,left,right);
        quick_sort(nums,left,pivot-1);
        quick_sort(nums,pivot+1,right);
    }
}
int main(){
    vector<int> nums;
    for(int i=0;i<10;i++){
        nums.push_back(10-i);
    }
    quick_sort(nums,0,nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}
