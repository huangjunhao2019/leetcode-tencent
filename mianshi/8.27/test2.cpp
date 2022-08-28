#include<unordered_set>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
bool solve(vector<string> &vec,unordered_set<string> &zhu,unordered_set<string> &wei,unordered_set<string> &bin){
    if(zhu.find(vec[0])==zhu.end()){
        return false;
    }
    int weiIndex=-1;
    int weiCount=0;
    for(int i=1;i<vec.size();++i){
        if(wei.find(vec[i])!=wei.end()){
            weiIndex=i;
            weiCount+=1;
        }
    }
    if(weiCount!=1){
        return false;
    }
    for(int i=0;i<weiIndex;++i){
        if(zhu.find(vec[i])==zhu.end()){
            return false;
        }
    }
    for(int i=weiIndex+1;i<vec.size();++i){
        if(bin.find(vec[i])==bin.end()){
            return false;
        }
    }
    return true;
}
int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    unordered_set<string> zhu;
    unordered_set<string> wei;
    unordered_set<string> bin;
    string temp;
    for(int i=0;i<n1;++i){
        cin>>temp;
        zhu.insert(temp);
    }
    for(int i=0;i<n2;++i){
        cin>>temp;
        wei.insert(temp);
    }
    for(int i=0;i<n3;++i){
        cin>>temp;
        bin.insert(temp);
    }
    int m;
    cin>>m;
   // cout<<m<<endl;
    cin.ignore();
    int count=0;
    while(getline(cin,temp)){
       // cout<<"hello"<<endl;
        ++count;
        stringstream ss(temp);
        vector<string> vecStr;
        string tempStr;
        while(ss>>tempStr){
            vecStr.push_back(tempStr);
        }
        bool flag=solve(vecStr,zhu,wei,bin);
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        if(count==m){
            return 0;
        }
    }
    return 0;
}