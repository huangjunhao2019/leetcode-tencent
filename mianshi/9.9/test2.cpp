#include<iostream>
#include<string>
using namespace std;
void convert_little_to_big(uint *numbers,int count){
    for(int i=0;i<count;i++){
        int x=numbers[i];
        int y;
        char *a=(char*)&y;
        a[0]=x>>24;
        a[1]=x>>16;
        a[2]=x>>8;
        a[3]=x;
        numbers[i]=y;
    } 
}
int main(){
    uint a=0x12345678;
    uint b=0x78563412;
    uint number[]={a,b};
    convert_little_to_big(number,2);
    cout<<hex<<number[0]<<endl<<number[1]<<endl;
    return 0;
}