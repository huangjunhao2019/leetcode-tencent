#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void findMax(unordered_map<int,int> &even,int &maxEvenVal,int &maxEvenTime,int &secondEvenVal,int &secondEvenTime){
    for(auto it=even.begin();it!=even.end();it++){
        if(it->second>maxEvenTime){
            secondEvenTime=maxEvenTime;
            secondEvenVal=maxEvenVal;
            maxEvenTime=it->second;
            maxEvenVal=it->first;
        }
        else if(it->second>=secondEvenTime){
            secondEvenTime=it->second;
            secondEvenVal=it->first;
        }
    }
}
int solve(vector<int> &nums,int n){
    unordered_map<int,int> even;
    unordered_map<int,int> odd;
    for(int i=0;i<n;i++){
        if(i%2==0){
            even[nums[i]]++;
        }
        else{
            odd[nums[i]]++;
        }
    }
    int maxEvenVal=0;
    int maxEvenTime=0;
    int secondEvenVal=0;
    int secondEvenTime=0;
    int maxOddVal=0;
    int maxOddTime=0;
    int secondOddVal=0;
    int secondOddTime=0;
    
    findMax(even,maxEvenVal,maxEvenTime,secondEvenVal,secondEvenTime);
    findMax(odd,maxOddVal,maxOddTime,secondOddVal,secondOddTime);
    int res=0;
    //cout<<maxEvenTime<<" "<<maxEvenVal<<" "<<secondEvenTime<<" "<<secondEvenVal<<endl;
    //cout<<maxOddTime<<" "<<maxOddVal<<" "<<secondOddTime<<" "<<secondOddVal<<endl;
    if(maxOddVal==maxEvenVal){
        int temp1=maxOddTime+secondEvenTime;
        int temp2=secondOddTime+maxEvenTime;
      //  cout<<temp1<<" "<<temp2<<endl;
        res=n-max(temp1,temp2);
    }
    else{
        res= n-maxOddTime-maxEvenTime;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    cout<<solve(nums,n)<<endl;
    return 0;
}