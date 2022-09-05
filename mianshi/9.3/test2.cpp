#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
void splitWord(string &s,vector<string> &res){
    string temp;
    stringstream ss(s);
    while(getline(ss,temp,'|')){
        res.push_back(temp);
    }
}
int main(){
    string s="湄公河大案|葫芦兄弟|少林足球"; 
    for(auto i=0;i<s.size();){
        if(s[i]>=0 && s[i]<=128){
            cout<<s[i]<<endl;
            i++;
        }
        else{
            cout<<s[i]<<endl;
            i+=2;
        }
    }
    
    return 0;
}