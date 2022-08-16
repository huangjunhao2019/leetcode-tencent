#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> weight={1,3,4};
    vector<int> value={15,20,30};
    int bagweight=4;
    vector<vector<int>> dp(weight.size(),vector<int> (bagweight+1,0));
    for(int j=0;j<=bagweight;j++){
        if(j>=weight[0]){
            dp[0][j]=max(dp[0][j],dp[0][j-weight[0]]+value[0]);
        }
    }
    for(int i=1;i<weight.size();i++){
        for(int j=0;j<=bagweight;j++){
            if(j<weight[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-weight[i]]+value[i]);
            }
        }
    }
    cout<<dp[weight.size()-1][bagweight]<<endl;
    return 0;
}