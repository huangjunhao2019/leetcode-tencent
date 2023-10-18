/*
3
2
buka celi
buka celi
3
dada celi upa
dapa celi upa
3
eleka mosi mita
eleka mosi gusha
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isOk(vector<string> &nums1,vector<string> &nums2){
    int count=0;
    for(int i=0;i<nums1.size();++i){
        if(nums1[i]==nums2[i]){
            ++count;
        } else{
            --count;
        }
        if(count<0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int m;
    int res=0;
    for(int i=0;i<n;++i){
        cin>>m;
        vector<string> vecStr1(m);
        vector<string> vecStr2(m);
        for(int i=0;i<m;++i){
            cin>>vecStr1[i];
        }
        for(int i=0;i<m;++i){
            cin>>vecStr2[i];
        }
        if(isOk(vecStr1,vecStr2)){
            ++res;
        }
    }
    cout<<res<<endl;
    return 0;
}