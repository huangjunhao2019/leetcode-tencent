#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<vector<int>> direc={{0,1},{1,0}};
void solve(int n){
    vector<vector<int>> nums(n,vector<int>(n,-1));
    queue<pair<int,int>> que;
    que.push({0,0});
    int odd=1;
    int even=2;
    nums[0][0]=1;
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++){
            auto temp=que.front();
            que.pop();
            int row=temp.first;
            int col=temp.second;
            int tempNum=nums[row][col];
            for(auto &d:direc){
                int newRow=row+d[0];
                int newCol=col+d[1];
                if(newRow>=n || newCol>=n || nums[newRow][newCol]!=-1){
                    continue;
                }
                nums[newRow][newCol]=1-tempNum;
                que.push({newRow,newCol});
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(nums[i][j]==0){
                cout<<even<<" ";
                even+=2;
            }
            else{
                cout<<odd<<" ";
                odd+=2;
            }
        }
        cout<<endl;
    }

}
int main(){
    int n;
    cin>>n;
    solve(n);
    return 0;
}