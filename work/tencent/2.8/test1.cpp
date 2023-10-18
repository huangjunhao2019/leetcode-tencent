#include<iostream>
#include<unordered_map>
using namespace std;
//int res=0;
char beginCh='a';
int solve(const unordered_map<char,int> &mp){
    if(mp.empty()){
        return 0;
    }
   // cout<<beginCh<<endl;
    unordered_map<char,int> newMap;
    int res=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        int time=it->second;
        if(time==1){
            continue;
        }
        res+=time/2;
        for(int i=0;i<time/2;i++){
            if(beginCh>'z'){
                beginCh='a';
            }
            newMap[beginCh]++;
            beginCh++;
        }
        if(time%2==1){
            if(beginCh>'z'){
                beginCh='a';
            }
            newMap[beginCh]++;
            beginCh++;
        }
    }
    return solve(newMap)+res;
}
int minOperations(string str){
    unordered_map<char,int> mp;
    for(auto &ch:str){
        mp[ch]++;
    }
    return solve(mp);
}
int main(){
    string str;
    while(cin>>str){
    //    res=0;
        cout<<minOperations(str)<<endl;
    }
    return 0;
}