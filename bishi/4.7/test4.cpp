/*
5 6 2
2 1
2 3
1 1 5 1

1
*/
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<string>
#include<unordered_set>
using namespace std;
void change(vector<vector<int>> &graph,int row,int col){
    for(int i=0;i<graph.size();++i){
        for(int j=0;j<graph[i].size();++j){
            if(graph[i][j]==-1){
                continue;
            }
            graph[i][j]=min(graph[i][j],abs(i-row)+abs(j-col));
        }
    }
}
vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
int solve2(vector<vector<int>> &graph,int sr,int sc,int dr,int dc){
    queue<pair<int,int>> que;
    que.push({sr,sc});
    int res=INT_MAX;
    unordered_set<int> visit;
    visit.insert(sr*1000+sc);
    queue<int> que2;
    que2.push(graph[sr][sc]);
    bool flag=false;
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;++i){
            auto temp=que.front();
            que.pop();
            int row=temp.first;
            int col=temp.second;
            int cost=que2.front();
            if(row==dr && col==dc){
                res=min(res,cost);
            }
            que2.pop();
            for(auto &d:dir){
                int newRow=row+d[0];
                int newCol=row+d[1];
                if(visit.find(newRow*1000+newCol)!=visit.end()){
                    continue;
                }
                visit.insert(newRow*1000+newCol);
                cost=min(cost,graph[newRow][newCol]);
                que2.push(cost);
                que.push({newRow,newCol});
            }
        }
    }
    if(res==INT_MAX){
        return 0;
    }
    return res;
}
int solve(vector<vector<int>> &graph,int sr,int sc,int dr,int dc){
    return min(graph[sr][sc],graph[dr][dc]);
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> graph(n,vector<int>(m,INT_MAX));
    for(int i=0;i<k;++i){
        int row;
        int col;
        cin>>row>>col;
        graph[row-1][col]=-1;
        change(graph,row-1,col-1);
    }
    int srcRow,srcCol,desRow,desCol;
    cin>>srcRow>>srcCol>>desRow>>desCol;
    int res=solve(graph,srcRow-1,srcCol-1,desRow-1,desCol-1);
    cout<<res<<endl;
    return 0;
}
