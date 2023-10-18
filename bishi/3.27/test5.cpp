#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
long long res=0;
long long mod=1e9+7;
vector<int> path;
int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
bool isOk(vector<int> &path,int k){
    if(path.size()==1){
        return path[0]==k;
    }
    int tempRes=INT_MAX;
    for(int i=0;i<path.size()-1;++i){
        tempRes=min(tempRes,gcd(path[i],path.back()));
    }
    return tempRes==k;
}
void backTrack(vector<int> &nums,int start,int k){
    if(start>nums.size()){
        return ;
    }
    if(!path.empty() && isOk(path,k)){
        res=(res+1)%mod;
    }
    int n=nums.size();
    for(int i=start;i<n;++i){
        path.push_back(nums[i]);
        backTrack(nums,i+1,k);
        path.pop_back();
    }
}
int main(){
    int n,k;
   // cout<<gcd(6,9)<<endl;
    cin>>n>>k;
    vector<int> nums;
    nums.reserve(n);
    int temp;
    for(int i=0;i<n;++i){
        cin>>temp;
        if(temp%k==0){
            nums.push_back(temp);
        }
    }
    sort(nums.begin(),nums.end());
    backTrack(nums,0,k);
    cout<<res<<endl;
    return 0;
}