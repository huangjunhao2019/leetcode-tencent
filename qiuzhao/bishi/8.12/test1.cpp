/*
4
1 4 2 3
2 4
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        mp[temp]=i;
    }
    int val1,val2;
    cin>>val1>>val2;
    if(mp.find(val1)==mp.end() || mp.find(val2)==mp.end()){
        cout<<"No"<<endl;
    } else if(abs(mp[val1]-mp[val2])>1){
        cout<<"No"<<endl;
    } else{
        cout<<"Yes"<<endl;
    }
    return 0;
}