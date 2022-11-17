#include<stdio.h>
struct BB{
    char *p;
};
int main(){
    struct BB temp;
    printf("%ld\n",sizeof temp);
    char *p;
    printf("%ld\n",sizeof(p));
    return 0;
    
}