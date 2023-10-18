#include<iostream>
using namespace std;
bool isOk(int num){
    int len1=num%10;
    int len2=(num/10)%10;
    int len3=num/100;
    if((len1==len2 || len1==len3 || len2==len3) 
    && (len1+len2>len3 &&  len1+len3>len2 && len2+len3>len1)){
        return true;
    }
    return false;
}
int main(){
    int res=0;
    for(int i=100;i<=999;++i){
        if(isOk(i)){
            ++res;
        }
    }
    cout<<res<<endl;
    return 0;
}