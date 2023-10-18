/*
input:
5
wovv
bod
pdd
moom
lalalai

output:
YES
YES
YES
YES
NO
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isOk(string &s){
    long long left=0;
    long long right=s.size()-1;
    while(left<right){
        if(s[left]!=s[right]){
            return true;
        } else{
            ++left;
            --right;
        }
    }
    return true;
}
bool backTrack(string &s,long long start,string path){
    if(isOk(s)){
        return true;
    }
    if(start>=s.size()){
        return isOk(path);
    }
    for(long long i=start;i<s.size();++i){
        if(s[i]=='w'){
            if(backTrack(s,i+1,path+s[i])){
                return true;
            }
            if(backTrack(s,i+1,path+"vv")){
                return true;
            }
        } else if(s[i]=='m'){
            if(backTrack(s,i+1,path+s[i])){
                return true;
            }
            if(backTrack(s,i+1,path+"nn")){
                return true;
            }
        } else{
            path.push_back(s[i]);
        }
    }
    if(isOk(path)){
        return true;
    }
    return false;
}
void change(string &s){
    for(long long i=0;i<s.size();++i){
        if(s[i]=='d' || s[i]=='p' || s[i]=='q'){
            s[i]='b';
        } else if(s[i]=='u'){
            s[i]='n';
        }
    }
}
int main(){
    long long n;
    cin>>n;
    string temp;
    string path="";
    for(long long i=0;i<n;++i){
        cin>>temp;
        change(temp);
        if(backTrack(temp,0,path)){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}