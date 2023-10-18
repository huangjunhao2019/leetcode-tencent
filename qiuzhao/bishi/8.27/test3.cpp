/*
input:
oppoppo
output:
8
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int solve(string &s){
    int n=s.size();
    int m=4;
    vector<int> count1(n,0);
    vector<int> count2(n,0);
    int res=0;
    int oppoCount=0;
    for(int i=0;i<n;++i){
        if(s.substr(i,m)=="oppo"){
            count1[i]=1;
        }
    }
    for(int i=n-2;i>=0;--i){
        count1[i]+=count1[i+1];
        res+=count1[i];
        if(s.substr(i,m)=="oppo"){
            res+=n-4-i;
        }
    }
    
    return res;
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}