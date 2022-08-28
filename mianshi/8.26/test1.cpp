#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solution(string &s){
    unordered_map<string,int> mp;
    string temp(26,'0');
    mp[temp]=-1;
    int res=0;
    for(int i=0;i<s.size();++i){
        int index=s[i]-'a';
        if(temp[index]=='0'){
            temp[index]='1';
        }
        else{
            temp[index]='0';
        }
        if(mp.find(temp)==mp.end()){
            mp[temp]=i;
        }
        else{
            res=max(res,i-mp[temp]);
        }
    }
    return res;
}
int main(){
    string s;
    while(cin>>s){
        cout<<solution(s)<<endl;
    }
    return 0;
}