#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    string test="huang;jun;hao is a good guy;";
    unordered_set<char> us={';',',',' '};
    string line="";
    stringstream ss(test);
    vector<string> res;
    //string line="";
    for(int i=0;i<test.size();++i){
        if(us.find(test[i])!=us.end()){
            res.push_back(line);
            line="";
            continue;
        }
        line.push_back(test[i]);
    }
    if(line!=""){
        res.push_back(line);
    }
    for(auto &str:res){
        cout<<str<<endl;
    }
    return 0;
}