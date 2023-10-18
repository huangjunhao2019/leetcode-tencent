/*
6 4 3 //n,m,s
1 4 5 1 4 1

21
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long res=INT_MAX;
long long sum=0;
void backTrack(vector<int> &fruit,int n,int m,int s,int start){
    if(start>=n){
        res=min(res,sum);
        return ;
    }
    for(int i=start;i<start+m;++i){
        int minVal=INT_MAX;
        int maxVal=INT_MIN;
        for(int j=start;j<=i;++j){
            minVal=min(minVal,fruit[j]);
            maxVal=max(maxVal,fruit[j]);
        }
        int temp=(minVal+maxVal)/2;
        long long cost=(i-start+1)*temp+s;
        sum+=cost;
        backTrack(fruit,n,m,s,i+1);
        sum-=cost;
    }
}
int main(){
    int n,m,s;
    cin>>n>>m>>s;
    vector<int> fruit(n);
    for(int i=0;i<n;++i){
        cin>>fruit[i];
    }
    backTrack(fruit,n,m,s,0);
    cout<<res<<endl;
    return 0;
}