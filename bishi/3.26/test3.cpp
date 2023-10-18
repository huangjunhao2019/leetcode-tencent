#include<iostream>
#include<vector>
#include<string>
using namespace std;
void changeNums(vector<int> &nums,int left,int right,char op,int x){
    for(int i=left;i<=right;++i){
        if(op=='|'){
            nums[i]|=x;
        } else if(op=='&'){
            nums[i]&=x;
        } else if(op=='='){
            nums[i]=x;
        }
    }
}
void solve(vector<int> &nums,int nSize,int mOp,vector<int> &L,
vector<int> &R,string &op,vector<int> &X){
    for(int i=0;i<mOp;++i){
        changeNums(nums,L[i]-1,R[i]-1,op[i],X[i]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    int m;
    cin>>m;
    vector<int> L(m);
    for(int i=0;i<m;++i){
        cin>>L[i];
    }
    vector<int> R(m);
    for(int i=0;i<m;++i){
        cin>>R[i];
    }
    string op;
    cin>>op;
    vector<int> X(m);
    for(int i=0;i<m;++i){
        cin>>X[i];
    }
    solve(nums,n,m,L,R,op,X);
    for(int i=0;i<n;++i){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
