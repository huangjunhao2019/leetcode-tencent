#include<iostream>
using namespace std;
bool isOk(int num){
    while(num!=0){
        if(num%10==1){
            return false;
        }
        num/=10;
    }
    return true;
}
int main(){
    int res=0;
    for(int i=0;i<=999999;++i){
        if(isOk(i)){
            ++res;
        }
    }
    cout<<res<<endl;
    return 0;
}