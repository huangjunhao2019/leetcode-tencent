#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void solve(vector<int> &nums,int n){
    int count=0;
    for(int i=1;i<=n;++i){
        if(i==nums[i]){
            continue;
        }
        int aimLoc=nums[i];
        
    }

}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n+1,0);
    nums[0]=-1;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    solve(nums,n);
    return 0;
}