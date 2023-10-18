#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int> &nums,int idx,int maxId){
    int left=idx*2+1;
    int right=idx*2+2;
    int largestId=idx;
    if(left<maxId && nums[left]>nums[largestId]){
        largestId=left;
    }
    if(right<maxId && nums[right]>nums[largestId]){
        largestId=right;
    }
    if(largestId!=idx){
        swap(nums[idx],nums[largestId]);
        heapify(nums,largestId,maxId);
    }
}
void buildHeap(vector<int> &nums){
    for(int i=nums.size()/2-1;i>=0;--i){
        heapify(nums,i,nums.size());
    }
}
void heap_sort(vector<int> &nums){
    buildHeap(nums);
    for(int i=nums.size()-1;i>0;--i){
        swap(nums[i],nums[0]);
        heapify(nums,0,i);
    }
}
int main(){
    vector<int> nums;
    for(int i=0;i<10;++i){
        nums.push_back(10-i);
    }
    heap_sort(nums);
    for(int i=0;i<nums.size();++i){
        cout<<nums[i]<<endl;
    }
    return 0;
}