#include<iostream>
#include<vector>
using namespace std;
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
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}