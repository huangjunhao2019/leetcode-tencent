#include<iostream>
#include<vector>
#include<string>
using namespace std;
int res=0;

void backTrack(vector<vector<int>> &alNums,int n,vector<int> visit,int start){
    if(start>=n){
        ++res;
        return ;
    }
    for(int i=0;i<26;++i){
        if(alNums[start][i]==0){
            continue;
        }
        if(visit[i]==1){
            continue;
        }
        visit[i]=1;
        backTrack(alNums,n,visit,start+1);
        visit[i]=0;
    }
}
int main(){
    int N;
    cin>>N;
    vector<vector<int>> alphaNums(N,vector<int>(26,0));
    string str;
    for(int i=0;i<N;++i){
        cin>>str;
        for(auto &ch:str){
            alphaNums[i][ch-'a']=1;
        }
    }
    vector<int> visit(26,0);
    backTrack(alphaNums,N,visit,0);
    cout<<res<<endl;
    return 0;
}