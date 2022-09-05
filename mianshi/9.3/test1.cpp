#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
bool dfs(string &flow,vector<vector<char>> &matrix,int row,int col,int len,vector<vector<int>> &visit){
    if(len>=flow.size()){
        return true;
    }
    int m=matrix.size();
    int n=matrix[0].size();
    for(auto &d:dirs){
        int newRow=row+d[0];
        int newCol=col+d[1];
        if(newRow<0 || newRow>=m || newCol<0 || newCol>=n){
            continue;
        }
        if(flow[len]==matrix[newRow][newCol] && visit[newRow][newCol]==0){
            visit[newRow][newCol]=1;
          //  cout<<"new "<<newRow<<" "<<newCol<<endl;
            if(dfs(flow,matrix,newRow,newCol,len+1,visit)){
                return true;
            }
            visit[newRow][newCol]=0;
        }
    }
    return false;
}
bool isOk(string &flow,vector<vector<char>> &matrix,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(matrix[i][j]==flow[0]){
             //   cout<<i<<" "<<j<<endl;
                vector<vector<int>> visit(m,vector<int>(n,0));
                visit[i][j]=1;
                if(dfs(flow,matrix,i,j,1,visit)){
                    return true;
                }
                visit[i][j]=0;
            }
        }
    }
    return false;
}


int main(){
    string s;
    int m;
    int n;
    cin>>s;
    cin>>m;
    cin>>n;
    vector<vector<char>> matrix(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i*n+j<s.size()){
                matrix[i][j]=s[i*n+j];
            }
        }
    }
    vector<string> res;
    string flow;
    while(cin>>flow){
        if(isOk(flow,matrix,m,n)){
            res.push_back(flow); 
        }
    }
    
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}