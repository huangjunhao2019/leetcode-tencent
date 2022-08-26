#include<iostream>
#include<vector>
using namespace std;
int res=0;
vector<int> path;
void chooseMax(vector<int> &nums,int start,int k){
    if(start>=nums.size()){
        return;
    }
    if(path.size()==k){
        int temp=path[0];
        for(int i=1;i<path.size();++i){
            temp&=path[i];
        }
        res=max(temp,res);
        return;
    }
    for(int i=start;i<nums.size();++i){
        path.push_back(nums[i]);
        chooseMax(nums,i+1,k);
        path.pop_back();
    }
}
int main(){
    int k;
    int n;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    chooseMax(nums,0,k);
    cout<<res<<endl;
    return 0;
}