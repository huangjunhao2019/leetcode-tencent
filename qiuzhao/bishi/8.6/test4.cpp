/*
3
1 2 3
1 2
2 3
*/
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int bfs(vector<vector<int>> &graph,vector<int> &nums){
    int res=0;
    queue<int> que;
    que.push(1);
    int depth=0;
    while(!que.empty()){
        depth++;
        int size=que.size();
        for(int i=0;i<size;++i){
            int start=que.front();
            que.pop();
            res+=nums[start]*depth;
            for(auto &temp:graph[start]){
                que.push(temp);
            }
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>nums[i];
    }
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n-1;++i){
        int from;
        int to;
        cin>>from>>to;
        graph[from].push_back(to);
    }
    int res=INT_MAX;
    for()
    return 0;
}