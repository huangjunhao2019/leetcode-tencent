#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    string temp;
    getline(cin,temp,',');
    n=stoi(temp);
    vector<int> nums(n,0);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    for(int i=0;i<n;++i){
        cout<<nums[i]<<endl;
    }
    return 0;
}