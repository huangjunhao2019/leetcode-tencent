#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solve(vector<vector<int>> &graph,int p1,int p2,int p3,int k,vector<int> &a,vector<int> &h){
    int timeSum=h[p1]+h[p2]+h[p3];
    if(graph[p1][p2]!=-1 && graph[p1][p3]!=-1){
        if(timeSum+graph[p1][p2]+graph[p1][p3]<=k){
            return a[p1]+a[p2]+a[p3];
        }
    }
    if(graph[p2][p1]!=-1 && graph[p2][p3]!=-1){
        if(timeSum+graph[p2][p1]+graph[p2][p3]<=k){
            return a[p1]+a[p2]+a[p3];
        }
    }
    if(graph[p3][p1]!=-1 && graph[p3][p2]!=-1){
        if(timeSum+graph[p3][p1]+graph[p3][p2]<=k){
            return a[p1]+a[p2]+a[p3];
        }
    }
    return -1;
}
int solve2(vector<vector<int>> &graph,int p1,int p2,int k,vector<int> &a,vector<int> &h){
    int timeSum=h[p1]+h[p2];
    if(graph[p1][p2]!=-1){
        if(timeSum+graph[p1][p2]<=k){
            return a[p1]+a[p2];
        }
    }
    return -1;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> h(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cin>>h[i];
    }
    vector<vector<int>> graph(n,vector<int>(n,-1));
    for(int i=0;i<m;++i){
        int from;
        int to;
        int w;
        cin>>from>>to>>w;
        graph[from-1][to-1]=w;
        graph[to-1][from-1]=w;
    }
    int res=INT_MIN;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            int tempRes1=solve2(graph,i,j,k,a,h);
            res=max(res,tempRes1);
            for(int t=j+1;t<n;++t){
                int tempRes=solve(graph,i,j,t,k,a,h);
                res=max(res,tempRes);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}