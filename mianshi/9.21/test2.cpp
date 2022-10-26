#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> horse={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
vector<vector<int>> soldier={{0,1},{0,-1},{1,0},{-1,0}};
int res=INT_MAX;
int step=0;
void solve(vector<vector<char>> &grid,vector<vector<int>> &visit,int startX,int startY,int m,int n,bool isHorse){
    if(startX==m-1 && startY==n-1){
        res=min(res,step);
        return;
    }
    if(isHorse){
        for(auto &d:horse){
            int newX=startX+d[0];
            int newY=startY+d[1];
            if(newX<0 || newX>=m || newY<0 || newY>=n || visit[newX][newY]==1 || grid[newX][newY]=='X'){
                continue;
            }
            step++;
            visit[newX][newY]=1;
            if(grid[newX][newY]=='.'){
                solve(grid,visit,newX,newY,m,n,isHorse);
            } else{
                solve(grid,visit,newX,newY,m,n,isHorse);
                step++;
                solve(grid,visit,newX,newY,m,n,!isHorse);
                step--;
            }
            step--;
            visit[newX][newY]=0;
        }
    } else{
        for(auto &d:soldier){
            int newX=startX+d[0];
            int newY=startY+d[1];
            if(newX<0 || newX>=m || newY<0 || newY>=n || visit[newX][newY]==1 || grid[newX][newY]=='X'){
                continue;
            }
            step++;
            visit[newX][newY]=1;
            if(grid[newX][newY]=='.'){
                solve(grid,visit,newX,newY,m,n,isHorse);
            } else{
                solve(grid,visit,newX,newY,m,n,isHorse);
                step++;
                solve(grid,visit,newX,newY,m,n,!isHorse);
                step--;
            }
            step--;
            visit[newX][newY]=0;
        }
    }
}
int main(){
    int m;
    int n;
    cin>>m;
    cin>>n;
    vector<vector<char>> grid(m,vector<char>(n));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>grid[i][j];
        }
    } 
    if(grid[m-1][n-1]=='X' || grid[0][0]=='X'){
        cout<<-1<<endl;
        return 0;
    }
    bool isHorse=false;
    vector<vector<int>> visit(m,vector<int>(n,0));
    visit[0][0]=1;
    solve(grid,visit,0,0,m,n,isHorse);
    if(grid[0][0]=='S'){
        step++;
        solve(grid,visit,0,0,m,n,true);
        step--;
    }
    if(res==INT_MAX){
        cout<<-1<<endl;
    } else{
        cout<<res<<endl;
    }
    return 0;
}