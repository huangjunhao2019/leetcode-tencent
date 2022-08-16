#include<iostream>
#include<tuple>
#include<string>
#include<vector>
using namespace std;
int main(){
    auto threeInts=std::make_tuple(10,20,30);
    using SomeTuple=std::tuple<std::string,std::vector<std::string>,std::pair<std::string,int>>;
    SomeTuple someTuple{"huang",{"jun","hao"},{"www",1}};
    cout<<get<0>(threeInts)<<" "<<get<1>(threeInts)<<" "<<get<2>(threeInts)<<endl;
    cout<<get<0>(someTuple)<<" ";
    for(auto &temp:get<1>(someTuple)){
        cout<<temp<<" ";
    }
    cout<<get<2>(someTuple).first<<" "<<get<2>(someTuple).second<<endl;
    return 0;
}