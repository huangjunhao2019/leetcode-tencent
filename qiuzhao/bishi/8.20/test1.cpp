/*
5
10
99
1
40
33

It's too small, please keep guessing!
It's too big, please keep guessing!
Are you kidding me?
It's too big, please keep guessing!
Congratulations! You guessed it right!
*/
#include<iostream>
#include<vector>
using namespace std;
void printSmall(){
    cout<<"It's too small, please keep guessing!"<<endl;
}
void printBig(){
    cout<<"It's too big, please keep guessing!"<<endl;
}
void printKidding(){
    cout<<"Are you kidding me?"<<endl;
}
void printCongratulations(){
    cout<<"Congratulations! You guessed it right!"<<endl;
}
void solve(vector<int> &nums,int n){
    int target=nums[n-1];
    int left=-1;
    int right=-1;
    for(int i=0;i<n;++i){
        if(i==n-1){
            printCongratulations();
        } else{
            if(left!=-1 && right!=-1 && (nums[i]<left || nums[i]>right)){
                printKidding();
            }
            else if(target<nums[i]){
                printBig();
                right=nums[i]-1;
            } else if(target>nums[i]){
                printSmall();
                left=nums[i]+1;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    solve(nums,n);
    return 0;
}