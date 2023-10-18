#include<bitset>
#include<iostream>
using namespace std;
int main(){
    bitset<10> bitVec;
    bitVec[3]=1;
    for(unsigned int i=0;i<bitVec.size();++i){
        cout<<bitVec[i]<<endl;
    }
    return 0;
}