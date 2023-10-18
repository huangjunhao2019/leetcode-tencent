#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;
long long g[510][510]={0};
long long dx[4]={0,0,-1,1};
long long dy[4]={1,-1,0,0};
long long dist[510][510]={0};
bool st[510][510]={0};
using pii=pair<long long,long long>;
using arr3=array<long long,3>;
int main(){
    long long n,m;
    cin>>n>>m;
    unordered_map<long long,vector<pii>> hash;
    for(long long i=0;i<n;++i){
        for(long long j=0;j<m;++j){
            cin>>g[i][j];
            hash[g[i][j]].push_back({i,j});
        }
    }
    memset(dist,0x3f,sizeof(dist));
    auto cmp=[](const arr3 &a,const arr3 &b){
        return a[0]>b[0];
    };
    priority_queue<arr3,vector<arr3>,decltype(cmp)> que(cmp);
    que.push({0,0,0});
    dist[0][0]=0;
    while(!que.empty()){
        auto temp=que.top();
        long long d=temp[0];
        long long x=temp[1];
        long long y=temp[2];
        que.pop();
        if(st[x][y]) 
            continue;
        st[x][y]=true;
        for(long long i=0;i<4;++i){
            long long xx=x+dx[i],yy=y+dy[i];
            if(xx<0 || xx>=n || yy<0 || yy>=m || st[xx][yy]){
                continue;
            }
            long long val;
            long long t=abs(g[x][y]-g[xx][yy]);
            val=d+t;
            if(g[xx][yy]==g[0][0]){
                val=0;
            }
            if(dist[xx][yy]>val){
                dist[xx][yy]=val;
                for(auto &vec:hash[g[xx][yy]]){
                    que.push({val,vec.first,vec.second});
                }
            }
        }
    }
    cout<<dist[n-1][m-1]<<endl;
    return 0;
}
