#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
vector<int> monthVec={0,31,28,31,30,31,30,31,31,30,31,30,31};
int countDay(const string &month,const string &day){
    int monthNum=(month[0]-'0')*10+(month[1]-'0');
    int dayNum=(day[0]-'0')*10+(day[1]-'0');
    int res=0;
    for(int i=1;i<monthNum;++i){
        res+=monthVec[i];
    }
    res+=dayNum;
    return res;
}
void dayProcess(vector<unordered_set<string>> &day,string &str){
    int firstLoc=0;
    int spaceLoc=0;
    for(int i=0;i<str.size();++i){
        if(str[i]=='-'){
            firstLoc=i;
            break;
        }
        if(str[i]==' '){
            spaceLoc=i;
        }
    }
    string name=str.substr(0,spaceLoc);
    string month=str.substr(firstLoc+1,2);
    string dayStr=str.substr(firstLoc+4,2);
    int dayNum=countDay(month,dayStr);
    day[dayNum].insert(name);
    
}
int solve(vector<unordered_set<string>> &day,int n){
    int left=1;
    int right=1;
    unordered_map<string,int> mp;
    int res=-1;
    while(left<day.size() && right<day.size()){
        while(right<day.size() && mp.size()<n){
            for(auto &name:day[right]){
                mp[name]++;
            }
            ++right; 
        }
        if(mp.size()>=n){
            if(res==-1){
                res=right-left;
            } else{
                res=min(res,right-left);
            }
        }
        for(auto &name:day[left]){
            mp[name]--;
            if(mp[name]==0){
                mp.erase(name);
            }
        }
        ++left;
    }
    return res;
}
int main(){
    int k;
    cin>>k;
    cin.ignore();
    string temp;
    vector<unordered_set<string>> day(370);
    for(int i=0;i<k;++i){
        getline(cin,temp);
        dayProcess(day,temp);
    }
    int n;
    cin>>n;
    int res=solve(day,n);
    cout<<res<<endl;
    return 0;
}