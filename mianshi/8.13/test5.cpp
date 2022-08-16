#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>
using namespace std;
long long solve(vector<int> &nums,int n){
    unordered_map<int,int> mp;
    long long res=0;
    for(int j=n-1;j>=0;--j){
        if(j==n-1){
            mp[nums[j]]++;
            continue;
        }
        for(int i=j-1;i>=0;--i){
            int target=3*nums[j]-nums[i];
            res+=mp[target];
        }
        mp[nums[j]]++;
    }
    return res;
}
int main(){
    string strN;
    getline(cin,strN);
    int n=stoi(strN);
    vector<int> nums(n,0);
    string input="";
    getline(cin,input);
    stringstream ss(input);
    string line="";
    int loc=0;
    while(getline(ss,line,' ')){
        nums[loc]=stoi(line);
        ++loc;
    }
    cout<<solve(nums,n);
    return 0;
}