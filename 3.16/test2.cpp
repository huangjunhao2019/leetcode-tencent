#include<iostream>
#include<vector>
using namespace std;
long long res=-1;
long long sum=0;

void backTrack(vector<vector<pair<int,int>>> &thing,int x,int start){
    if(start>=thing.size()){
        res=max(res,sum);
      //  cout<<sum<<endl;
        return ;
    }
    int m=thing[start].size();
    for(int i=0;i<m;++i){
        if(x<thing[start][i].first){
            continue;
        }
        x-=thing[start][i].first;
        sum+=thing[start][i].second;
        backTrack(thing,x,start+1);
        sum-=thing[start][i].second;
        x+=thing[start][i].first;
    }
}
long long solve(vector<vector<pair<int,int>>> &thing,int x){
    backTrack(thing,x,0);
    return res;
}
int main(){
    int n,x; //n是零件数量，x是总预算
    cin>>n>>x;
    vector<vector<pair<int,int>>> thing;
    for(int i=0;i<n;++i){
        int m;
        cin>>m;
        vector<pair<int,int>> pvec(m);
        for(int i=0;i<m;++i){
            cin>>pvec[i].first;
        }
        for(int i=0;i<m;++i){
            cin>>pvec[i].second;
        }
        thing.push_back(pvec);
    }
    cout<<solve(thing,x)<<endl;
    return 0;
}