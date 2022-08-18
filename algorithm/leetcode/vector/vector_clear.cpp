#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums;
    for(int i=0;i<10;++i){
        nums.push_back(i);
    }
    cout<<nums.size()<<endl;
    nums.clear();
    cout<<nums.size()<<endl;
    vector<vector<int>> nums2(10);
    for(int i=0;i<10;++i){
        nums2[i].push_back(i);
    }
    nums2.clear();
    return 0;
}