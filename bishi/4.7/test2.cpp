#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
/*
7
1 2 3 4 5 3
3 7

4
*/
int solve(vector<vector<int>> &graph,int n,int x,int y){
    int res1=0;
    int res2=0;
    unordered_set<int> visit1;
    queue<int> que1;
    que1.push(x);
    visit1.insert(y);
    visit1.insert(x);
    //x扩展，不包括y
    while(!que1.empty()){
        int size=que1.size();
        ++res1;
        for(int i=0;i<size;++i){
            int temp=que1.front();
            que1.pop();
            for(auto &p:graph[temp]){
                if(visit1.find(p)!=visit1.end()){
                    continue;
                }
                visit1.insert(p);
                que1.push(p);
            }
        }
    }
   // cout<<res1<<endl;
    queue<int> que2;
    que2.push(y);
    while(!que2.empty()){
        int size=que2.size();
        ++res2;
        for(int i=0;i<size;++i){
            int temp=que2.front();
            que2.pop();
            for(auto &p:graph[temp]){
                if(visit1.find(p)!=visit1.end()){
                    continue;
                }
                visit1.insert(p);
                que2.push(p);
            }
        }
    }
    return res1+res2-1;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n-1;++i){
        int temp;
        cin>>temp;
        graph[i+2].push_back(temp);
        graph[temp].push_back(i+2);
    }
    int x,y;
    cin>>x>>y;
    int res=solve(graph,n,x,y);
    cout<<res<<endl;
    return 0;
}