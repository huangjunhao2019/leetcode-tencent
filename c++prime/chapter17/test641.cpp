#include<iostream>
#include<bitset>
using namespace std;
int main(){
    bitset<20> bitvec1(0xbeef);
    for(int i=0;i<bitvec1.size();++i){
        cout<<bitvec1[i]<<endl;
    }
    return 0;
}