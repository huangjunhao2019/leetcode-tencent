#include<iostream>
#include<unordered_map>
using namespace std;
int  main(){
    unordered_map<int,int> mp;
    for(int i=0;i<10;i++){
        mp[i]=i;
    }
    for(auto [k,v]:mp){
        cout<<k<<" "<<v<<endl;
    }
    return 0;
}