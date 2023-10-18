#include<stdio.h>

int main(){
    unsigned int  a=0x12345678;
    char *ch=&a;
    int i;
    int n=sizeof(a);
    for(i=0;i<n/2;i++){
        char temp=ch[i];
        ch[i]=ch[n-1-i];
        ch[n-1-i]=temp;
    }
    printf("%x\n",a);
    return 0;
}