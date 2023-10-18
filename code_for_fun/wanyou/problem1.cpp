#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=10;
    int count=n;
    vector<int> nums(n,0);
    int index=0;
    while(count!=0){
        int tempCount=0;
        while(true){
            if(count==0){
                break;
            }
            if(nums[index]==0){
                tempCount++;
                if(tempCount==9){
                    nums[index]=1;
                    cout<<index+1<<endl;
                    break;
                }
                index=(index+1)%n;
            } else{
                index=(index+1)%n;
            }
        }
    }
    return 0;
}