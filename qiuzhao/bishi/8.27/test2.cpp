#include<iostream>
#include<string>
#include<vector>
using namespace std;
void changePointStar(string &s,int index,int n){
    for(int i=0;i<n-index;++i){
        s[i]='.';
        s[5*n-1-i]='.';
    }
}
void changeStarO(string &s,int index,int n){
    for(int i=n;i<4*n;++i){
        s[i]='o';
    }
}
void changeOPoint(string &s,int index,int n){
    for(int i=2*n;i<3*n;++i){
        s[i]='.';
    }
}
void solve(vector<string> &res,int n){
    //*_.
    for(int i=0;i<n;++i){
        changePointStar(res[i],i,n);
    }
    for(int i=4*n;i<5*n;++i){
        res[i]=res[5*n-i-1];
    }
    //*o
    for(int i=n;i<4*n;++i){
        changeStarO(res[i],i,n);
    }
    
    //*o.
    for(int i=2*n;i<3*n;++i){
        changeOPoint(res[i],i,n);
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<string> res(5*n,string(5*n,'*'));
    solve(res,n);
    for(int i=0;i<5*n;++i){
        cout<<res[i]<<endl;
    }
    return 0;
}