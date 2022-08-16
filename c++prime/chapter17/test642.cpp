#include<iostream>
#include<bitset>
using namespace std;
int main(){
    bitset<4> bitVec(12);
    for(int i=0;i<bitVec.size();++i){
        cout<<bitVec[i]<<endl;
    }
    cout<<bitVec<<endl;
    return 0;
}