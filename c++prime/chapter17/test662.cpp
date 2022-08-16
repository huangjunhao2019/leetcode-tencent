#include<iostream>
#include<vector>
#include<random>
using namespace std;
vector<unsigned> badRandVec(){
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0,9);
    vector<unsigned> ret;
    for(int i=0;i<100;++i){
        ret.push_back(u(e));
    }
    return ret;
}
vector<unsigned> goodRandVec(){
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0,9);
    vector<unsigned> ret;
    for(int i=0;i<100;++i){
        ret.push_back(u(e));
    }
    return ret;
}
int main(){
    vector<unsigned> v1(badRandVec());
    vector<unsigned> v2(badRandVec());
    vector<unsigned> v3(goodRandVec());
    vector<unsigned> v4(goodRandVec());
    cout<<((v1==v2)?"equal":"not equal")<<endl;
    cout<<((v3==v4)?"equal":"not equal")<<endl;
    return 0;
}