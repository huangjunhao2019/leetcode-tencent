/*
9
aababbabb
*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
vector<vector<int>> neigh={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(vector<vector<char>> &grid,int row,int col,int rowNum,int colNum,int n){
    queue<pair<int,int>> que;
    que.push({row,col});
    char pivot=grid[row][col];
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;++i){
            auto temp=que.front();
            que.pop();
            grid[temp.first][temp.second]='-';
            for(auto &newLoc:neigh){
                int newRow=temp.first+newLoc[0];
                int newCol=temp.second+newLoc[1];
                if(newRow>=0 && newRow<rowNum && newCol>=0 && newCol<colNum && grid[newRow][newCol]==pivot){
                    que.push({newRow,newCol});
                    grid[newRow][newCol]='-';
                }
            }
        }
    }
}
int countBrick(vector<vector<char>> &grid,int rowNum,int colNum,int n){
    int res=0;
    for(int i=0;i<rowNum;++i){
        for(int j=0;j<colNum;++j){
            if(grid[i][j]!='-'){
                ++res;
                bfs(grid,i,j,rowNum,colNum,n);
            }
        }
    }
    return res;
}
int solve(string &str,int rowNum, int colNum,int n){
    vector<vector<char>> grid(rowNum,vector<char>(colNum));
    for(int i=0;i<rowNum;++i){
        for(int j=0;j<colNum;++j){
            grid[i][j]=str[i*colNum+j];
        }
    }
    int res=countBrick(grid,rowNum,colNum,n);
    return res;
}
int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int res=n;
    for(int i=1;i<n;++i){
        if(n%i==0){
            res=min(res,solve(str,i,n/i,n));
        }
    }
    cout<<res<<endl;
    return 0;
}