#include<iostream>
#include<bitset>
using namespace std;
int main(){
    bitset<32> bitVec(32);
    cout<<bitVec<<endl;
    unsigned long ulong=bitVec.to_ulong();
    cout<<"ulong= "<<ulong<<endl;
    return 0;
}