#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<set>
using namespace std;
int solution(vector<int> &nums,int m){
    if(nums.empty()){
        return 0;
    }
    unordered_map<int,int> mp;
    set<int> st;
    int res=1;
    int maxVal=INT_MIN;
    int minVal=INT_MAX;
    for(auto &num:nums){
        ++mp[num];
        st.insert(num);
    }
    for(auto num:nums){
        if(mp.find(num)==mp.end()){
            continue;
        }
        int count=0;
        int temp=num;
        while(!st.empty() && temp<=*st.rbegin()){
            if(mp.find(temp)!=mp.end()){
                count+=mp[temp];
                mp.erase(temp);
                st.erase(temp);
            }
            temp+=m;
        }
        temp=num-m;
        while(!st.empty() && temp>=*st.begin()){
            if(mp.find(temp)!=mp.end()){
                count+=mp[temp];
                mp.erase(temp);
                st.erase(temp);
            }
            temp-=m;
        }
        res=max(res,count);
    }
    return res;
}
int main(){
   // vector<int> nums={7,1,11,8,4,10};
    vector<int> nums={-3,-2,1,0,8,7,1};
    cout<<solution(nums,3)<<endl;
    return 0;
}