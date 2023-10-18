/*
5
you
thank
queue
queue
thank
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
int solve(vector<string> &strVec,int n){
    int res=0;
    unordered_map<string,int> mp;
    unordered_set<string> visit;
    for(int i=0;i<n;++i){
        if(visit.find(strVec[i])!=visit.end()){
            continue;
        }
        mp[strVec[i]]++;
        if(mp[strVec[i]]>=res+1){
            ++res;
            visit.insert(strVec[i]);
        }
    }
    return res;
}
int main(){
    long long n;
    cin>>n;
    vector<string> strVec(n);
    for(int i=0;i<n;++i){
        cin>>strVec[i];
    }
    cout<<solve(strVec,n)<<endl;

    return 0;
}