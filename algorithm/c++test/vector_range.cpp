#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums={1,2,3};
    vector<int> res(nums.begin(),nums.begin()+1);
    for(auto &num:res){
        cout<<num<<endl;
    }
    return 0;
}