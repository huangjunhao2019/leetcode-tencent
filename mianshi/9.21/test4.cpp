#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> horse={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
vector<vector<int>> soldier={{0,1},{0,-1},{1,0},{-1,0}};
 
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
    vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
    
}