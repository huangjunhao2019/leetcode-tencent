#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
3
0 -1 3
1 0 1
2 0 2
 5

*/
int sumRes=0;
void dfs(vector<vector<int>> &graph,vector<int> &valueVec,int start,int n,int sum){
    sumRes=max(sumRes,sum);
    for(auto &point:graph[start]){
        dfs(graph,valueVec,point,n,sum+valueVec[point]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n);
    vector<int> valueVec(n,0);
    for(int i=0;i<n;++i){
        int num1,num2,num3;
        cin>>num1>>num2>>num3;
        if(num2==-1){
            valueVec[num1]=num3;
        } else{
            valueVec[num1]=num3;
            graph[num2].push_back(num1);
        }
    }
    for(int i=0;i<n;++i){
        if(valueVec[i]<=0){
            continue;
        }
        dfs(graph,valueVec,i,n,valueVec[i]);
    }
    cout<<sumRes<<endl;
    return 0;
}