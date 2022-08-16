#include<iostream>
#include<vector>
using namespace std;
void solve(int n,int m,int k,string &order){
    vector<vector<int>> grid(n,vector<int>(m,0));
    grid[0][0]=1;
    int count=1;
    int row=0;
    int col=0;
    for(int i=0;i<order.size();++i){
        if(order[i]=='W'){
            --row;
        }
        else if(order[i]=='A'){
            --col;
        }
        else if(order[i]=='S'){
            ++row;
        }
        else if(order[i]=='D'){
            ++col;
        }
        if(grid[row][col]==0){
            ++count;
            grid[row][col]=1;
        }
        if(count==n*m){
            cout<<"Yes"<<endl;
            cout<<i+1;
            return;
        }
    }
    cout<<"No"<<endl;
    cout<<n*m-count;
}
int main(){
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    string order="";
    cin>>order;
    solve(n,m,k,order);
    return 0;
}