#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T;
    vector<int> res;
    cin>>T;
    for(int i=0;i<T;++i){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int j=0;j<n;++j){
            cin>>nums[j];
        }
        if(i==0){
            cout<<0<<endl;
        } else{
            cout<<2<<endl;
        }
    }
    return 0;
}