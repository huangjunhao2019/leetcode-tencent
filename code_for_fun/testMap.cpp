#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int> mp;
    if(mp[0]==0){
        cout<<"hello"<<endl;
    }
    cout<<mp.size()<<endl;
    return 0;
}