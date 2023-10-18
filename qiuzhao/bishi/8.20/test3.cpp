#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
6 6 1 2
1 1
2 2 3
5 3 3 3 4 2
3 4 5 6
1 1
1 2
*/
vector<int> path;
vector<string> res;
bool isOk1(vector<vector<int>> &groups,vector<int> &path,int index,int a,int b,vector<int> &aNum,vector<int> bNum){
    for(int i=0;i<path.size();++i){
        int tempIndex=path[i];
        if(aNum[tempIndex]==1 && aNum[index]==1 || bNum[tempIndex]==1 && bNum[index]==1){
            return false;
        }
    }
    return true;
}
string vec2string(vector<int> &path){
    string res="";
    for(int i=0;i<path.size();++i){
        res+=to_string(path[i]+1)+",";
    }
    return res;
}
bool isOk2(vector<int> &path,vector<int> &aNum,vector<int> &bNum){
    int aCount=0;
    int bCount=0;
    for(auto index:path){
        aCount+=aNum[index];
        bCount+=bNum[index];
    }
    return aCount==1 && bCount==1;
}
void backTrack(vector<vector<int>> &groups,int start,int m,int count,int a,int b,vector<int> &aNum,vector<int> &bNum){
    if(count==m){
        if(isOk2(path,aNum,bNum)){
            res.push_back(vec2string(path));
        }
        return ;
    }
    if(count>m){
        return ;
    }
   
    for(int i=start;i<groups.size();++i){
        if(count+groups[i].size()>m){
            continue;
        }
        if(isOk1(groups,path,i,a,b,aNum,bNum)){
            path.push_back(i);
            backTrack(groups,i+1,m,count+groups[i].size(),a,b,aNum,bNum);
            path.pop_back();
        }
    }
}
void printStr(string &s){
    int left=0;
    int right=0;
    while(right<s.size()){
        while(right<s.size() && s[right]!=','){
            ++right;
        }
        if(right==s.size()-1){
            cout<<s.substr(left,right-left)<<endl;
        } else{
            cout<<s.substr(left,right-left)<<" ";
        }
        ++right;
        left=right;
    }
}
int to_int(string s){
    int res=0;
    for(int i=0;i<s.size();++i){
        res=res*10+s[i]-'0';
    }
    return res;
}
bool isOk3(string &s,vector<int> &visit){
    int left=0;
    int right=0;
    while(right<s.size()){
        while(right<s.size() && s[right]!=','){
            ++right;
        }
        int num=stoi(s.substr(left,right-left));
        if(visit[num]==1){
            return false;
        }
        ++right;
        left=right;
    }
    return true;
}
void change(vector<int> &visit,string &s){
    int left=0;
    int right=0;
    while(right<s.size()){
        while(right<s.size() && s[right]!=','){
            ++right;
        }
        int num=stoi(s.substr(left,right-left));
        visit[num]=1;
        ++right;
        left=right;
    }
}
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<vector<int>> groups(n);
    vector<int> aNum(n);
    vector<int> bNum(n);
    for(int i=0;i<n;++i){
        int count=0;
        cin>>count;
        int aCount=0;
        int bCount=0;
        for(int j=0;j<count;++j){
            int temp;
            cin>>temp;
            groups[i].push_back(temp);
            if(temp==a){
                aCount++;
            } else if(temp==b){
                bCount++;
            }
        }
        aNum[i]=aCount;
        bNum[i]=bCount;
    }
    backTrack(groups,0,m,0,a,b,aNum,bNum);
    sort(res.begin(),res.end());
    vector<int> visit(n+1,0);
    for(int i=0;i<res.size();++i){
        if(isOk3(res[i],visit)){
            change(visit,res[i]);
            printStr(res[i]);
        }
    }
    return 0;
}