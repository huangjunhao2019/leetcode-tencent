/*岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。
你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

输入：grid = [
[0,0,1,0,0,0,0,1,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,1,1,0,1,0,0,0,0,0,0,0,0],
[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0]]
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> direct={{0,1},{0,-1},{1,0},{-1,0}};
int bfs(vector<vector<int>> &grid,vector<vector<int>> &visit,int row,int col){
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>> que;
    que.push({row,col});
    visit[row][col]=1;
    int area=1;
    while(!que.empty()){
        int size=que.size();
        area+=size;
        for(int i=0;i<size;++i){
            auto temp=que.front();
            que.pop();
            for(auto &d:direct){
                int newRow=temp.first+d[0];
                int newCol=temp.second+d[1];
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && visit[newRow][newCol]==0 && 
                    grid[newRow][newCol]==1){
                        visit[newRow][newCol]=1;
                        que.push({newRow,newCol});
                }
            }
            
        }
    }
    return area;
}
int  main(){
    vector<vector<int>> grid={{0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> visit(m,vector<int>(n,0));
    int res=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(visit[i][j]==1 || grid[i][j]==0){
                continue;
            }
            res=max(res,bfs(grid,visit,i,j));
        }
    }
    cout<<res<<endl;
    return 0;
}