#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    for(int i=0;i<10;++i){
        vec.push_back(i);
    }
    auto cmp=[](const int &a,const int &b){
        return a>b;
    };
    sort(vec.begin(),vec.end(),cmp);
    for(auto &num:vec){
        cout<<num<<endl;
    }
    return 0;
}