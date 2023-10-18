//有N件商品
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
pair<int,int> solve(vector<pair<int,int>> &thing,int n,int x,int y){
    int res=0;
    int oldX=x;
    for(int i=0;i<y;++i){
        if(x>=thing[i].second){
            x-=thing[i].second;
            ++res;
        }
    }
    if(x<=0){
        return {res,oldX-x};
    }
    vector<int> oldPrice(n-y);
    for(int i=y;i<n;++i){
        oldPrice[i-y]=thing[i].first;
    }
    sort(oldPrice.begin(),oldPrice.end());
    for(int i=0;i<oldPrice.size();++i){
        if(x>=oldPrice[i]){
            x-=oldPrice[i];
            ++res;
        }
    }
    return {res,oldX-x};
}
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<pair<int,int>> thing;
    for(int i=0;i<n;++i){
        int a;
        int b;
        cin>>a>>b;
        thing.push_back({a,b});
    }
    auto cmp=[](const pair<int,int> &p1,const pair<int,int> &p2){
        if(p1.second!=p2.second){
            return p1.second<p2.second;
        }
        return p1.first<p2.first;
    };
    sort(thing.begin(),thing.end(),cmp);
    auto res=solve(thing,n,x,y);
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
}