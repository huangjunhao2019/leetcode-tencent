#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    int s;
    cin>>s;
    int res=s-1;
    unordered_set<int> us;
    for(auto &num:nums){
        if(s%2==0 && num==s/2){
            res-=1;
            us.insert(num);
        } else if(num<s && us.find(num)==us.end() && us.find(s-num)==us.end()){
            res-=2;
            us.insert(num);
            us.insert(s-num);
        }
    }
    cout<<res<<endl;
    return 0;
}