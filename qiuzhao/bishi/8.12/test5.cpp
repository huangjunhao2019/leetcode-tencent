/*
3
3 3 12
1 2
2 3
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool isOk(long long a,long long b){
    long long temp=a*b;
   // long long sqrtTemp=sqrt(temp);
    long long left=0;
    long long right=temp;
    while(left<=right){
        long long mid=left+(right-left)/2;
        if(mid*mid==temp){
            return true;
        } else if(mid*mid>temp){
            right=mid-1;
        } else{
            left=mid+1;
        }
    }
    return false;
}
long long solve1(vector<vector<long long>> &grid,vector<long long> &valVec,long long n){
    vector<long long> visit(n,0);
    for(long long i=0;i<n;++i){
        if(visit[i]==1){
            continue;
        }
        for(auto &p:grid[i]){
            if(visit[p]==1){
                continue;
            }
            if(isOk(valVec[i],valVec[p])){
                visit[i]=1;
                visit[p]=1;
            }
        }
    }
    long long res=0;
    for(long long i=0;i<n;++i){
        res+=visit[i];
    }
    return res;
}
long long solve2(vector<vector<long long>> &grid,vector<long long> &valVec,long long n){
    vector<long long> visit(n,0);
    for(long long i=n-1;i>=0;--i){
        if(visit[i]==1){
            continue;
        }
        for(auto &p:grid[i]){
            if(visit[p]==1){
                continue;
            }
            if(isOk(valVec[i],valVec[p])){
                visit[i]=1;
                visit[p]=1;
            }
        }
    }
    long long res=0;
    for(long long i=0;i<n;++i){
        res+=visit[i];
    }
    return res;
}
int main(){
    long long n;
    cin>>n;
    vector<long long> valVec(n);
    for(long long i=0;i<n;++i){
        cin>>valVec[i];
    }
    vector<vector<long long>> grid(n);
    for(long long i=0;i<n-1;++i){
        long long from,to;
        cin>>from>>to;
        grid[from-1].push_back(to-1);
        grid[to-1].push_back(from-1);
    }
    long long res1=solve1(grid,valVec,n);
    long long res2=solve2(grid,valVec,n);
    cout<<max(res1,res2)<<endl;
    return 0;
}