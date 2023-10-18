#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
/*
3 def
abc
*/
void solve(int n,string &str){
    unordered_map<char,char> mp;
    for(char i='a';i<='z';++i){
        if(i=='a'){
            mp[i]='x';
        } else if(i=='b'){
            mp[i]='y';
        } else if(i=='c'){
            mp[i]='z';
        } else{
            mp[i]=i-3;
        }
    }
    for(int i=0;i<n;++i){
        str[i]=mp[str[i]];
    }
}
int main(){
    int n;
    string str;
    cin>>n;
    cin>>str;
    solve(n,str);
    cout<<str<<endl;
    return 0;
}