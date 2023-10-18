//小美玩游戏
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findRight(vector<pair<int,int>> &graph,int row,int col){
    int n=graph.size();
    int left=-1;
    int right=n;
    while(left+1<right){
        int mid=left+(right-left)/2;
        if(graph[mid].first>row || graph[mid].second>col){
            right=mid;
        } else{
            left=mid;
        }
    }
    return right;
}
int main(){
    int n;
    int A;
    int B;
    cin>>n>>A>>B;
    vector<pair<int,int>> graph;
    for(int i=0;i<n;++i){
        int row;
        int col;
        cin>>row>>col;
        graph.push_back({row,col});
    }
    auto cmp=[](const pair<int,int> &p1,const pair<int,int> &p2){
        if(p1.first!=p2.first){
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    };
    sort(graph.begin(),graph.end(),cmp);
    int res=0;
    for(int i=0;i<graph.size();++i){
        int rightRow=graph[i].first+A;
        int rightCol=graph[i].second+B;
      
        int rightIndex=findRight(graph,rightRow,rightCol); //寻找右边第一个大于rightRow,rightCol的index
        res=max(res,rightIndex-i);
    }
    cout<<res<<endl;
    return 0;
}