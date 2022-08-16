#include<iostream>
#include<vector>
#include<random>
using namespace std;
int main(){
    default_random_engine e;
    normal_distribution<> n(4,1.5);
    vector<unsigned> vals(9);
    for(int i=0;i<200;++i){
        unsigned v=lround(n(e));
        if(v<vals.size()){
            ++vals[v];
        }
    }
    for(int i=0;i<vals.size();++i){
        cout<<i<<":"<<string(vals[i],'*')<<endl;
    }
    return 0;
}