#include<iostream>
#include<vector>
using namespace std;
int res=0;
vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
int solve(vector<vector<int>> &grid,int m,int n){
    vector<vector<pair<int,int>>> path(m,vector<pair<int,int>>(n));
    if(grid[0][0]==1){
        return 
    }
}
int main(){
    int m=2;
    int n=2;
    int count=0;
    vector<vector<int>> grid={{0,0},{0,0}};
    int res=solve(grid,m,n);
    cout<<res<<endl;
    return 0;
}