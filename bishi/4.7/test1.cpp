#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
3 3 2
01 10 00
10 00 11
01 00 00

8
*/
void change(vector<vector<string>> &newDesk,int n,int m){
    vector<string> temp=newDesk.back();
    for(int i=n-2;i>=0;--i){
        newDesk[i+1]=newDesk[i];
    }
    newDesk[0]=temp;
    for(int i=0;i<n;++i){
        string tempStr=newDesk[i][m-1];
        for(int j=m-2;j>=0;--j){
            newDesk[i][j+1]=newDesk[i][j];
        }
        newDesk[i][0]=tempStr;
    }
}
int main(){
    int n,m,a;
    cin>>n>>m>>a;
    vector<vector<string>> desk(n,vector<string>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>desk[i][j];
        }
    }
    vector<vector<string>> newDesk(desk.begin(),desk.end());
    change(newDesk,n,m);
    int res=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<a;++k){
                if(desk[i][j][k]!=newDesk[i][j][k]){
                    ++res;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}